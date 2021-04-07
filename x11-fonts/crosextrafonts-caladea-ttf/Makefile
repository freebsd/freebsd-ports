PORTNAME=	crosextrafonts
PORTVERSION=	20130214
PORTREVISION=	4
CATEGORIES=	x11-fonts
MASTER_SITES=	https://gsdview.appspot.com/chromeos-localmirror/distfiles/ \
		https://commondatastorage.googleapis.com/chromeos-localmirror/distfiles
PKGNAMESUFFIX=	-caladea

MAINTAINER=	office@FreeBSD.org
COMMENT=	Font created by Google for ChromeOS to replace MS Cambria

LICENSE=	APACHE20

USES=		fonts xorg
USE_XORG=	x11

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

FONTNAME=	Caladea

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
