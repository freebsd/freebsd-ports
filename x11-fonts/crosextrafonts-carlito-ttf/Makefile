# $FreeBSD$

PORTNAME=	crosextrafonts-carlito
PORTVERSION=	20130920
PORTREVISION=	3
CATEGORIES=	x11-fonts
MASTER_SITES=	http://gsdview.appspot.com/chromeos-localmirror/distfiles/

MAINTAINER=	office@FreeBSD.org
COMMENT=	Font created by Google for ChromeOS to replace MS Calibri

LICENSE=	OFL11

USES=		fonts
USE_XORG=	x11

SUB_FILES=	pkg-message

FONTNAME=	Carlito
NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${WRKSRC} &&	\
	${INSTALL_DATA} ${INSTDAT} *.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
