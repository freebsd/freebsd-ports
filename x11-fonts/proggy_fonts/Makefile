# Created by: Leland Wang <llwang@infor.org>
# $FreeBSD$

PORTNAME=	proggy_fonts
PORTVERSION=	1.0
PORTREVISION=	5
CATEGORIES=	x11-fonts
MASTER_SITES=	http://upperbounds.net/download/
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

ALREADY_UNZIP=	${DISTDIR}/Opti.pcf.gz ${DISTDIR}/OptiSmall.pcf.gz \
	        ${DISTDIR}/PixelCarnageMono.pcf.gz

USE_XORG=	x11
USES=		fonts zip
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${CP} ${ALREADY_UNZIP} ${WRKSRC}
	${INSTALL_DATA} ${WRKSRC}/*.pcf* ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
