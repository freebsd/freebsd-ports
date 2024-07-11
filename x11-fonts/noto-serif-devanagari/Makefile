PORTNAME=	noto
PORTVERSION=	2.006
CATEGORIES=	x11-fonts
#MASTER_SITES=	https://github.com/notofonts/notofonts.github.io/raw/NotoSerifDevanagari-v${PORTVERSION}/fonts/ \
#		https://github.com/notofonts/notofonts.github.io/raw/NotoSerifDevanagari-v${PORTVERSION}/fonts/NotoSerifDevanagari/hinted/ttf/:fonts
#MASTER_SITES=	https://github.com/notofonts/notofonts.github.io/raw/noto-monthly-release-23.4.1/fonts/ \
#		https://github.com/notofonts/notofonts.github.io/raw/noto-monthly-release-23.4.1/fonts/NotoSerifDevanagari/hinted/ttf/:fonts
MASTER_SITES=	https://github.com/notofonts/notofonts.github.io/raw/4107892fb07b01fbccc96e43638028f6bf127a4a/fonts/ \
		https://github.com/notofonts/notofonts.github.io/raw/4107892fb07b01fbccc96e43638028f6bf127a4a/fonts/NotoSerifDevanagari/hinted/ttf/:fonts
PKGNAMESUFFIX=	-serif-devanagari
DISTFILES=	LICENSE \
		${FONTS:S|$|:fonts|}
DIST_SUBDIR=	Noto/SerifDevanagari/${PORTVERSION}
EXTRACT_ONLY=	# empty

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Noto Serif Devanagari
WWW=		https://fonts.google.com/noto \
		https://notofonts.github.io/ \
		https://github.com/notofonts/devanagari \
		https://github.com/notofonts/notofonts.github.io/tree/main/fonts/NotoSerifDevanagari

LICENSE=	OFL11
LICENSE_FILE=	${DISTDIR}/${DIST_SUBDIR}/LICENSE

USES=		fonts

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

FONTS=		NotoSerifDevanagari-Black.ttf \
		NotoSerifDevanagari-Bold.ttf \
		NotoSerifDevanagari-Condensed.ttf \
		NotoSerifDevanagari-CondensedBlack.ttf \
		NotoSerifDevanagari-CondensedBold.ttf \
		NotoSerifDevanagari-CondensedExtraBold.ttf \
		NotoSerifDevanagari-CondensedExtraLight.ttf \
		NotoSerifDevanagari-CondensedLight.ttf \
		NotoSerifDevanagari-CondensedMedium.ttf \
		NotoSerifDevanagari-CondensedSemiBold.ttf \
		NotoSerifDevanagari-CondensedThin.ttf \
		NotoSerifDevanagari-ExtraBold.ttf \
		NotoSerifDevanagari-ExtraCondensed.ttf \
		NotoSerifDevanagari-ExtraCondensedBlack.ttf \
		NotoSerifDevanagari-ExtraCondensedBold.ttf \
		NotoSerifDevanagari-ExtraCondensedExtraBold.ttf \
		NotoSerifDevanagari-ExtraCondensedExtraLight.ttf \
		NotoSerifDevanagari-ExtraCondensedLight.ttf \
		NotoSerifDevanagari-ExtraCondensedMedium.ttf \
		NotoSerifDevanagari-ExtraCondensedSemiBold.ttf \
		NotoSerifDevanagari-ExtraCondensedThin.ttf \
		NotoSerifDevanagari-ExtraLight.ttf \
		NotoSerifDevanagari-Light.ttf \
		NotoSerifDevanagari-Medium.ttf \
		NotoSerifDevanagari-Regular.ttf \
		NotoSerifDevanagari-SemiBold.ttf \
		NotoSerifDevanagari-SemiCondensed.ttf \
		NotoSerifDevanagari-SemiCondensedBlack.ttf \
		NotoSerifDevanagari-SemiCondensedBold.ttf \
		NotoSerifDevanagari-SemiCondensedExtraBold.ttf \
		NotoSerifDevanagari-SemiCondensedExtraLight.ttf \
		NotoSerifDevanagari-SemiCondensedLight.ttf \
		NotoSerifDevanagari-SemiCondensedMedium.ttf \
		NotoSerifDevanagari-SemiCondensedSemiBold.ttf \
		NotoSerifDevanagari-SemiCondensedThin.ttf \
		NotoSerifDevanagari-Thin.ttf

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${INSTALL_DATA} ${FONTS} ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
