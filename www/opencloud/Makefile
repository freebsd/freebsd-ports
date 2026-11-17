PORTNAME=	opencloud
DISTVERSIONPREFIX=	v
DISTVERSION=	9.2.0
CATEGORIES=	www
MASTER_SITES=	https://github.com/opencloud-eu/web/releases/download/${WEB_ASSETS_VERSION}/:web \
		https://github.com/jostreff/opencloud-idp-assets/releases/download/v${DISTVERSION}/:idp
DISTFILES=	web.tar.gz:web \
		${PORTNAME}-idp-assets-${DISTVERSION}.tar.gz:idp
DIST_SUBDIR=	${PORTNAME}/${DISTVERSION}
EXTRACT_ONLY=	${GH_ACCOUNT}-${GH_PROJECT}-${DISTVERSIONFULL}_GH0${EXTRACT_SUFX}

MAINTAINER=	jordan@ostreff.info
COMMENT=	Open source file sync, sharing and collaboration platform
WWW=		https://opencloud.eu/

LICENSE=	AGPLv3 APACHE20
LICENSE_COMB=	multi
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE

USES=		go:1.26+,modules

USE_GITHUB=	yes
GH_ACCOUNT=	opencloud-eu

USE_RC_SUBR=	${PORTNAME}

GO_TARGET=	./opencloud/cmd/${PORTNAME}:${PORTNAME}
GO_BUILDFLAGS=	-tags disable_crypt -ldflags '${OC_LDFLAGS}'
CGO_ENABLED=	0

SUB_FILES=	pkg-message
SUB_LIST=	OC_DBDIR=${OC_DBDIR} \
		OC_USER=${USERS}

USERS=		${PORTNAME}
GROUPS=		${PORTNAME}

PLIST_SUB=	OC_DBDIR=${OC_DBDIR}

OPTIONS_DEFINE=	CLI DOCS
OPTIONS_SUB=	yes

CLI_DESC=	Install opencloud-cli, a wrapper to run commands as the service user
CLI_SUB_FILES=	opencloud-cli

WEB_ASSETS_VERSION=	v8.3.0

OC_PKG=		github.com/opencloud-eu/opencloud
OC_DBDIR=	/var/db/${PORTNAME}
OC_EDITION?=	rolling

OC_LDFLAGS=	-s -w -X \
		google.golang.org/protobuf/reflect/protoregistry.conflictPolicy=warn \
		-X ${OC_PKG}/pkg/version.Tag=${DISTVERSION} -X \
		${OC_PKG}/pkg/version.Edition=${OC_EDITION} -X \
		${OC_PKG}/pkg/config/defaults.BaseDataPathType=path -X \
		${OC_PKG}/pkg/config/defaults.BaseDataPathValue=${OC_DBDIR} -X \
		${OC_PKG}/pkg/config/defaults.BaseConfigPathType=path -X \
		${OC_PKG}/pkg/config/defaults.BaseConfigPathValue=${ETCDIR}

post-extract:
	@${TAR} -xzf ${DISTDIR}/${DIST_SUBDIR}/web.tar.gz -C ${WRKSRC}/services/web/assets/core
	@${TAR} -xzf ${DISTDIR}/${DIST_SUBDIR}/${PORTNAME}-idp-assets-${DISTVERSION}.tar.gz \
		-C ${WRKSRC}/services/idp

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${MKDIR} ${STAGEDIR}${OC_DBDIR}
	${INSTALL_DATA} ${FILESDIR}/${PORTNAME}.env.sample \
		${STAGEDIR}${ETCDIR}/${PORTNAME}.env.sample
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d
	${INSTALL_DATA} ${FILESDIR}/newsyslog.conf.sample \
		${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d/${PORTNAME}.conf.sample

post-install-CLI-on:
	${INSTALL_SCRIPT} ${WRKDIR}/opencloud-cli ${STAGEDIR}${PREFIX}/sbin/

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${FILESDIR}/README.FreeBSD ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
