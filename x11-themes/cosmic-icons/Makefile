PORTNAME=	cosmic-icons
PORTVERSION=	1.8.0
DISTVERSIONPREFIX=	epoch-
CATEGORIES=	x11-themes

MAINTAINER=	jo.sh@tutanota.com
COMMENT=	Icon theme for the COSMIC desktop environment
WWW=		https://github.com/pop-os/cosmic-icons

LICENSE=	CC-BY-SA-4.0
LICENSE_FILE=	${WRKSRC}/LICENSE

NO_ARCH=	yes
NO_BUILD=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	pop-os

DATADIR=	${PREFIX}/share/icons/Cosmic
PORTDATA=	*

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/extra && \
		${COPYTREE_SHARE} scalable ${STAGEDIR}${DATADIR})
	(cd ${WRKSRC}/freedesktop && \
		${COPYTREE_SHARE} scalable ${STAGEDIR}${DATADIR})

	${INSTALL_DATA} ${WRKSRC}/index.theme ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
