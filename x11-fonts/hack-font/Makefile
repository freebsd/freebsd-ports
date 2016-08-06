# $FreeBSD$

PORTNAME=	hack-font
PORTVERSION=	2.020
DISTVERSIONPREFIX=	v
CATEGORIES=	x11-fonts

MAINTAINER=	rakuco@FreeBSD.org
COMMENT=	Typeface designed for source code

LICENSE=		BITSTREAM HACK2
LICENSE_COMB=		multi
LICENSE_NAME_BITSTREAM=	Bitstream Vera License
LICENSE_NAME_HACK2=	Hack Open Font License v2.0
LICENSE_FILE_BITSTREAM=	${WRKSRC}/LICENSE.md
LICENSE_FILE_HACK2=	${WRKSRC}/LICENSE.md
LICENSE_PERMS_BITSTREAM=auto-accept dist-mirror dist-sell pkg-mirror pkg-sell
LICENSE_PERMS_HACK2=	auto-accept dist-mirror dist-sell pkg-mirror pkg-sell

USE_GITHUB=	yes
GH_ACCOUNT=	chrissimpkins
GH_PROJECT=	Hack

USES=		fonts
NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${WRKSRC}/build/otf/*.otf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
