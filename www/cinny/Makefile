PORTNAME=	cinny
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.0
CATEGORIES=	www
MASTER_SITES=	https://github.com/ajbura/${PORTNAME}/releases/download/v${PORTVERSION}/

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Yet another Matrix client for the web

LICENSE=	MIT

NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	pkg-message
WRKSRC=		${WRKDIR}/dist

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
