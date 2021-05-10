PORTNAME=	oldschool-pc-fonts
DISTVERSION=	2.2
PORTREVISION=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	https://int10h.org/${PORTNAME}/download/
DISTNAME=	oldschool_pc_font_pack_v${DISTVERSION}_linux

MAINTAINER=	evgeniy@khramtsov.org
COMMENT=	Ultimate Oldschool PC Font Pack

LICENSE=	CC-BY-SA-4.0
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT

USES=		fonts zip
NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

OPTIONS_DEFAULT=	AC BM MX PX
OPTIONS_MULTI=		SET
OPTIONS_MULTI_SET=	AC BM MX PX
OPTIONS_SUB=		yes

AC_DESC=	Aspect-corrected fonts
BM_DESC=	Bitmap fonts
MX_DESC=	Mixed outline+bitmap fonts
PX_DESC=	Pixel outline fonts
SET_DESC=	Font sets

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
do-install-AC-on:
	${INSTALL_DATA} ${WRKSRC}/*Ac*/*.ttf ${STAGEDIR}${FONTSDIR}
do-install-BM-on:
	${INSTALL_DATA} ${WRKSRC}/*Bm*/*.otb ${STAGEDIR}${FONTSDIR}
do-install-MX-on:
	${INSTALL_DATA} ${WRKSRC}/*Mx*/*.ttf ${STAGEDIR}${FONTSDIR}
do-install-PX-on:
	${INSTALL_DATA} ${WRKSRC}/*Px*/*.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
