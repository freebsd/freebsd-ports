PORTNAME=	noto
PORTVERSION=	2.109
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/notofonts/arabic/releases/download/NotoKufiArabic-v${PORTVERSION}/
PKGNAMESUFFIX=	-kufi-arabic
DISTNAME=	NotoKufiArabic-v${PORTVERSION}
DIST_SUBDIR=	Noto

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Noto Kufi Arabic
WWW=		https://fonts.google.com/noto \
		https://notofonts.github.io/ \
		https://github.com/notofonts/arabic

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/OFL.txt

USES=		fonts zip

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/NotoKufiArabic/hinted/ttf/*.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
