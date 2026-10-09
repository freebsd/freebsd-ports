PORTNAME=	zen
DISTVERSION=	1.5.0.20261008
PORTEPOCH=	1
CATEGORIES=	www
MASTER_SITES=	LOCAL/dtxdf/${PORTNAME}/:assets
# For instructions on how to create assets:
#   https://github.com/DtxdF/port-assets-makejails/tree/main/zen
DISTFILES=	${PORTNAME}-${DISTVERSIONPREFIX}${DISTVERSION}-${GH_TAGNAME}.frontend${EXTRACT_SUFX}:assets \
		${PORTNAME}-${DISTVERSIONPREFIX}${DISTVERSION}-${GH_TAGNAME}.vendor${EXTRACT_SUFX}:assets

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Lightweight self-hosted notes application
WWW=		https://www.sheshbabu.com/zen/ \
		https://github.com/sheshbabu/zen

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/license.md

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	sheshbabu
GH_TAGNAME=	6c716f7b17c5757ff282917963400ee679e2dfe4

USE_RC_SUBR=	${PORTNAME}

GO_BUILDFLAGS=	-tags fts5

SUB_LIST=	USER=${ZEN_USER}

PLIST_SUB=	GROUP=${ZEN_USER} \
		USER=${ZEN_GROUP}

PLIST_FILES=	bin/${PORTNAME} \
		"@dir(${ZEN_USER},${ZEN_GROUP},) /var/db/${PORTNAME}"

ZEN_USER=	www
ZEN_GROUP=	${ZEN_USER}

post-extract:
	@${MKDIR} ${WRKSRC}/vendor
	@cd ${WRKDIR}/${PORTNAME}-vendor && ${COPYTREE_SHARE} . ${WRKSRC}/vendor
	@${MKDIR} ${WRKSRC}/assets
	@cd ${WRKDIR}/${PORTNAME}-frontend && ${COPYTREE_SHARE} . ${WRKSRC}/assets

post-install:
	@${MKDIR} ${STAGEDIR}/var/db/${PORTNAME}

.include <bsd.port.mk>
