PORTNAME=	evcc
DISTVERSION=	0.310.1
CATEGORIES=	www
MASTER_SITES=	LOCAL/mfechner/${PORTNAME}/:npmcache
DISTFILES=	${PORTNAME}-npm-cache-${DISTVERSION}${EXTRACT_SUFX}:npmcache

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Extensible EV Charge Controller
WWW=		https://evcc.io/ \
		https://github.com/evcc-io/evcc

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	Npm cache only for amd64 generated

BUILD_DEPENDS=	npm>0:www/npm

USES=		gmake go:1.26+,modules,no_targets nodejs:lts,build tar:zstd

# Find here: https://github.com/evcc-io/evcc/releases
_SHA=		659328092ff158c634f79b0a2b1e11f08223c1ae

USE_GITHUB=	yes
GH_ACCOUNT=	evcc-io
USE_RC_SUBR=	${PORTNAME}
GO_MOD_DIST=	github
GO_MODULE=	github.com/evcc-io/evccmain

MAKE_ENV=	npm_config_offline=true TAG_NAME=${DISTVERSION} SHA=${_SHA}

# parallel build failed in my tests, so disable it here
MAKE_JOBS_UNSAFE=yes
ALL_TARGET=	default

USERS=		evcc
GROUPS=		evcc

PLIST_FILES=	bin/${PORTNAME}

pre-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} npm ci --legacy-peer-deps
	#cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} npm run build

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/evcc ${STAGEDIR}${PREFIX}/bin

# (for maintainer) helper target to generate node_modules tarball
make-npm-cache: patch
	@cd ${WRKDIR} && ${RM} -r .npm
	@cd ${WRKSRC} && ${SETENV} HOME=${WRKDIR} npm ci --legacy-peer-deps
	@cd ${WRKDIR} \
		&& ${TAR} -c --zstd -f ${PORTNAME}-npm-cache-${DISTVERSION}${EXTRACT_SUFX} .npm \
		&& ${ECHO} "Please upload the file: scp ${WRKDIR}/${PORTNAME}-npm-cache-${DISTVERSION}${EXTRACT_SUFX} mfechner@freefall.freebsd.org:public_distfiles/${PORTNAME}/"

.include <bsd.port.mk>
