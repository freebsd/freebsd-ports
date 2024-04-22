PORTNAME=	noto
PORTVERSION=	2.107
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/notofonts/myanmar/releases/download/NotoSansMyanmar-v${PORTVERSION}/
PKGNAMESUFFIX=	-sans-myanmar
DISTNAME=	NotoSansMyanmar-v${PORTVERSION}
DIST_SUBDIR=	Noto

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Noto Sans Myanmar
WWW=		https://fonts.google.com/noto \
		https://notofonts.github.io/ \
		https://github.com/notofonts/myanmar

LICENSE=	OFL11
#LICENSE_FILE=	${WRKSRC}/OFL.txt

USES=		fonts zip

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/NotoSansMyanmar/hinted/ttf/*.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
