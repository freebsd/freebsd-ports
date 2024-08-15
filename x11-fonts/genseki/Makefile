PORTNAME=	genseki
PORTVERSION=	1.501
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/ButTaiwan/genseki-font/releases/download/v${PORTVERSION}/
DISTNAME=	GenSekiGothic

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Free Gothic font family derived from Adobe Source Han Sans
WWW=		https://github.com/ButTaiwan/genseki-font

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/SIL_Open_Font_License_1.1.txt

USES=		fonts zip

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}/
	${INSTALL_DATA} ${WRKSRC}/*.ttc ${STAGEDIR}${FONTSDIR}/

.include <bsd.port.mk>
