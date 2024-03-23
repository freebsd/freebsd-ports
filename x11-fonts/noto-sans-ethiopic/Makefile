PORTNAME=	noto
PORTVERSION=	2.102
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/notofonts/ethiopic/releases/download/NotoSansEthiopic-v${PORTVERSION}/
PKGNAMESUFFIX=	-sans-ethiopic
DISTNAME=	NotoSansEthiopic-v${PORTVERSION}
DIST_SUBDIR=	Noto

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Noto Sans Ethiopic
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
	${INSTALL_DATA} ${WRKSRC}/NotoSansEthiopic/hinted/ttf/*.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
