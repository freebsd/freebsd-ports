PORTNAME=	noto
PORTVERSION=	3.000
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/notofonts/notofonts.github.io/raw/NotoSansSinhala-v${PORTVERSION}/fonts/ \
		https://github.com/notofonts/notofonts.github.io/raw/NotoSansSinhala-v${PORTVERSION}/fonts/NotoSansSinhala/hinted/ttf/:fonts
PKGNAMESUFFIX=	-sans-sinhala
DISTFILES=	LICENSE \
		${FONTS:S|$|:fonts|}
DIST_SUBDIR=	Noto/SansSinhala/${PORTVERSION}
EXTRACT_ONLY=	# empty

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Noto Sans Sinhala
WWW=		https://fonts.google.com/noto \
		https://notofonts.github.io/ \
		https://github.com/notofonts/sinhala \
		https://github.com/notofonts/notofonts.github.io/tree/main/fonts/NotoSansSinhala

LICENSE=	OFL11
LICENSE_FILE=	${DISTDIR}/${DIST_SUBDIR}/LICENSE

USES=		fonts

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

FONTS=		NotoSansSinhala-Black.ttf \
		NotoSansSinhala-Bold.ttf \
		NotoSansSinhala-Condensed.ttf \
		NotoSansSinhala-CondensedBlack.ttf \
		NotoSansSinhala-CondensedBold.ttf \
		NotoSansSinhala-CondensedExtraBold.ttf \
		NotoSansSinhala-CondensedExtraLight.ttf \
		NotoSansSinhala-CondensedLight.ttf \
		NotoSansSinhala-CondensedMedium.ttf \
		NotoSansSinhala-CondensedSemiBold.ttf \
		NotoSansSinhala-CondensedThin.ttf \
		NotoSansSinhala-ExtraBold.ttf \
		NotoSansSinhala-ExtraCondensed.ttf \
		NotoSansSinhala-ExtraCondensedBlack.ttf \
		NotoSansSinhala-ExtraCondensedBold.ttf \
		NotoSansSinhala-ExtraCondensedExtraBold.ttf \
		NotoSansSinhala-ExtraCondensedExtraLight.ttf \
		NotoSansSinhala-ExtraCondensedLight.ttf \
		NotoSansSinhala-ExtraCondensedMedium.ttf \
		NotoSansSinhala-ExtraCondensedSemiBold.ttf \
		NotoSansSinhala-ExtraCondensedThin.ttf \
		NotoSansSinhala-ExtraLight.ttf \
		NotoSansSinhala-Light.ttf \
		NotoSansSinhala-Medium.ttf \
		NotoSansSinhala-Regular.ttf \
		NotoSansSinhala-SemiBold.ttf \
		NotoSansSinhala-SemiCondensed.ttf \
		NotoSansSinhala-SemiCondensedBlack.ttf \
		NotoSansSinhala-SemiCondensedBold.ttf \
		NotoSansSinhala-SemiCondensedExtraBold.ttf \
		NotoSansSinhala-SemiCondensedExtraLight.ttf \
		NotoSansSinhala-SemiCondensedLight.ttf \
		NotoSansSinhala-SemiCondensedMedium.ttf \
		NotoSansSinhala-SemiCondensedSemiBold.ttf \
		NotoSansSinhala-SemiCondensedThin.ttf \
		NotoSansSinhala-Thin.ttf \
		NotoSansSinhalaUI-Black.ttf \
		NotoSansSinhalaUI-Bold.ttf \
		NotoSansSinhalaUI-Condensed.ttf \
		NotoSansSinhalaUI-CondensedBlack.ttf \
		NotoSansSinhalaUI-CondensedBold.ttf \
		NotoSansSinhalaUI-CondensedExtraBold.ttf \
		NotoSansSinhalaUI-CondensedExtraLight.ttf \
		NotoSansSinhalaUI-CondensedLight.ttf \
		NotoSansSinhalaUI-CondensedMedium.ttf \
		NotoSansSinhalaUI-CondensedSemiBold.ttf \
		NotoSansSinhalaUI-CondensedThin.ttf \
		NotoSansSinhalaUI-ExtraBold.ttf \
		NotoSansSinhalaUI-ExtraCondensed.ttf \
		NotoSansSinhalaUI-ExtraCondensedBlack.ttf \
		NotoSansSinhalaUI-ExtraCondensedBold.ttf \
		NotoSansSinhalaUI-ExtraCondensedExtraBold.ttf \
		NotoSansSinhalaUI-ExtraCondensedExtraLight.ttf \
		NotoSansSinhalaUI-ExtraCondensedLight.ttf \
		NotoSansSinhalaUI-ExtraCondensedMedium.ttf \
		NotoSansSinhalaUI-ExtraCondensedSemiBold.ttf \
		NotoSansSinhalaUI-ExtraCondensedThin.ttf \
		NotoSansSinhalaUI-ExtraLight.ttf \
		NotoSansSinhalaUI-Light.ttf \
		NotoSansSinhalaUI-Medium.ttf \
		NotoSansSinhalaUI-Regular.ttf \
		NotoSansSinhalaUI-SemiBold.ttf \
		NotoSansSinhalaUI-SemiCondensed.ttf \
		NotoSansSinhalaUI-SemiCondensedBlack.ttf \
		NotoSansSinhalaUI-SemiCondensedBold.ttf \
		NotoSansSinhalaUI-SemiCondensedExtraBold.ttf \
		NotoSansSinhalaUI-SemiCondensedExtraLight.ttf \
		NotoSansSinhalaUI-SemiCondensedLight.ttf \
		NotoSansSinhalaUI-SemiCondensedMedium.ttf \
		NotoSansSinhalaUI-SemiCondensedSemiBold.ttf \
		NotoSansSinhalaUI-SemiCondensedThin.ttf \
		NotoSansSinhalaUI-Thin.ttf

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${INSTALL_DATA} ${FONTS} ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
