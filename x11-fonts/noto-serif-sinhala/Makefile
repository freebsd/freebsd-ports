PORTNAME=	noto
PORTVERSION=	2.007
CATEGORIES=	x11-fonts
#MASTER_SITES=	https://github.com/notofonts/notofonts.github.io/raw/NotoSerifSinhala-v${PORTVERSION}/fonts/ \
#		https://github.com/notofonts/notofonts.github.io/raw/NotoSerifSinhala-v${PORTVERSION}/fonts/NotoSerifSinhala/hinted/ttf/:fonts
MASTER_SITES=	https://github.com/notofonts/notofonts.github.io/raw/noto-monthly-release-23.4.1/fonts/ \
		https://github.com/notofonts/notofonts.github.io/raw/noto-monthly-release-23.4.1/fonts/NotoSerifSinhala/hinted/ttf/:fonts
PKGNAMESUFFIX=	-serif-sinhala
DISTFILES=	LICENSE \
		${FONTS:S|$|:fonts|}
DIST_SUBDIR=	Noto/SerifSinhala/${PORTVERSION}
EXTRACT_ONLY=	# empty

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Noto Serif Sinhala
WWW=		https://fonts.google.com/noto \
		https://notofonts.github.io/ \
		https://github.com/notofonts/sinhala \
		https://github.com/notofonts/notofonts.github.io/tree/main/fonts/NotoSerifSinhala

LICENSE=	OFL11
LICENSE_FILE=	${DISTDIR}/${DIST_SUBDIR}/LICENSE

USES=		fonts

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

FONTS=		NotoSerifSinhala-Black.ttf \
		NotoSerifSinhala-Bold.ttf \
		NotoSerifSinhala-Condensed.ttf \
		NotoSerifSinhala-CondensedBlack.ttf \
		NotoSerifSinhala-CondensedBold.ttf \
		NotoSerifSinhala-CondensedExtraBold.ttf \
		NotoSerifSinhala-CondensedExtraLight.ttf \
		NotoSerifSinhala-CondensedLight.ttf \
		NotoSerifSinhala-CondensedMedium.ttf \
		NotoSerifSinhala-CondensedSemiBold.ttf \
		NotoSerifSinhala-CondensedThin.ttf \
		NotoSerifSinhala-ExtraBold.ttf \
		NotoSerifSinhala-ExtraCondensed.ttf \
		NotoSerifSinhala-ExtraCondensedBlack.ttf \
		NotoSerifSinhala-ExtraCondensedBold.ttf \
		NotoSerifSinhala-ExtraCondensedExtraBold.ttf \
		NotoSerifSinhala-ExtraCondensedExtraLight.ttf \
		NotoSerifSinhala-ExtraCondensedLight.ttf \
		NotoSerifSinhala-ExtraCondensedMedium.ttf \
		NotoSerifSinhala-ExtraCondensedSemiBold.ttf \
		NotoSerifSinhala-ExtraCondensedThin.ttf \
		NotoSerifSinhala-ExtraLight.ttf \
		NotoSerifSinhala-Light.ttf \
		NotoSerifSinhala-Medium.ttf \
		NotoSerifSinhala-Regular.ttf \
		NotoSerifSinhala-SemiBold.ttf \
		NotoSerifSinhala-SemiCondensed.ttf \
		NotoSerifSinhala-SemiCondensedBlack.ttf \
		NotoSerifSinhala-SemiCondensedBold.ttf \
		NotoSerifSinhala-SemiCondensedExtraBold.ttf \
		NotoSerifSinhala-SemiCondensedExtraLight.ttf \
		NotoSerifSinhala-SemiCondensedLight.ttf \
		NotoSerifSinhala-SemiCondensedMedium.ttf \
		NotoSerifSinhala-SemiCondensedSemiBold.ttf \
		NotoSerifSinhala-SemiCondensedThin.ttf \
		NotoSerifSinhala-Thin.ttf

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${INSTALL_DATA} ${FONTS} ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
