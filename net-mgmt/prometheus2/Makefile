PORTNAME=	prometheus
DISTVERSIONPREFIX=	v
DISTVERSION=	2.55.1
PORTREVISION=	6
CATEGORIES=	net-mgmt
MASTER_SITES=	https://raw.githubusercontent.com/${GH_ACCOUNT}/${GH_PROJECT}/${DISTVERSIONFULL}/:gomod \
		https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/releases/download/${DISTVERSIONFULL}/:ui
DISTFILES=	go.mod:gomod ${PORTNAME}-web-ui-${DISTVERSION}.tar.gz:ui

MAINTAINER=	dor.bsd@xm0.uk
COMMENT=	Systems monitoring and alerting toolkit
WWW=		https://prometheus.io/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

PATCH_DEPENDS=	bash:shells/bash

USES=		cpe gmake go:1.23,modules

CONFLICTS_INSTALL=	prometheus[13]

USE_GITHUB=	yes
USE_RC_SUBR=	prometheus

GO_MODULE=	github.com/prometheus/prometheus
GO_TARGET=	./cmd/prometheus ./cmd/promtool
GO_BUILDFLAGS=	-a -v -ldflags "${LD_FLAG_STRING}" -tags netgo,builtinassets

SUB_LIST+=	PROMETHEUS_CONSOLE_LIBRARIES_DIR=${PROMETHEUS_CONSOLE_LIBRARIES_DIR} \
		PROMETHEUS_CONSOLES_DIR=${PROMETHEUS_CONSOLES_DIR} \
		PROMETHEUS_DB_DIR=${PROMETHEUS_DB_DIR} \
		PROMETHEUS_GROUP=${PROMETHEUS_GROUP} \
		PROMETHEUS_USER=${PROMETHEUS_USER}

USERS=		${PROMETHEUS_USER}
GROUPS=		${PROMETHEUS_GROUP}

PLIST_SUB+=	PROMETHEUS_CONSOLE_LIBRARIES_DIR=${PROMETHEUS_CONSOLE_LIBRARIES_DIR} \
		PROMETHEUS_CONSOLES_DIR=${PROMETHEUS_CONSOLES_DIR} \
		PROMETHEUS_GROUP=${PROMETHEUS_GROUP} \
		PROMETHEUS_USER=${PROMETHEUS_USER}

OPTIONS_DEFINE=	DOCS

BUILD_USER?=		${USER}
LD_FLAG_STRING=		-s ${LD_FLAG_X_PREFIX}.Version=${PORTVERSION} \
			${LD_FLAG_X_PREFIX}.Revision=${PORTREVISION} \
			${LD_FLAG_X_PREFIX}.Branch=release-${PORTVERSION:R} \
			${LD_FLAG_X_PREFIX}.BuildUser=${BUILD_USER} \
			${LD_FLAG_X_PREFIX}.BuildDate=${SOURCE_DATE_EPOCH:U${SOURCE_DATE_EPOCH_CMD:sh}}
LD_FLAG_X_PREFIX=	-X github.com/prometheus/common/version

PROMETHEUS_CONSOLES_DIR?=		${DATADIR}/consoles
PROMETHEUS_CONSOLE_LIBRARIES_DIR?=	${DATADIR}/console_libraries
PROMETHEUS_DB_DIR?=			/var/db/${PORTNAME}
PROMETHEUS_GROUP?=			prometheus
PROMETHEUS_USER?=			prometheus

# Bring DISTINFO_FILE into scope so we can get the timestamp.
.include <bsd.port.pre.mk>

SOURCE_DATE_EPOCH_CMD=	date -ur $$(${GREP} TIMESTAMP ${DISTINFO_FILE} | ${SED} -e 's/[^0-9]//g') \
			'+%Y%m%d-%T'

post-patch:
	@${RM} -rf ${WRKSRC}/web/ui/static
	# A symlink isn't good enough here, copy the entire static directory over
	@${CP} -a ${WRKDIR}/static ${WRKSRC}/web/ui/static
	@( cd ${WRKSRC} && ${WRKSRC}/scripts/compress_assets.sh )

post-install:
	${MKDIR} ${STAGEDIR}${DESTDIR}${PROMETHEUS_CONSOLES_DIR}
	${MKDIR} ${STAGEDIR}${DESTDIR}${PROMETHEUS_CONSOLE_LIBRARIES_DIR}
	${INSTALL_DATA} \
		${WRKSRC}/documentation/examples/prometheus.yml \
		${STAGEDIR}${LOCALBASE}/etc/prometheus.yml.sample
	( cd ${WRKSRC}/console_libraries \
		&& ${COPYTREE_SHARE} . ${STAGEDIR}${PROMETHEUS_CONSOLE_LIBRARIES_DIR} )
	( cd ${WRKSRC}/consoles \
		&& ${COPYTREE_SHARE} . ${STAGEDIR}${PROMETHEUS_CONSOLES_DIR} )

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@( cd ${WRKSRC}/docs \
		&& ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} )

.include <bsd.port.post.mk>
