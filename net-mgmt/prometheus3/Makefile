PORTNAME=	prometheus
DISTVERSIONPREFIX=	v
DISTVERSION=	3.4.2
CATEGORIES=	net-mgmt
MASTER_SITES=	https://raw.githubusercontent.com/${GH_ACCOUNT}/${GH_PROJECT}/${DISTVERSIONFULL}/:gomod \
		https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/releases/download/${DISTVERSIONFULL}/:ui
PKGNAMESUFFIX=	3
DISTFILES=	go.mod:gomod \
		${PORTNAME}-web-ui-${DISTVERSION}.tar.gz:ui

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Systems monitoring and alerting toolkit
WWW=		https://prometheus.io/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

PATCH_DEPENDS=	bash:shells/bash

USES=		cpe go:modules

USE_GITHUB=	yes
USE_RC_SUBR=	prometheus

GO_MODULE=	github.com/prometheus/prometheus
GO_TARGET=	./cmd/prometheus ./cmd/promtool
GO_BUILDFLAGS=	-a -ldflags "${LD_FLAG_STRING}" -tags netgo,builtinassets

CONFLICTS_INSTALL=	prometheus1 prometheus

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
			${LD_FLAG_X_PREFIX}.BuildDate=$$(date +'%Y%m%d-%H:%M:%S')
LD_FLAG_X_PREFIX=	-X github.com/prometheus/common/version

PROMETHEUS_CONSOLES_DIR?=		${DATADIR}/consoles
PROMETHEUS_CONSOLE_LIBRARIES_DIR?=	${DATADIR}/console_libraries
PROMETHEUS_DB_DIR?=			/var/db/${PORTNAME}
PROMETHEUS_GROUP?=			prometheus
PROMETHEUS_USER?=			prometheus

.include <bsd.port.pre.mk>

post-patch:
	@${RM} -rf ${WRKSRC}/web/ui/static
	@${CP} -a ${WRKDIR}/static ${WRKSRC}/web/ui/static
	@( cd ${WRKSRC} && ${WRKSRC}/scripts/compress_assets.sh )

post-install:
	${MKDIR} ${STAGEDIR}${DESTDIR}${PROMETHEUS_CONSOLES_DIR}
	${MKDIR} ${STAGEDIR}${DESTDIR}${PROMETHEUS_CONSOLE_LIBRARIES_DIR}
	${INSTALL_DATA} \
		${WRKSRC}/documentation/examples/prometheus.yml \
		${STAGEDIR}${LOCALBASE}/etc/prometheus.yml.sample

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@( cd ${WRKSRC}/docs \
		&& ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} )

.include <bsd.port.post.mk>
