# $FreeBSD$

PORTNAME=	hack-font
PORTVERSION=	3.003
DISTVERSIONPREFIX=	v
CATEGORIES=	x11-fonts

MAINTAINER=	rakuco@FreeBSD.org
COMMENT=	Typeface designed for source code

LICENSE=		BITSTREAM MIT
LICENSE_COMB=		multi
LICENSE_NAME_BITSTREAM=	Bitstream Vera License
LICENSE_FILE_BITSTREAM=	${WRKSRC}/LICENSE.md
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE.md
LICENSE_PERMS_BITSTREAM=auto-accept dist-mirror dist-sell pkg-mirror pkg-sell

USE_GITHUB=	yes
GH_ACCOUNT=	source-foundry
GH_PROJECT=	Hack

USES=		fonts
NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${WRKSRC}/build/ttf/*.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
