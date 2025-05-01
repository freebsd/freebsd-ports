PORTNAME=	vazirmatn
DISTVERSION=	33.003
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/rastikerdar/${PORTNAME}/releases/download/v${DISTVERSION}/
DISTNAME=	${PORTNAME}-v${DISTVERSION}

MAINTAINER=	armean.shirazi@gmail.com
COMMENT=	Simple Persian/Arabic font
WWW=		https://rastikerdar.github.io/vazirmatn/

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/OFL.txt

USES=		fonts zip

EXTRACT_AFTER_ARGS=	-j -x *wght* *.woff2 *.css

NO_ARCH=	YES
NO_BUILD=	YES
NO_WRKSUBDIR=	YES

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
