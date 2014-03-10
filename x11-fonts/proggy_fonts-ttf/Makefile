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

MAINTAINER=	rakuco@FreeBSD.org
COMMENT=	The perfect monospaced bitmap programming fonts, TTF version

LICENSE=	MIT

BUILD_DEPENDS=	mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale

USES=		zip
NO_WRKSUBDIR=	yes
INSTALLDIR=	${PREFIX}/lib/X11/fonts/${PORTNAME}

NO_STAGE=	yes
do-build:
	@cd ${WRKSRC} && ${LOCALBASE}/bin/mkfontscale
	@cd ${WRKSRC} && ${LOCALBASE}/bin/mkfontdir

do-install:
	@${MKDIR} ${INSTALLDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} fonts.dir fonts.scale *.ttf ${INSTALLDIR}

.include <bsd.port.mk>
