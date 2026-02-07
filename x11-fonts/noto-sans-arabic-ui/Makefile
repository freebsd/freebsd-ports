PORTNAME=	noto
PORTVERSION=	2.011
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/notofonts/notofonts.github.io/raw/NotoSansArabicUI-v${PORTVERSION}/fonts/ \
		https://github.com/notofonts/notofonts.github.io/raw/NotoSansArabicUI-v${PORTVERSION}/fonts/NotoSansArabicUI/hinted/ttf/:fonts
PKGNAMESUFFIX=	-sans-arabic-ui
DISTFILES=	LICENSE \
		${FONTS:S|$|:fonts|}
DIST_SUBDIR=	Noto/SansArabicUI/${PORTVERSION}
EXTRACT_ONLY=	# empty

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Noto Sans Arabic UI
WWW=		https://fonts.google.com/noto \
		https://notofonts.github.io/ \
		https://github.com/notofonts/arabic \
		https://github.com/notofonts/notofonts.github.io/tree/main/fonts/NotoSansArabicUI

LICENSE=	OFL11
LICENSE_FILE=	${DISTDIR}/${DIST_SUBDIR}/LICENSE

USES=		fonts

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

FONTS=		NotoSansArabicUI-Black.ttf \
		NotoSansArabicUI-Bold.ttf \
		NotoSansArabicUI-Condensed.ttf \
		NotoSansArabicUI-CondensedBlack.ttf \
		NotoSansArabicUI-CondensedBold.ttf \
		NotoSansArabicUI-CondensedExtraBold.ttf \
		NotoSansArabicUI-CondensedExtraLight.ttf \
		NotoSansArabicUI-CondensedLight.ttf \
		NotoSansArabicUI-CondensedMedium.ttf \
		NotoSansArabicUI-CondensedSemiBold.ttf \
		NotoSansArabicUI-CondensedThin.ttf \
		NotoSansArabicUI-ExtraBold.ttf \
		NotoSansArabicUI-ExtraCondensed.ttf \
		NotoSansArabicUI-ExtraCondensedBlack.ttf \
		NotoSansArabicUI-ExtraCondensedBold.ttf \
		NotoSansArabicUI-ExtraCondensedExtraBold.ttf \
		NotoSansArabicUI-ExtraCondensedExtraLight.ttf \
		NotoSansArabicUI-ExtraCondensedLight.ttf \
		NotoSansArabicUI-ExtraCondensedMedium.ttf \
		NotoSansArabicUI-ExtraCondensedSemiBold.ttf \
		NotoSansArabicUI-ExtraCondensedThin.ttf \
		NotoSansArabicUI-ExtraLight.ttf \
		NotoSansArabicUI-Light.ttf \
		NotoSansArabicUI-Medium.ttf \
		NotoSansArabicUI-Regular.ttf \
		NotoSansArabicUI-SemiBold.ttf \
		NotoSansArabicUI-SemiCondensed.ttf \
		NotoSansArabicUI-SemiCondensedBlack.ttf \
		NotoSansArabicUI-SemiCondensedBold.ttf \
		NotoSansArabicUI-SemiCondensedExtraBold.ttf \
		NotoSansArabicUI-SemiCondensedExtraLight.ttf \
		NotoSansArabicUI-SemiCondensedLight.ttf \
		NotoSansArabicUI-SemiCondensedMedium.ttf \
		NotoSansArabicUI-SemiCondensedSemiBold.ttf \
		NotoSansArabicUI-SemiCondensedThin.ttf \
		NotoSansArabicUI-Thin.ttf

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${INSTALL_DATA} ${FONTS} ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
