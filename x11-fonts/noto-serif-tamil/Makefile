PORTNAME=	noto
PORTVERSION=	2.004
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/notofonts/notofonts.github.io/raw/noto-monthly-release-23.4.1/fonts/ \
		https://github.com/notofonts/notofonts.github.io/raw/noto-monthly-release-23.4.1/fonts/NotoSerifTamil/hinted/ttf/:fonts
PKGNAMESUFFIX=	-serif-tamil
DISTFILES=	LICENSE \
		${FONTS:S|$|:fonts|}
DIST_SUBDIR=	Noto/SerifTamil/${PORTVERSION}
EXTRACT_ONLY=	# empty

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Noto Serif Tamil
WWW=		https://fonts.google.com/noto \
		https://notofonts.github.io/ \
		https://github.com/notofonts/tamil \
		https://github.com/notofonts/notofonts.github.io/tree/main/fonts/NotoSerifTamil

LICENSE=	OFL11
LICENSE_FILE=	${DISTDIR}/${DIST_SUBDIR}/LICENSE

USES=		fonts

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

FONTS=		NotoSerifTamil-Black.ttf \
		NotoSerifTamil-BlackItalic.ttf \
		NotoSerifTamil-Bold.ttf \
		NotoSerifTamil-BoldItalic.ttf \
		NotoSerifTamil-Condensed.ttf \
		NotoSerifTamil-CondensedBlack.ttf \
		NotoSerifTamil-CondensedBlackItalic.ttf \
		NotoSerifTamil-CondensedBold.ttf \
		NotoSerifTamil-CondensedBoldItalic.ttf \
		NotoSerifTamil-CondensedExtraBold.ttf \
		NotoSerifTamil-CondensedExtraBoldItalic.ttf \
		NotoSerifTamil-CondensedExtraLight.ttf \
		NotoSerifTamil-CondensedExtraLightItalic.ttf \
		NotoSerifTamil-CondensedItalic.ttf \
		NotoSerifTamil-CondensedLight.ttf \
		NotoSerifTamil-CondensedLightItalic.ttf \
		NotoSerifTamil-CondensedMedium.ttf \
		NotoSerifTamil-CondensedMediumItalic.ttf \
		NotoSerifTamil-CondensedSemiBold.ttf \
		NotoSerifTamil-CondensedSemiBoldItalic.ttf \
		NotoSerifTamil-CondensedThin.ttf \
		NotoSerifTamil-CondensedThinItalic.ttf \
		NotoSerifTamil-ExtraBold.ttf \
		NotoSerifTamil-ExtraBoldItalic.ttf \
		NotoSerifTamil-ExtraCondensed.ttf \
		NotoSerifTamil-ExtraCondensedBlack.ttf \
		NotoSerifTamil-ExtraCondensedBlackItalic.ttf \
		NotoSerifTamil-ExtraCondensedBold.ttf \
		NotoSerifTamil-ExtraCondensedBoldItalic.ttf \
		NotoSerifTamil-ExtraCondensedExtraBold.ttf \
		NotoSerifTamil-ExtraCondensedExtraBoldItalic.ttf \
		NotoSerifTamil-ExtraCondensedExtraLight.ttf \
		NotoSerifTamil-ExtraCondensedExtraLightItalic.ttf \
		NotoSerifTamil-ExtraCondensedItalic.ttf \
		NotoSerifTamil-ExtraCondensedLight.ttf \
		NotoSerifTamil-ExtraCondensedLightItalic.ttf \
		NotoSerifTamil-ExtraCondensedMedium.ttf \
		NotoSerifTamil-ExtraCondensedMediumItalic.ttf \
		NotoSerifTamil-ExtraCondensedSemiBold.ttf \
		NotoSerifTamil-ExtraCondensedSemiBoldItalic.ttf \
		NotoSerifTamil-ExtraCondensedThin.ttf \
		NotoSerifTamil-ExtraCondensedThinItalic.ttf \
		NotoSerifTamil-ExtraLight.ttf \
		NotoSerifTamil-ExtraLightItalic.ttf \
		NotoSerifTamil-Italic.ttf \
		NotoSerifTamil-Light.ttf \
		NotoSerifTamil-LightItalic.ttf \
		NotoSerifTamil-Medium.ttf \
		NotoSerifTamil-MediumItalic.ttf \
		NotoSerifTamil-Regular.ttf \
		NotoSerifTamil-SemiBold.ttf \
		NotoSerifTamil-SemiBoldItalic.ttf \
		NotoSerifTamil-SemiCondensed.ttf \
		NotoSerifTamil-SemiCondensedBlack.ttf \
		NotoSerifTamil-SemiCondensedBlackItalic.ttf \
		NotoSerifTamil-SemiCondensedBold.ttf \
		NotoSerifTamil-SemiCondensedBoldItalic.ttf \
		NotoSerifTamil-SemiCondensedExtraBold.ttf \
		NotoSerifTamil-SemiCondensedExtraBoldItalic.ttf \
		NotoSerifTamil-SemiCondensedExtraLight.ttf \
		NotoSerifTamil-SemiCondensedExtraLightItalic.ttf \
		NotoSerifTamil-SemiCondensedItalic.ttf \
		NotoSerifTamil-SemiCondensedLight.ttf \
		NotoSerifTamil-SemiCondensedLightItalic.ttf \
		NotoSerifTamil-SemiCondensedMedium.ttf \
		NotoSerifTamil-SemiCondensedMediumItalic.ttf \
		NotoSerifTamil-SemiCondensedSemiBold.ttf \
		NotoSerifTamil-SemiCondensedSemiBoldItalic.ttf \
		NotoSerifTamil-SemiCondensedThin.ttf \
		NotoSerifTamil-SemiCondensedThinItalic.ttf \
		NotoSerifTamil-Thin.ttf \
		NotoSerifTamil-ThinItalic.ttf

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${INSTALL_DATA} ${FONTS} ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
