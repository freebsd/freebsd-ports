PORTNAME=	noto
PORTVERSION=	2.107
CATEGORIES=	x11-fonts
#MASTER_SITES=	https://github.com/notofonts/notofonts.github.io/raw/NotoSansMyanmar-v${PORTVERSION}/fonts/ \
#		https://github.com/notofonts/notofonts.github.io/raw/NotoSansMyanmar-v${PORTVERSION}/fonts/NotoSansMyanmar/hinted/ttf/:fonts
MASTER_SITES=	https://github.com/notofonts/notofonts.github.io/raw/noto-monthly-release-23.2.1/fonts/ \
		https://github.com/notofonts/notofonts.github.io/raw/noto-monthly-release-23.2.1/fonts/NotoSansMyanmar/hinted/ttf/:fonts
PKGNAMESUFFIX=	-sans-myanmar
DISTFILES=	LICENSE \
		${FONTS:S|$|:fonts|}
DIST_SUBDIR=	Noto/SansMyanmar/${PORTVERSION}
EXTRACT_ONLY=	# empty

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Noto Sans Myanmar
WWW=		https://fonts.google.com/noto \
		https://notofonts.github.io/ \
		https://github.com/notofonts/myanmar \
		https://github.com/notofonts/notofonts.github.io/tree/main/fonts/NotoSansMyanmar

LICENSE=	OFL11
LICENSE_FILE=	${DISTDIR}/${DIST_SUBDIR}/LICENSE

USES=		fonts

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

FONTS=		NotoSansMyanmar-Black.ttf \
		NotoSansMyanmar-Bold.ttf \
		NotoSansMyanmar-Condensed.ttf \
		NotoSansMyanmar-CondensedBlack.ttf \
		NotoSansMyanmar-CondensedBold.ttf \
		NotoSansMyanmar-CondensedExtraBold.ttf \
		NotoSansMyanmar-CondensedExtraLight.ttf \
		NotoSansMyanmar-CondensedLight.ttf \
		NotoSansMyanmar-CondensedMedium.ttf \
		NotoSansMyanmar-CondensedSemiBold.ttf \
		NotoSansMyanmar-CondensedThin.ttf \
		NotoSansMyanmar-ExtraBold.ttf \
		NotoSansMyanmar-ExtraCondensed.ttf \
		NotoSansMyanmar-ExtraCondensedBlack.ttf \
		NotoSansMyanmar-ExtraCondensedBold.ttf \
		NotoSansMyanmar-ExtraCondensedExtraBold.ttf \
		NotoSansMyanmar-ExtraCondensedExtraLight.ttf \
		NotoSansMyanmar-ExtraCondensedLight.ttf \
		NotoSansMyanmar-ExtraCondensedMedium.ttf \
		NotoSansMyanmar-ExtraCondensedSemiBold.ttf \
		NotoSansMyanmar-ExtraCondensedThin.ttf \
		NotoSansMyanmar-ExtraLight.ttf \
		NotoSansMyanmar-Light.ttf \
		NotoSansMyanmar-Medium.ttf \
		NotoSansMyanmar-Regular.ttf \
		NotoSansMyanmar-SemiBold.ttf \
		NotoSansMyanmar-SemiCondensed.ttf \
		NotoSansMyanmar-SemiCondensedBlack.ttf \
		NotoSansMyanmar-SemiCondensedBold.ttf \
		NotoSansMyanmar-SemiCondensedExtraBold.ttf \
		NotoSansMyanmar-SemiCondensedExtraLight.ttf \
		NotoSansMyanmar-SemiCondensedLight.ttf \
		NotoSansMyanmar-SemiCondensedMedium.ttf \
		NotoSansMyanmar-SemiCondensedSemiBold.ttf \
		NotoSansMyanmar-SemiCondensedThin.ttf \
		NotoSansMyanmar-Thin.ttf

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${INSTALL_DATA} ${FONTS} ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
