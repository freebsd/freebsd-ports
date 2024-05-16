PORTNAME=	noto
PORTVERSION=	2.106
CATEGORIES=	x11-fonts
#MASTER_SITES=	https://github.com/notofonts/notofonts.github.io/raw/NotoSerifMyanmar-v${PORTVERSION}/fonts/ \
#		https://github.com/notofonts/notofonts.github.io/raw/NotoSerifMyanmar-v${PORTVERSION}/fonts/NotoSerifMyanmar/hinted/ttf/:fonts
MASTER_SITES=	https://github.com/notofonts/notofonts.github.io/raw/noto-monthly-release-23.2.1/fonts/ \
		https://github.com/notofonts/notofonts.github.io/raw/noto-monthly-release-23.2.1/fonts/NotoSerifMyanmar/hinted/ttf/:fonts
PKGNAMESUFFIX=	-serif-myanmar
DISTFILES=	LICENSE \
		${FONTS:S|$|:fonts|}
DIST_SUBDIR=	Noto/SerifMyanmar/${PORTVERSION}
EXTRACT_ONLY=	# empty

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Noto Serif Myanmar
WWW=		https://fonts.google.com/noto \
		https://notofonts.github.io/ \
		https://github.com/notofonts/myanmar \
		https://github.com/notofonts/notofonts.github.io/tree/main/fonts/NotoSerifMyanmar

LICENSE=	OFL11
LICENSE_FILE=	${DISTDIR}/${DIST_SUBDIR}/LICENSE

USES=		fonts

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

FONTS=		NotoSerifMyanmar-Black.ttf \
		NotoSerifMyanmar-Bold.ttf \
		NotoSerifMyanmar-Condensed.ttf \
		NotoSerifMyanmar-CondensedBlack.ttf \
		NotoSerifMyanmar-CondensedBold.ttf \
		NotoSerifMyanmar-CondensedExtraBold.ttf \
		NotoSerifMyanmar-CondensedExtraLight.ttf \
		NotoSerifMyanmar-CondensedLight.ttf \
		NotoSerifMyanmar-CondensedMedium.ttf \
		NotoSerifMyanmar-CondensedSemiBold.ttf \
		NotoSerifMyanmar-CondensedThin.ttf \
		NotoSerifMyanmar-ExtraBold.ttf \
		NotoSerifMyanmar-ExtraCondensed.ttf \
		NotoSerifMyanmar-ExtraCondensedBlack.ttf \
		NotoSerifMyanmar-ExtraCondensedBold.ttf \
		NotoSerifMyanmar-ExtraCondensedExtraBold.ttf \
		NotoSerifMyanmar-ExtraCondensedExtraLight.ttf \
		NotoSerifMyanmar-ExtraCondensedLight.ttf \
		NotoSerifMyanmar-ExtraCondensedMedium.ttf \
		NotoSerifMyanmar-ExtraCondensedSemiBold.ttf \
		NotoSerifMyanmar-ExtraCondensedThin.ttf \
		NotoSerifMyanmar-ExtraLight.ttf \
		NotoSerifMyanmar-Light.ttf \
		NotoSerifMyanmar-Medium.ttf \
		NotoSerifMyanmar-Regular.ttf \
		NotoSerifMyanmar-SemiBold.ttf \
		NotoSerifMyanmar-SemiCondensed.ttf \
		NotoSerifMyanmar-SemiCondensedBlack.ttf \
		NotoSerifMyanmar-SemiCondensedBold.ttf \
		NotoSerifMyanmar-SemiCondensedExtraBold.ttf \
		NotoSerifMyanmar-SemiCondensedExtraLight.ttf \
		NotoSerifMyanmar-SemiCondensedLight.ttf \
		NotoSerifMyanmar-SemiCondensedMedium.ttf \
		NotoSerifMyanmar-SemiCondensedSemiBold.ttf \
		NotoSerifMyanmar-SemiCondensedThin.ttf \
		NotoSerifMyanmar-Thin.ttf

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${INSTALL_DATA} ${FONTS} ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
