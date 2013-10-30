# Created by: Ilya A. Arkhipov <rum1cro@yandex.ru>
# $FreeBSD$

PORTNAME=	Inconsolata-LGC
PORTVERSION=	20131024
CATEGORIES=	x11-fonts

MAINTAINER=	rum1cro@yandex.ru
COMMENT=	Monospaced TrueType font with Cyrillic glyphs

LICENSE=	OFL11

USE_GITHUB=	yes
GH_ACCOUNT=	DeLaGuardo
GH_COMMIT=	16e2c94
GH_TAGNAME=	${GH_COMMIT}

USE_XORG=	x11
INSTALLS_TTF=	yes
NO_BUILD=	yes
FONTDIR=	TTF

PLIST_FILES=	lib/X11/fonts/${FONTDIR}/inconsolatalgc.ttf \
		lib/X11/fonts/${FONTDIR}/inconsolatalgcbold.ttf \
		lib/X11/fonts/${FONTDIR}/inconsolatalgcbolditalic.ttf \
		lib/X11/fonts/${FONTDIR}/inconsolatalgcitalic.ttf
PLIST_DIRSTRY=	lib/X11/fonts/${FONTDIR}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/X11/fonts/${FONTDIR}
	${INSTALL_DATA} ${WRKSRC}/inconsolatalgc.ttf \
		${STAGEDIR}${PREFIX}/lib/X11/fonts/${FONTDIR}
	${INSTALL_DATA} ${WRKSRC}/inconsolatalgcbold.ttf \
		${STAGEDIR}${PREFIX}/lib/X11/fonts/${FONTDIR}
	${INSTALL_DATA} ${WRKSRC}/inconsolatalgcbolditalic.ttf \
		${STAGEDIR}${PREFIX}/lib/X11/fonts/${FONTDIR}
	${INSTALL_DATA} ${WRKSRC}/inconsolatalgcitalic.ttf \
		${STAGEDIR}${PREFIX}/lib/X11/fonts/${FONTDIR}

.include <bsd.port.mk>
