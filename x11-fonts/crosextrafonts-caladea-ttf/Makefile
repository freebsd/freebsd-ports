# $FreeBSD$

PORTNAME=	crosextrafonts
PORTVERSION=	20130214
PORTREVISION=	2
CATEGORIES=	x11-fonts
MASTER_SITES=	http://gsdview.appspot.com/chromeos-localmirror/distfiles/
PKGNAMESUFFIX=	-caladea

MAINTAINER=	office@FreeBSD.org
COMMENT=	Font created by Google for ChromeOS to replace MS Cambria

LICENSE=	APACHE20

USES=		fonts
USE_XORG=	x11

SUB_FILES=	pkg-message
NO_BUILD=	yes

FONTNAME=	Caladea

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} *.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
