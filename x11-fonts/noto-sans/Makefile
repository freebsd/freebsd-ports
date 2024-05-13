PORTNAME=	noto
PORTVERSION=	2.013
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/notofonts/notofonts.github.io/raw/NotoSans-v${PORTVERSION}/fonts/ \
		https://github.com/notofonts/notofonts.github.io/raw/NotoSans-v${PORTVERSION}/fonts/NotoSans/hinted/ttf/:fonts
PKGNAMESUFFIX=	-sans
DISTFILES=	LICENSE \
		${FONTS:S|$|:fonts|}
DIST_SUBDIR=	Noto/Sans/${PORTVERSION}
EXTRACT_ONLY=	# empty

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Noto Sans
WWW=		https://fonts.google.com/noto \
		https://notofonts.github.io/ \
		https://github.com/notofonts/latin-greek-cyrillic \
		https://github.com/notofonts/notofonts.github.io/tree/main/fonts/NotoSans

LICENSE=	OFL11
LICENSE_FILE=	${DISTDIR}/${DIST_SUBDIR}/LICENSE

USES=		fonts

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

FONTS=		NotoSans-Black.ttf \
		NotoSans-BlackItalic.ttf \
		NotoSans-Bold.ttf \
		NotoSans-BoldItalic.ttf \
		NotoSans-Condensed.ttf \
		NotoSans-CondensedBlack.ttf \
		NotoSans-CondensedBlackItalic.ttf \
		NotoSans-CondensedBold.ttf \
		NotoSans-CondensedBoldItalic.ttf \
		NotoSans-CondensedExtraBold.ttf \
		NotoSans-CondensedExtraBoldItalic.ttf \
		NotoSans-CondensedExtraLight.ttf \
		NotoSans-CondensedExtraLightItalic.ttf \
		NotoSans-CondensedItalic.ttf \
		NotoSans-CondensedLight.ttf \
		NotoSans-CondensedLightItalic.ttf \
		NotoSans-CondensedMedium.ttf \
		NotoSans-CondensedMediumItalic.ttf \
		NotoSans-CondensedSemiBold.ttf \
		NotoSans-CondensedSemiBoldItalic.ttf \
		NotoSans-CondensedThin.ttf \
		NotoSans-CondensedThinItalic.ttf \
		NotoSans-ExtraBold.ttf \
		NotoSans-ExtraBoldItalic.ttf \
		NotoSans-ExtraCondensed.ttf \
		NotoSans-ExtraCondensedBlack.ttf \
		NotoSans-ExtraCondensedBlackItalic.ttf \
		NotoSans-ExtraCondensedBold.ttf \
		NotoSans-ExtraCondensedBoldItalic.ttf \
		NotoSans-ExtraCondensedExtraBold.ttf \
		NotoSans-ExtraCondensedExtraBoldItalic.ttf \
		NotoSans-ExtraCondensedExtraLight.ttf \
		NotoSans-ExtraCondensedExtraLightItalic.ttf \
		NotoSans-ExtraCondensedItalic.ttf \
		NotoSans-ExtraCondensedLight.ttf \
		NotoSans-ExtraCondensedLightItalic.ttf \
		NotoSans-ExtraCondensedMedium.ttf \
		NotoSans-ExtraCondensedMediumItalic.ttf \
		NotoSans-ExtraCondensedSemiBold.ttf \
		NotoSans-ExtraCondensedSemiBoldItalic.ttf \
		NotoSans-ExtraCondensedThin.ttf \
		NotoSans-ExtraCondensedThinItalic.ttf \
		NotoSans-ExtraLight.ttf \
		NotoSans-ExtraLightItalic.ttf \
		NotoSans-Italic.ttf \
		NotoSans-Light.ttf \
		NotoSans-LightItalic.ttf \
		NotoSans-Medium.ttf \
		NotoSans-MediumItalic.ttf \
		NotoSans-Regular.ttf \
		NotoSans-SemiBold.ttf \
		NotoSans-SemiBoldItalic.ttf \
		NotoSans-SemiCondensed.ttf \
		NotoSans-SemiCondensedBlack.ttf \
		NotoSans-SemiCondensedBlackItalic.ttf \
		NotoSans-SemiCondensedBold.ttf \
		NotoSans-SemiCondensedBoldItalic.ttf \
		NotoSans-SemiCondensedExtraBold.ttf \
		NotoSans-SemiCondensedExtraBoldItalic.ttf \
		NotoSans-SemiCondensedExtraLight.ttf \
		NotoSans-SemiCondensedExtraLightItalic.ttf \
		NotoSans-SemiCondensedItalic.ttf \
		NotoSans-SemiCondensedLight.ttf \
		NotoSans-SemiCondensedLightItalic.ttf \
		NotoSans-SemiCondensedMedium.ttf \
		NotoSans-SemiCondensedMediumItalic.ttf \
		NotoSans-SemiCondensedSemiBold.ttf \
		NotoSans-SemiCondensedSemiBoldItalic.ttf \
		NotoSans-SemiCondensedThin.ttf \
		NotoSans-SemiCondensedThinItalic.ttf \
		NotoSans-Thin.ttf \
		NotoSans-ThinItalic.ttf

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${INSTALL_DATA} ${FONTS} ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
