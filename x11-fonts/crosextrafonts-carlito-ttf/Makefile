PORTNAME=	crosextrafonts-carlito
PORTVERSION=	20130920
PORTREVISION=	4
CATEGORIES=	x11-fonts
MASTER_SITES=	https://gsdview.appspot.com/chromeos-localmirror/distfiles/ \
		https://commondatastorage.googleapis.com/chromeos-localmirror/distfiles

MAINTAINER=	office@FreeBSD.org
COMMENT=	Font created by Google for ChromeOS to replace MS Calibri

LICENSE=	OFL11

USES=		fonts xorg
USE_XORG=	x11

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

FONTNAME=	Carlito

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
