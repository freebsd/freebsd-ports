PORTNAME=	noto
PORTVERSION=	2.013
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/notofonts/notofonts.github.io/raw/NotoSerif-v${PORTVERSION}/fonts/ \
		https://github.com/notofonts/notofonts.github.io/raw/NotoSerif-v${PORTVERSION}/fonts/NotoSerif/hinted/ttf/:fonts
PKGNAMESUFFIX=	-serif
DISTFILES=	LICENSE \
		${FONTS:S|$|:fonts|}
DIST_SUBDIR=	Noto/Serif/${PORTVERSION}
EXTRACT_ONLY=	# empty

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Noto Serif
WWW=		https://fonts.google.com/noto \
		https://notofonts.github.io/ \
		https://github.com/notofonts/latin-greek-cyrillic \
		https://github.com/notofonts/notofonts.github.io/tree/main/fonts/NotoSerif

LICENSE=	OFL11
LICENSE_FILE=	${DISTDIR}/${DIST_SUBDIR}/LICENSE

USES=		fonts

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

FONTS=		NotoSerif-Black.ttf \
		NotoSerif-BlackItalic.ttf \
		NotoSerif-Bold.ttf \
		NotoSerif-BoldItalic.ttf \
		NotoSerif-Condensed.ttf \
		NotoSerif-CondensedBlack.ttf \
		NotoSerif-CondensedBlackItalic.ttf \
		NotoSerif-CondensedBold.ttf \
		NotoSerif-CondensedBoldItalic.ttf \
		NotoSerif-CondensedExtraBold.ttf \
		NotoSerif-CondensedExtraBoldItalic.ttf \
		NotoSerif-CondensedExtraLight.ttf \
		NotoSerif-CondensedExtraLightItalic.ttf \
		NotoSerif-CondensedItalic.ttf \
		NotoSerif-CondensedLight.ttf \
		NotoSerif-CondensedLightItalic.ttf \
		NotoSerif-CondensedMedium.ttf \
		NotoSerif-CondensedMediumItalic.ttf \
		NotoSerif-CondensedSemiBold.ttf \
		NotoSerif-CondensedSemiBoldItalic.ttf \
		NotoSerif-CondensedThin.ttf \
		NotoSerif-CondensedThinItalic.ttf \
		NotoSerif-ExtraBold.ttf \
		NotoSerif-ExtraBoldItalic.ttf \
		NotoSerif-ExtraCondensed.ttf \
		NotoSerif-ExtraCondensedBlack.ttf \
		NotoSerif-ExtraCondensedBlackItalic.ttf \
		NotoSerif-ExtraCondensedBold.ttf \
		NotoSerif-ExtraCondensedBoldItalic.ttf \
		NotoSerif-ExtraCondensedExtraBold.ttf \
		NotoSerif-ExtraCondensedExtraBoldItalic.ttf \
		NotoSerif-ExtraCondensedExtraLight.ttf \
		NotoSerif-ExtraCondensedExtraLightItalic.ttf \
		NotoSerif-ExtraCondensedItalic.ttf \
		NotoSerif-ExtraCondensedLight.ttf \
		NotoSerif-ExtraCondensedLightItalic.ttf \
		NotoSerif-ExtraCondensedMedium.ttf \
		NotoSerif-ExtraCondensedMediumItalic.ttf \
		NotoSerif-ExtraCondensedSemiBold.ttf \
		NotoSerif-ExtraCondensedSemiBoldItalic.ttf \
		NotoSerif-ExtraCondensedThin.ttf \
		NotoSerif-ExtraCondensedThinItalic.ttf \
		NotoSerif-ExtraLight.ttf \
		NotoSerif-ExtraLightItalic.ttf \
		NotoSerif-Italic.ttf \
		NotoSerif-Light.ttf \
		NotoSerif-LightItalic.ttf \
		NotoSerif-Medium.ttf \
		NotoSerif-MediumItalic.ttf \
		NotoSerif-Regular.ttf \
		NotoSerif-SemiBold.ttf \
		NotoSerif-SemiBoldItalic.ttf \
		NotoSerif-SemiCondensed.ttf \
		NotoSerif-SemiCondensedBlack.ttf \
		NotoSerif-SemiCondensedBlackItalic.ttf \
		NotoSerif-SemiCondensedBold.ttf \
		NotoSerif-SemiCondensedBoldItalic.ttf \
		NotoSerif-SemiCondensedExtraBold.ttf \
		NotoSerif-SemiCondensedExtraBoldItalic.ttf \
		NotoSerif-SemiCondensedExtraLight.ttf \
		NotoSerif-SemiCondensedExtraLightItalic.ttf \
		NotoSerif-SemiCondensedItalic.ttf \
		NotoSerif-SemiCondensedLight.ttf \
		NotoSerif-SemiCondensedLightItalic.ttf \
		NotoSerif-SemiCondensedMedium.ttf \
		NotoSerif-SemiCondensedMediumItalic.ttf \
		NotoSerif-SemiCondensedSemiBold.ttf \
		NotoSerif-SemiCondensedSemiBoldItalic.ttf \
		NotoSerif-SemiCondensedThin.ttf \
		NotoSerif-SemiCondensedThinItalic.ttf \
		NotoSerif-Thin.ttf \
		NotoSerif-ThinItalic.ttf

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${INSTALL_DATA} ${FONTS} ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
