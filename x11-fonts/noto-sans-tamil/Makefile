PORTNAME=	noto
PORTVERSION=	2.004
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/notofonts/notofonts.github.io/raw/NotoSansTamil-v${PORTVERSION}/fonts/ \
		https://github.com/notofonts/notofonts.github.io/raw/NotoSansTamil-v${PORTVERSION}/fonts/NotoSansTamil/hinted/ttf/:fonts
PKGNAMESUFFIX=	-sans-tamil
DISTFILES=	LICENSE \
		${FONTS:S|$|:fonts|}
DIST_SUBDIR=	Noto/SansTamil/${PORTVERSION}
EXTRACT_ONLY=	# empty

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Noto Sans Tamil
WWW=		https://fonts.google.com/noto \
		https://notofonts.github.io/ \
		https://github.com/notofonts/tamil \
		https://github.com/notofonts/notofonts.github.io/tree/main/fonts/NotoSansTamil

LICENSE=	OFL11
LICENSE_FILE=	${DISTDIR}/${DIST_SUBDIR}/LICENSE

USES=		fonts

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

FONTS=		NotoSansTamil-Black.ttf \
		NotoSansTamil-Bold.ttf \
		NotoSansTamil-Condensed.ttf \
		NotoSansTamil-CondensedBlack.ttf \
		NotoSansTamil-CondensedBold.ttf \
		NotoSansTamil-CondensedExtraBold.ttf \
		NotoSansTamil-CondensedExtraLight.ttf \
		NotoSansTamil-CondensedLight.ttf \
		NotoSansTamil-CondensedMedium.ttf \
		NotoSansTamil-CondensedSemiBold.ttf \
		NotoSansTamil-CondensedThin.ttf \
		NotoSansTamil-ExtraBold.ttf \
		NotoSansTamil-ExtraCondensed.ttf \
		NotoSansTamil-ExtraCondensedBlack.ttf \
		NotoSansTamil-ExtraCondensedBold.ttf \
		NotoSansTamil-ExtraCondensedExtraBold.ttf \
		NotoSansTamil-ExtraCondensedExtraLight.ttf \
		NotoSansTamil-ExtraCondensedLight.ttf \
		NotoSansTamil-ExtraCondensedMedium.ttf \
		NotoSansTamil-ExtraCondensedSemiBold.ttf \
		NotoSansTamil-ExtraCondensedThin.ttf \
		NotoSansTamil-ExtraLight.ttf \
		NotoSansTamil-Light.ttf \
		NotoSansTamil-Medium.ttf \
		NotoSansTamil-Regular.ttf \
		NotoSansTamil-SemiBold.ttf \
		NotoSansTamil-SemiCondensed.ttf \
		NotoSansTamil-SemiCondensedBlack.ttf \
		NotoSansTamil-SemiCondensedBold.ttf \
		NotoSansTamil-SemiCondensedExtraBold.ttf \
		NotoSansTamil-SemiCondensedExtraLight.ttf \
		NotoSansTamil-SemiCondensedLight.ttf \
		NotoSansTamil-SemiCondensedMedium.ttf \
		NotoSansTamil-SemiCondensedSemiBold.ttf \
		NotoSansTamil-SemiCondensedThin.ttf \
		NotoSansTamil-Thin.ttf \
		NotoSansTamilUI-Black.ttf \
		NotoSansTamilUI-Bold.ttf \
		NotoSansTamilUI-Condensed.ttf \
		NotoSansTamilUI-CondensedBlack.ttf \
		NotoSansTamilUI-CondensedBold.ttf \
		NotoSansTamilUI-CondensedExtraBold.ttf \
		NotoSansTamilUI-CondensedExtraLight.ttf \
		NotoSansTamilUI-CondensedLight.ttf \
		NotoSansTamilUI-CondensedMedium.ttf \
		NotoSansTamilUI-CondensedSemiBold.ttf \
		NotoSansTamilUI-CondensedThin.ttf \
		NotoSansTamilUI-ExtraBold.ttf \
		NotoSansTamilUI-ExtraCondensed.ttf \
		NotoSansTamilUI-ExtraCondensedBlack.ttf \
		NotoSansTamilUI-ExtraCondensedBold.ttf \
		NotoSansTamilUI-ExtraCondensedExtraBold.ttf \
		NotoSansTamilUI-ExtraCondensedExtraLight.ttf \
		NotoSansTamilUI-ExtraCondensedLight.ttf \
		NotoSansTamilUI-ExtraCondensedMedium.ttf \
		NotoSansTamilUI-ExtraCondensedSemiBold.ttf \
		NotoSansTamilUI-ExtraCondensedThin.ttf \
		NotoSansTamilUI-ExtraLight.ttf \
		NotoSansTamilUI-Light.ttf \
		NotoSansTamilUI-Medium.ttf \
		NotoSansTamilUI-Regular.ttf \
		NotoSansTamilUI-SemiBold.ttf \
		NotoSansTamilUI-SemiCondensed.ttf \
		NotoSansTamilUI-SemiCondensedBlack.ttf \
		NotoSansTamilUI-SemiCondensedBold.ttf \
		NotoSansTamilUI-SemiCondensedExtraBold.ttf \
		NotoSansTamilUI-SemiCondensedExtraLight.ttf \
		NotoSansTamilUI-SemiCondensedLight.ttf \
		NotoSansTamilUI-SemiCondensedMedium.ttf \
		NotoSansTamilUI-SemiCondensedSemiBold.ttf \
		NotoSansTamilUI-SemiCondensedThin.ttf \
		NotoSansTamilUI-Thin.ttf

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${INSTALL_DATA} ${FONTS} ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
