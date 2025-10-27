PORTNAME=	noto
PORTVERSION=	2.013
CATEGORIES=	x11-fonts
#MASTER_SITES=	https://github.com/notofonts/notofonts.github.io/raw/NotoSansArabic-v${PORTVERSION}/fonts/ \
#		https://github.com/notofonts/notofonts.github.io/raw/NotoSansArabic-v${PORTVERSION}/fonts/NotoSansArabic/hinted/ttf/:fonts
MASTER_SITES=	https://github.com/notofonts/notofonts.github.io/raw/40ff3d2422daeef927f4cebce11c1323e1d8e95b/fonts/ \
		https://github.com/notofonts/notofonts.github.io/raw/40ff3d2422daeef927f4cebce11c1323e1d8e95b/fonts/NotoSansArabic/hinted/ttf/:fonts
PKGNAMESUFFIX=	-sans-arabic
DISTFILES=	LICENSE \
		${FONTS:S|$|:fonts|}
DIST_SUBDIR=	Noto/SansArabic/${PORTVERSION}
EXTRACT_ONLY=	# empty

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Noto Sans Arabic
WWW=		https://fonts.google.com/noto \
		https://notofonts.github.io/ \
		https://github.com/notofonts/arabic \
		https://github.com/notofonts/notofonts.github.io/tree/main/fonts/NotoSansArabic

LICENSE=	OFL11
LICENSE_FILE=	${DISTDIR}/${DIST_SUBDIR}/LICENSE

USES=		fonts

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

FONTS=		NotoSansArabic-Black.ttf \
		NotoSansArabic-Bold.ttf \
		NotoSansArabic-Condensed.ttf \
		NotoSansArabic-CondensedBlack.ttf \
		NotoSansArabic-CondensedBold.ttf \
		NotoSansArabic-CondensedExtraBold.ttf \
		NotoSansArabic-CondensedExtraLight.ttf \
		NotoSansArabic-CondensedLight.ttf \
		NotoSansArabic-CondensedMedium.ttf \
		NotoSansArabic-CondensedSemiBold.ttf \
		NotoSansArabic-CondensedThin.ttf \
		NotoSansArabic-ExtraBold.ttf \
		NotoSansArabic-ExtraCondensed.ttf \
		NotoSansArabic-ExtraCondensedBlack.ttf \
		NotoSansArabic-ExtraCondensedBold.ttf \
		NotoSansArabic-ExtraCondensedExtraBold.ttf \
		NotoSansArabic-ExtraCondensedExtraLight.ttf \
		NotoSansArabic-ExtraCondensedLight.ttf \
		NotoSansArabic-ExtraCondensedMedium.ttf \
		NotoSansArabic-ExtraCondensedSemiBold.ttf \
		NotoSansArabic-ExtraCondensedThin.ttf \
		NotoSansArabic-ExtraLight.ttf \
		NotoSansArabic-Light.ttf \
		NotoSansArabic-Medium.ttf \
		NotoSansArabic-Regular.ttf \
		NotoSansArabic-SemiBold.ttf \
		NotoSansArabic-SemiCondensed.ttf \
		NotoSansArabic-SemiCondensedBlack.ttf \
		NotoSansArabic-SemiCondensedBold.ttf \
		NotoSansArabic-SemiCondensedExtraBold.ttf \
		NotoSansArabic-SemiCondensedExtraLight.ttf \
		NotoSansArabic-SemiCondensedLight.ttf \
		NotoSansArabic-SemiCondensedMedium.ttf \
		NotoSansArabic-SemiCondensedSemiBold.ttf \
		NotoSansArabic-SemiCondensedThin.ttf \
		NotoSansArabic-Thin.ttf

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${INSTALL_DATA} ${FONTS} ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
