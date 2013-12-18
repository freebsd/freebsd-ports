# Created by: Leland Wang <llwang@infor.org>
# $FreeBSD$

PORTNAME=	proggy_fonts
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	x11-fonts
MASTER_SITES=	http://www.proggyfonts.com/download/
DISTFILES=	ProggyClean.pcf.zip ProggySquare.pcf.zip \
		ProggySmall.pcf.zip ProggyTiny.pcf.zip	\
		ProggyCleanSZ.pcf.zip ProggySquareSZ.pcf.zip \
		ProggyTinySZ.pcf.zip ProggyCleanSZBP.pcf.zip \
		ProggyCleanCP.pcf.zip CodingFontTobi.pcf.zip \
		Opti.pcf.gz OptiSmall.pcf.gz SpeedyPCF.zip \
		PixelCarnageMono.pcf.gz WebbySmall.pcf.zip \
		WebbyCaps.pcf.zip
EXTRACT_ONLY=	ProggyClean.pcf.zip ProggySquare.pcf.zip \
		ProggySmall.pcf.zip ProggyTiny.pcf.zip	\
		ProggyCleanSZ.pcf.zip ProggySquareSZ.pcf.zip \
		ProggyTinySZ.pcf.zip ProggyCleanSZBP.pcf.zip \
		ProggyCleanCP.pcf.zip CodingFontTobi.pcf.zip \
		SpeedyPCF.zip WebbySmall.pcf.zip \
		WebbyCaps.pcf.zip

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The perfect monospaced bitmap programming fonts

RUN_DEPENDS=	mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale

ALREADY_UNZIP=	${DISTDIR}/Opti.pcf.gz ${DISTDIR}/OptiSmall.pcf.gz \
	        ${DISTDIR}/PixelCarnageMono.pcf.gz

USE_XORG=	x11
USE_ZIP=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
XFONTDIR=	${PREFIX}/lib/X11/fonts/local

NO_STAGE=	yes
do-install:
	@${MKDIR} ${XFONTDIR}
	@${CP} ${ALREADY_UNZIP} ${WRKDIR}
	@${INSTALL_DATA} ${WRKDIR}/*.pcf* ${XFONTDIR}
	@(cd ${XFONTDIR}; mkfontdir)

.include <bsd.port.mk>
