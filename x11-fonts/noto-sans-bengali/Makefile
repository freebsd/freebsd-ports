PORTNAME=	noto
PORTVERSION=	3.000
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/notofonts/notofonts.github.io/raw/NotoSansBengali-v${PORTVERSION}/ \
		https://github.com/notofonts/notofonts.github.io/raw/NotoSansBengali-v${PORTVERSION}/fonts/NotoSansBengali/hinted/ttf/:fonts
PKGNAMESUFFIX=	-sans-bengali
DISTFILES=	LICENSE \
		${FONTS:S|$|:fonts|}
DIST_SUBDIR=	Noto/SansBengali/${PORTVERSION}
EXTRACT_ONLY=	# empty

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Noto Sans Bengali
WWW=		https://fonts.google.com/noto \
		https://notofonts.github.io/ \
		https://github.com/notofonts/bengali \
		https://github.com/notofonts/notofonts.github.io/tree/main/fonts/NotoSansBengali

LICENSE=	OFL11
LICENSE_FILE=	${DISTDIR}/${DIST_SUBDIR}/LICENSE

USES=		fonts

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

FONTS=		NotoSansBengali-Black.ttf \
		NotoSansBengali-Bold.ttf \
		NotoSansBengali-Condensed.ttf \
		NotoSansBengali-ExtraBold.ttf \
		NotoSansBengali-ExtraCondensed.ttf \
		NotoSansBengali-ExtraLight.ttf \
		NotoSansBengali-Light.ttf \
		NotoSansBengali-Medium.ttf \
		NotoSansBengali-Regular.ttf \
		NotoSansBengali-SemiBold.ttf \
		NotoSansBengali-SemiCondensed.ttf \
		NotoSansBengali-Thin.ttf \
		NotoSansBengaliUI-Black.ttf \
		NotoSansBengaliUI-Bold.ttf \
		NotoSansBengaliUI-Condensed.ttf \
		NotoSansBengaliUI-ExtraBold.ttf \
		NotoSansBengaliUI-ExtraCondensed.ttf \
		NotoSansBengaliUI-ExtraLight.ttf \
		NotoSansBengaliUI-Light.ttf \
		NotoSansBengaliUI-Medium.ttf \
		NotoSansBengaliUI-Regular.ttf \
		NotoSansBengaliUI-SemiBold.ttf \
		NotoSansBengaliUI-SemiCondensed.ttf \
		NotoSansBengaliUI-Thin.ttf

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${INSTALL_DATA} ${FONTS} ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
