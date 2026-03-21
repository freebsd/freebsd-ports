PORTNAME=	gatus
DISTVERSIONPREFIX=	v
DISTVERSION=	5.35.0
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	LOCAL/dtxdf/${PORTNAME}/
# For instructions on how to create assets:
#   https://github.com/DtxdF/port-assets-makejails/tree/main/gatus
DISTFILES=	${PORTNAME}-${DISTVERSIONPREFIX}${DISTVERSION}.vendor${EXTRACT_SUFX}

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Automated developer-oriented status page
WWW=		https://gatus.io

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64
ONLY_FOR_ARCHS_REASON=	module modernc.org/sqlite only supported on aarch64 and amd64

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	TwiN

USE_RC_SUBR=	${PORTNAME}

SUB_LIST=	USER=${GATUS_USER}

PLIST_FILES=	bin/${PORTNAME} \
		"@sample etc/${PORTNAME}.yaml.sample"

GATUS_USER=	www

post-extract:
	@${MKDIR} ${WRKSRC}/vendor
	@cd ${WRKDIR}/${PORTNAME}-vendor && ${COPYTREE_SHARE} . ${WRKSRC}/vendor

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc
	${INSTALL_DATA} ${WRKSRC}/config.yaml ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.yaml.sample

.include <bsd.port.mk>
