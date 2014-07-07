# $FreeBSD$

PORTNAME=	proggy_fonts-ttf
PORTVERSION=	1.0
CATEGORIES=	x11-fonts
MASTER_SITES=	http://www.proggyfonts.com/download/
DISTFILES=	ProggyClean.ttf.zip ProggySquare.ttf.zip \
		ProggySmall.ttf.zip ProggyTiny.ttf.zip	\
		ProggyCleanSZ.ttf.zip ProggySquareSZ.ttf.zip \
		ProggyTinySZ.ttf.zip ProggyCleanSZBP.ttf.zip
DIST_SUBDIR=	proggy_fonts-ttf

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The perfect monospaced bitmap programming fonts, TTF version

LICENSE=	MIT

BUILD_DEPENDS=	mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale \
		fc-cache:${PORTSDIR}/x11-fonts/fontconfig

USES=		zip
NO_WRKSUBDIR=	yes
FONTDIR=	${PREFIX}/lib/X11/fonts/${PORTNAME}
NO_BUILD=	yes
PLIST_SUB=	FONTDIR="${FONTDIR:S|${PREFIX}/||}"

do-install:
	@${MKDIR} ${STAGEDIR}${FONTDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} *.ttf ${STAGEDIR}${FONTDIR}

.include <bsd.port.mk>
