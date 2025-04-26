PORTNAME=	vazirmatn
DISTVERSIONPREFIX=	v
DISTVERSION=	33.003
CATEGORIES=	x11-fonts

MAINTAINER=	armean.shirazi@gmail.com
COMMENT=	Simple Persian/Arabic font
WWW=		https://rastikerdar.github.io/vazirmatn/

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/OFL.txt

USES=	fonts
USE_GITHUB=	YES
GH_ACCOUNT=	rastikerdar

NO_ARCH=	YES
NO_BUILD=	YES

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/fonts/ttf/*.ttf ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/Round-Dots/fonts/ttf/*.ttf ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/Round-Dots/misc/Farsi-Digits/fonts/ttf/*.ttf ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/Round-Dots/misc/Farsi-Digits-Non-Latin/fonts/ttf/*.ttf ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/Round-Dots/misc/Non-Latin/fonts/ttf/*.ttf ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/Round-Dots/misc/UI/fonts/ttf/*.ttf ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/Round-Dots/misc/UI-Farsi-Digits/fonts/ttf/*.ttf ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/Round-Dots/misc/UI-Farsi-Digits-Non-Latin/fonts/ttf/*.ttf ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/Round-Dots/misc/UI-Non-Latin/fonts/ttf/*.ttf ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/misc/Farsi-Digits/fonts/ttf/*.ttf ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/misc/Farsi-Digits-Non-Latin/fonts/ttf/*.ttf ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/misc/Non-Latin/fonts/ttf/*.ttf ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/misc/UI/fonts/ttf/*.ttf ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/misc/UI-Farsi-Digits/fonts/ttf/*.ttf ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/misc/UI-Farsi-Digits-Non-Latin/fonts/ttf/*.ttf ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/misc/UI-Non-Latin/fonts/ttf/*.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
