PORTNAME=	noto
PORTVERSION=	3.000
CATEGORIES=	x11-fonts
#MASTER_SITES=	https://github.com/notofonts/notofonts.github.io/raw/NotoSerifBengali-v${PORTVERSION}/fonts/ \
#		https://github.com/notofonts/notofonts.github.io/raw/NotoSerifBengali-v${PORTVERSION}/fonts/NotoSerifBengali/hinted/ttf/:fonts
MASTER_SITES=	https://github.com/notofonts/notofonts.github.io/raw/noto-monthly-release-23.12.1/fonts/ \
		https://github.com/notofonts/notofonts.github.io/raw/noto-monthly-release-23.12.1/fonts/NotoSerifBengali/hinted/ttf/:fonts
PKGNAMESUFFIX=	-serif-bengali
DISTFILES=	LICENSE \
		${FONTS:S|$|:fonts|}
DIST_SUBDIR=	Noto/SerifBengali/${PORTVERSION}
EXTRACT_ONLY=	# empty

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Noto Serif Bengali
WWW=		https://fonts.google.com/noto \
		https://notofonts.github.io/ \
		https://github.com/notofonts/bengali \
		https://github.com/notofonts/notofonts.github.io/tree/main/fonts/NotoSerifBengali

LICENSE=	OFL11
LICENSE_FILE=	${DISTDIR}/${DIST_SUBDIR}/LICENSE

USES=		fonts

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

FONTS=		NotoSerifBengali-Black.ttf \
		NotoSerifBengali-Bold.ttf \
		NotoSerifBengali-Condensed.ttf \
		NotoSerifBengali-CondensedBlack.ttf \
		NotoSerifBengali-CondensedBold.ttf \
		NotoSerifBengali-CondensedExtraBold.ttf \
		NotoSerifBengali-CondensedExtraLight.ttf \
		NotoSerifBengali-CondensedLight.ttf \
		NotoSerifBengali-CondensedMedium.ttf \
		NotoSerifBengali-CondensedSemiBold.ttf \
		NotoSerifBengali-CondensedThin.ttf \
		NotoSerifBengali-ExtraBold.ttf \
		NotoSerifBengali-ExtraCondensed.ttf \
		NotoSerifBengali-ExtraCondensedBlack.ttf \
		NotoSerifBengali-ExtraCondensedBold.ttf \
		NotoSerifBengali-ExtraCondensedExtraBold.ttf \
		NotoSerifBengali-ExtraCondensedExtraLight.ttf \
		NotoSerifBengali-ExtraCondensedLight.ttf \
		NotoSerifBengali-ExtraCondensedMedium.ttf \
		NotoSerifBengali-ExtraCondensedSemiBold.ttf \
		NotoSerifBengali-ExtraCondensedThin.ttf \
		NotoSerifBengali-ExtraLight.ttf \
		NotoSerifBengali-Light.ttf \
		NotoSerifBengali-Medium.ttf \
		NotoSerifBengali-Regular.ttf \
		NotoSerifBengali-SemiBold.ttf \
		NotoSerifBengali-SemiCondensed.ttf \
		NotoSerifBengali-SemiCondensedBlack.ttf \
		NotoSerifBengali-SemiCondensedBold.ttf \
		NotoSerifBengali-SemiCondensedExtraBold.ttf \
		NotoSerifBengali-SemiCondensedExtraLight.ttf \
		NotoSerifBengali-SemiCondensedLight.ttf \
		NotoSerifBengali-SemiCondensedMedium.ttf \
		NotoSerifBengali-SemiCondensedSemiBold.ttf \
		NotoSerifBengali-SemiCondensedThin.ttf \
		NotoSerifBengali-Thin.ttf

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${INSTALL_DATA} ${FONTS} ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
