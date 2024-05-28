PORTNAME=	noto
PORTVERSION=	2.006
CATEGORIES=	x11-fonts
#MASTER_SITES=	https://github.com/notofonts/notofonts.github.io/raw/NotoSansDevanagari-v${PORTVERSION}/fonts/ \
#		https://github.com/notofonts/notofonts.github.io/raw/NotoSansDevanagari-v${PORTVERSION}/fonts/NotoSansDevanagari/hinted/ttf/:fonts
#MASTER_SITES=	https://github.com/notofonts/notofonts.github.io/raw/noto-monthly-release-23.4.1/fonts/ \
#		https://github.com/notofonts/notofonts.github.io/raw/noto-monthly-release-23.4.1/fonts/NotoSansDevanagari/hinted/ttf/:fonts
MASTER_SITES=	https://github.com/notofonts/notofonts.github.io/raw/4107892fb07b01fbccc96e43638028f6bf127a4a/fonts/ \
		https://github.com/notofonts/notofonts.github.io/raw/4107892fb07b01fbccc96e43638028f6bf127a4a/fonts/NotoSansDevanagari/hinted/ttf/:fonts
PKGNAMESUFFIX=	-sans-devanagari
DISTFILES=	LICENSE \
		${FONTS:S|$|:fonts|}
DIST_SUBDIR=	Noto/SansDevanagari/${PORTVERSION}
EXTRACT_ONLY=	# empty

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Noto Sans Devanagari
WWW=		https://fonts.google.com/noto \
		https://notofonts.github.io/ \
		https://github.com/notofonts/devanagari \
		https://github.com/notofonts/notofonts.github.io/tree/main/fonts/NotoSansDevanagari

LICENSE=	OFL11
LICENSE_FILE=	${DISTDIR}/${DIST_SUBDIR}/LICENSE

USES=		fonts

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

FONTS=		NotoSansDevanagari-Black.ttf \
		NotoSansDevanagari-Bold.ttf \
		NotoSansDevanagari-Condensed.ttf \
		NotoSansDevanagari-CondensedBlack.ttf \
		NotoSansDevanagari-CondensedBold.ttf \
		NotoSansDevanagari-CondensedExtraBold.ttf \
		NotoSansDevanagari-CondensedExtraLight.ttf \
		NotoSansDevanagari-CondensedLight.ttf \
		NotoSansDevanagari-CondensedMedium.ttf \
		NotoSansDevanagari-CondensedSemiBold.ttf \
		NotoSansDevanagari-CondensedThin.ttf \
		NotoSansDevanagari-ExtraBold.ttf \
		NotoSansDevanagari-ExtraCondensed.ttf \
		NotoSansDevanagari-ExtraCondensedBlack.ttf \
		NotoSansDevanagari-ExtraCondensedBold.ttf \
		NotoSansDevanagari-ExtraCondensedExtraBold.ttf \
		NotoSansDevanagari-ExtraCondensedExtraLight.ttf \
		NotoSansDevanagari-ExtraCondensedLight.ttf \
		NotoSansDevanagari-ExtraCondensedMedium.ttf \
		NotoSansDevanagari-ExtraCondensedSemiBold.ttf \
		NotoSansDevanagari-ExtraCondensedThin.ttf \
		NotoSansDevanagari-ExtraLight.ttf \
		NotoSansDevanagari-Light.ttf \
		NotoSansDevanagari-Medium.ttf \
		NotoSansDevanagari-Regular.ttf \
		NotoSansDevanagari-SemiBold.ttf \
		NotoSansDevanagari-SemiCondensed.ttf \
		NotoSansDevanagari-SemiCondensedBlack.ttf \
		NotoSansDevanagari-SemiCondensedBold.ttf \
		NotoSansDevanagari-SemiCondensedExtraBold.ttf \
		NotoSansDevanagari-SemiCondensedExtraLight.ttf \
		NotoSansDevanagari-SemiCondensedLight.ttf \
		NotoSansDevanagari-SemiCondensedMedium.ttf \
		NotoSansDevanagari-SemiCondensedSemiBold.ttf \
		NotoSansDevanagari-SemiCondensedThin.ttf \
		NotoSansDevanagari-Thin.ttf \
		NotoSansDevanagariUI-Black.ttf \
		NotoSansDevanagariUI-Bold.ttf \
		NotoSansDevanagariUI-Condensed.ttf \
		NotoSansDevanagariUI-CondensedBlack.ttf \
		NotoSansDevanagariUI-CondensedBold.ttf \
		NotoSansDevanagariUI-CondensedExtraBold.ttf \
		NotoSansDevanagariUI-CondensedExtraLight.ttf \
		NotoSansDevanagariUI-CondensedLight.ttf \
		NotoSansDevanagariUI-CondensedMedium.ttf \
		NotoSansDevanagariUI-CondensedSemiBold.ttf \
		NotoSansDevanagariUI-CondensedThin.ttf \
		NotoSansDevanagariUI-ExtraBold.ttf \
		NotoSansDevanagariUI-ExtraCondensed.ttf \
		NotoSansDevanagariUI-ExtraCondensedBlack.ttf \
		NotoSansDevanagariUI-ExtraCondensedBold.ttf \
		NotoSansDevanagariUI-ExtraCondensedExtraBold.ttf \
		NotoSansDevanagariUI-ExtraCondensedExtraLight.ttf \
		NotoSansDevanagariUI-ExtraCondensedLight.ttf \
		NotoSansDevanagariUI-ExtraCondensedMedium.ttf \
		NotoSansDevanagariUI-ExtraCondensedSemiBold.ttf \
		NotoSansDevanagariUI-ExtraCondensedThin.ttf \
		NotoSansDevanagariUI-ExtraLight.ttf \
		NotoSansDevanagariUI-Light.ttf \
		NotoSansDevanagariUI-Medium.ttf \
		NotoSansDevanagariUI-Regular.ttf \
		NotoSansDevanagariUI-SemiBold.ttf \
		NotoSansDevanagariUI-SemiCondensed.ttf \
		NotoSansDevanagariUI-SemiCondensedBlack.ttf \
		NotoSansDevanagariUI-SemiCondensedBold.ttf \
		NotoSansDevanagariUI-SemiCondensedExtraBold.ttf \
		NotoSansDevanagariUI-SemiCondensedExtraLight.ttf \
		NotoSansDevanagariUI-SemiCondensedLight.ttf \
		NotoSansDevanagariUI-SemiCondensedMedium.ttf \
		NotoSansDevanagariUI-SemiCondensedSemiBold.ttf \
		NotoSansDevanagariUI-SemiCondensedThin.ttf \
		NotoSansDevanagariUI-Thin.ttf

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${INSTALL_DATA} ${FONTS} ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
