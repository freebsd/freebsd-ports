PORTNAME=	noto
PORTVERSION=	2.008
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/notofonts/symbols/releases/download/NotoSansSymbols2-v${PORTVERSION}/
PKGNAMESUFFIX=	-sans-symbols2
DISTNAME=	NotoSansSymbols2-v${PORTVERSION}
DIST_SUBDIR=	Noto

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Noto Sans Symbols 2
WWW=		https://fonts.google.com/noto \
		https://notofonts.github.io/ \
		https://github.com/notofonts/symbols

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/OFL.txt

USES=		fonts zip

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	${FONTSDIR}/NotoSansSymbols2-Regular.ttf

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/NotoSansSymbols2/hinted/ttf/NotoSansSymbols2-Regular.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
