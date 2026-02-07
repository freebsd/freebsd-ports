PORTNAME=	noto
PORTVERSION=	2.009
CATEGORIES=	x11-fonts
#MASTER_SITES=	https://github.com/notofonts/notofonts.github.io/raw/NotoSerifDisplay-v${PORTVERSION}/fonts/ \
#		https://github.com/notofonts/notofonts.github.io/raw/NotoSerifDisplay-v${PORTVERSION}/fonts/NotoSerifDisplay/hinted/ttf/:fonts
MASTER_SITES=	https://github.com/notofonts/notofonts.github.io/raw/noto-monthly-release-23.2.1/fonts/ \
		https://github.com/notofonts/notofonts.github.io/raw/noto-monthly-release-23.2.1/fonts/NotoSerifDisplay/hinted/ttf/:fonts
PKGNAMESUFFIX=	-serif-display
DISTFILES=	LICENSE \
		${FONTS:S|$|:fonts|}
DIST_SUBDIR=	Noto/SerifDisplay/${PORTVERSION}
EXTRACT_ONLY=	# empty

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Noto Serif Display
WWW=		https://fonts.google.com/noto \
		https://notofonts.github.io/ \
		https://github.com/notofonts/display \
		https://github.com/notofonts/notofonts.github.io/tree/main/fonts/NotoSerifDisplay

LICENSE=	OFL11
LICENSE_FILE=	${DISTDIR}/${DIST_SUBDIR}/LICENSE

USES=		fonts

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

FONTS=		NotoSerifDisplay-Black.ttf \
		NotoSerifDisplay-BlackItalic.ttf \
		NotoSerifDisplay-Bold.ttf \
		NotoSerifDisplay-BoldItalic.ttf \
		NotoSerifDisplay-Condensed.ttf \
		NotoSerifDisplay-CondensedBlack.ttf \
		NotoSerifDisplay-CondensedBlackItalic.ttf \
		NotoSerifDisplay-CondensedBold.ttf \
		NotoSerifDisplay-CondensedBoldItalic.ttf \
		NotoSerifDisplay-CondensedExtraBold.ttf \
		NotoSerifDisplay-CondensedExtraBoldItalic.ttf \
		NotoSerifDisplay-CondensedExtraLight.ttf \
		NotoSerifDisplay-CondensedExtraLightItalic.ttf \
		NotoSerifDisplay-CondensedItalic.ttf \
		NotoSerifDisplay-CondensedLight.ttf \
		NotoSerifDisplay-CondensedLightItalic.ttf \
		NotoSerifDisplay-CondensedMedium.ttf \
		NotoSerifDisplay-CondensedMediumItalic.ttf \
		NotoSerifDisplay-CondensedSemiBold.ttf \
		NotoSerifDisplay-CondensedSemiBoldItalic.ttf \
		NotoSerifDisplay-CondensedThin.ttf \
		NotoSerifDisplay-CondensedThinItalic.ttf \
		NotoSerifDisplay-ExtraBold.ttf \
		NotoSerifDisplay-ExtraBoldItalic.ttf \
		NotoSerifDisplay-ExtraCondensed.ttf \
		NotoSerifDisplay-ExtraCondensedBlack.ttf \
		NotoSerifDisplay-ExtraCondensedBlackItalic.ttf \
		NotoSerifDisplay-ExtraCondensedBold.ttf \
		NotoSerifDisplay-ExtraCondensedBoldItalic.ttf \
		NotoSerifDisplay-ExtraCondensedExtraBold.ttf \
		NotoSerifDisplay-ExtraCondensedExtraBoldItalic.ttf \
		NotoSerifDisplay-ExtraCondensedExtraLight.ttf \
		NotoSerifDisplay-ExtraCondensedExtraLightItalic.ttf \
		NotoSerifDisplay-ExtraCondensedItalic.ttf \
		NotoSerifDisplay-ExtraCondensedLight.ttf \
		NotoSerifDisplay-ExtraCondensedLightItalic.ttf \
		NotoSerifDisplay-ExtraCondensedMedium.ttf \
		NotoSerifDisplay-ExtraCondensedMediumItalic.ttf \
		NotoSerifDisplay-ExtraCondensedSemiBold.ttf \
		NotoSerifDisplay-ExtraCondensedSemiBoldItalic.ttf \
		NotoSerifDisplay-ExtraCondensedThin.ttf \
		NotoSerifDisplay-ExtraCondensedThinItalic.ttf \
		NotoSerifDisplay-ExtraLight.ttf \
		NotoSerifDisplay-ExtraLightItalic.ttf \
		NotoSerifDisplay-Italic.ttf \
		NotoSerifDisplay-Light.ttf \
		NotoSerifDisplay-LightItalic.ttf \
		NotoSerifDisplay-Medium.ttf \
		NotoSerifDisplay-MediumItalic.ttf \
		NotoSerifDisplay-Regular.ttf \
		NotoSerifDisplay-SemiBold.ttf \
		NotoSerifDisplay-SemiBoldItalic.ttf \
		NotoSerifDisplay-SemiCondensed.ttf \
		NotoSerifDisplay-SemiCondensedBlack.ttf \
		NotoSerifDisplay-SemiCondensedBlackItalic.ttf \
		NotoSerifDisplay-SemiCondensedBold.ttf \
		NotoSerifDisplay-SemiCondensedBoldItalic.ttf \
		NotoSerifDisplay-SemiCondensedExtraBold.ttf \
		NotoSerifDisplay-SemiCondensedExtraBoldItalic.ttf \
		NotoSerifDisplay-SemiCondensedExtraLight.ttf \
		NotoSerifDisplay-SemiCondensedExtraLightItalic.ttf \
		NotoSerifDisplay-SemiCondensedItalic.ttf \
		NotoSerifDisplay-SemiCondensedLight.ttf \
		NotoSerifDisplay-SemiCondensedLightItalic.ttf \
		NotoSerifDisplay-SemiCondensedMedium.ttf \
		NotoSerifDisplay-SemiCondensedMediumItalic.ttf \
		NotoSerifDisplay-SemiCondensedSemiBold.ttf \
		NotoSerifDisplay-SemiCondensedSemiBoldItalic.ttf \
		NotoSerifDisplay-SemiCondensedThin.ttf \
		NotoSerifDisplay-SemiCondensedThinItalic.ttf \
		NotoSerifDisplay-Thin.ttf \
		NotoSerifDisplay-ThinItalic.ttf

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${INSTALL_DATA} ${FONTS} ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
