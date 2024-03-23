PORTNAME=	noto
PORTVERSION=	2.003
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/notofonts/symbols/releases/download/NotoSansSymbols-v${PORTVERSION}/
PKGNAMESUFFIX=	-sans-symbols-extra
DISTNAME=	NotoSansSymbols-v${PORTVERSION}
DIST_SUBDIR=	Noto

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Noto Sans Symbols (Extra)
WWW=		https://fonts.google.com/noto \
		https://notofonts.github.io/ \
		https://github.com/notofonts/symbols

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/OFL.txt

USES=		fonts zip

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

post-patch:
	@${RM} ${WRKSRC}/NotoSansSymbols/hinted/ttf/NotoSansSymbols-Bold.ttf
	@${RM} ${WRKSRC}/NotoSansSymbols/hinted/ttf/NotoSansSymbols-Regular.ttf

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/NotoSansSymbols/hinted/ttf/*.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
