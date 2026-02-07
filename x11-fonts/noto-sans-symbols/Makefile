PORTNAME=	noto
PORTVERSION=	2.008
PORTREVISION=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/notofonts/notofonts.github.io/raw/noto-monthly-release-23.7.1/fonts/ \
		https://github.com/notofonts/notofonts.github.io/raw/noto-monthly-release-23.7.1/fonts/NotoSansSymbols/hinted/ttf/:fonts
PKGNAMESUFFIX=	-sans-symbols
DISTFILES=	LICENSE \
		${FONTS:S|$|:fonts|}
DIST_SUBDIR=	Noto/SansSymbols/${PORTVERSION}
EXTRACT_ONLY=	# empty

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Noto Sans Symbols
WWW=		https://fonts.google.com/noto \
		https://notofonts.github.io/ \
		https://github.com/notofonts/symbols \
		https://github.com/notofonts/notofonts.github.io/tree/main/fonts/NotoSansSymbols

LICENSE=	OFL11
LICENSE_FILE=	${DISTDIR}/${DIST_SUBDIR}/LICENSE

USES=		fonts

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

FONTS=		NotoSansSymbols-Black.ttf \
		NotoSansSymbols-Bold.ttf \
		NotoSansSymbols-ExtraBold.ttf \
		NotoSansSymbols-ExtraLight.ttf \
		NotoSansSymbols-Light.ttf \
		NotoSansSymbols-Medium.ttf \
		NotoSansSymbols-Regular.ttf \
		NotoSansSymbols-SemiBold.ttf \
		NotoSansSymbols-Thin.ttf

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${INSTALL_DATA} ${FONTS} ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
