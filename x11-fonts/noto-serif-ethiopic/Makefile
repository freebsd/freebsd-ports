PORTNAME=	noto
PORTVERSION=	2.102
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/notofonts/ethiopic/releases/download/NotoSerifEthiopic-v${PORTVERSION}/
PKGNAMESUFFIX=	-serif-ethiopic
DISTNAME=	NotoSerifEthiopic-v${PORTVERSION}
DIST_SUBDIR=	Noto

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Noto Serif Ethiopic
WWW=		https://fonts.google.com/noto \
		https://notofonts.github.io/ \
		https://github.com/notofonts/ethiopic

LICENSE=	OFL11
#LICENSE_FILE=	${WRKSRC}/OFL.txt

USES=		fonts zip

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/NotoSerifEthiopic/hinted/ttf/*.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
