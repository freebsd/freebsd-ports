PORTNAME=	chronograf
DISTVERSIONPREFIX=	v
DISTVERSION=	1.9.4
CATEGORIES=	net-mgmt
MASTER_SITES+=	https://nodejs.org/download/release/v${NODEJS_VERSION}/:node
DISTFILES=	yarn-cache-${PKGNAME}.tar.xz:prefetch \
		node-v${NODEJS_VERSION}-headers.tar.gz:node
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Open source monitoring and visualization UI for the TICK stack

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

FETCH_DEPENDS=	ca_root_nss>0:security/ca_root_nss \
		yarn:www/yarn-node${NODEJS_VERSION_MAJOR}
BUILD_DEPENDS=	go-bindata:devel/go-bindata \
		yarn:www/yarn-node${NODEJS_VERSION_MAJOR}

USES=		gmake go:modules python:build

EXTRACT_ONLY:=	${DISTFILES:C/:[^:]+$//}

GO_MODULE=	github.com/influxdata/${PORTNAME}
GO_TARGET=	./cmd/chronograf/main.go:chronograf \
		./cmd/chronoctl:chronoctl
GO_BUILDFLAGS=	-ldflags "-X main.version=${DISTVERSION}"

NODEJS_VERSION_MAJOR=	14
#NODEJS_VERSION!=	make -V DISTVERSION -f ${PORTSDIR}/www/node${NODEJS_VERSION_MAJOR}/Makefile
NODEJS_VERSION=	14.18.1

USE_RC_SUBR=	chronograf

SUB_FILES=	chronograf
SUB_LIST=	CHRONOGRAF_USER=${CHRONOGRAF_USER} \
		CHRONOGRAF_GROUP=${CHRONOGRAF_GROUP} \
		CHRONOGRAF_DBDIR=${CHRONOGRAF_DBDIR} \
		CHRONOGRAF_LOGDIR=${CHRONOGRAF_LOGDIR}
PLIST_SUB=	CHRONOGRAF_USER=${CHRONOGRAF_USER} \
		CHRONOGRAF_GROUP=${CHRONOGRAF_GROUP} \
		CHRONOGRAF_DBDIR=${CHRONOGRAF_DBDIR} \
		CHRONOGRAF_LOGDIR=${CHRONOGRAF_LOGDIR}

# Use influxd user as it's aleary present in the ports system
CHRONOGRAF_USER=	influxd
CHRONOGRAF_GROUP=	influxd

USERS?=		${CHRONOGRAF_USER}
GROUPS?=		${CHRONOGRAF_GROUP}

CHRONOGRAF_DBDIR?=	/var/db/${PORTNAME}
CHRONOGRAF_LOGDIR?=	/var/log/${PORTNAME}

YARN_ENV=	HOME=${WRKDIR} XDG_CACHE_HOME=${WRKDIR}/.cache
YARN_CACHE_FILE=	yarn-cache-${PKGNAME}.tar.xz

PLIST_FILES=	bin/chronoctl \
		bin/chronograf

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DIST_SUBDIR}/${YARN_CACHE_FILE})
pre-fetch:
	${MKDIR} ${DISTDIR}/${DIST_SUBDIR}
	${MKDIR} ${WRKDIR}
	${ECHO_CMD} 'yarn-offline-mirror "./yarn-offline-cache"' >> ${WRKDIR}/.yarnrc
	${CP} ${FILESDIR}/yarn/package.json ${FILESDIR}/yarn/yarn.lock ${WRKDIR}
	${MKDIR} ${WRKDIR}/ui
	${CP} ${FILESDIR}/yarn/ui/package.json ${WRKDIR}/ui
	cd ${WRKDIR} && ${SETENV} ${YARN_ENV} yarn --frozen-lockfile --ignore-scripts
	cd ${WRKDIR}/ui && ${SETENV} ${YARN_ENV} yarn --frozen-lockfile --ignore-scripts
	cd ${WRKDIR} && ${MTREE_CMD} -cbnSp yarn-offline-cache | ${MTREE_CMD} -C | ${SED} \
		-e 's:time=[0-9.]*:time=0.000000000:' \
		-e 's:\([gu]id\)=[0-9]*:\1=0:g' \
		-e 's:flags=.*:flags=none:' \
		-e 's:^\.:./yarn-offline-cache:' > yarn-offline-cache.mtree
	cd ${WRKDIR} && ${TAR} cJf ${DISTDIR}/${DIST_SUBDIR}/${YARN_CACHE_FILE} \
		@yarn-offline-cache.mtree
	${RM} -r ${WRKDIR}
.endif

pre-build:
	${ECHO_CMD} "yarn-offline-mirror \"${WRKDIR}/yarn-offline-cache\"" >> ${WRKDIR}/.yarnrc
	cd ${WRKDIR} && ${SETENV} ${YARN_ENV} \
		yarn install --frozen-lockfile --offline
	cd ${WRKSRC}/ui && ${SETENV} ${YARN_ENV} \
		PYTHON=${PYTHON_CMD} \
		npm_config_tarball=${DISTDIR}/${DIST_SUBDIR}/node-v${NODEJS_VERSION}-headers.tar.gz \
		yarn --frozen-lockfile --offline --no-progress --no-emoji
	cd ${WRKSRC}/ui && ${SETENV} ${YARN_ENV} yarn run build
	cd ${WRKSRC} && ${GMAKE} .bindata

.include <bsd.port.post.mk>
