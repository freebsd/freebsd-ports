PORTNAME=	noto
PORTVERSION=	2.004
CATEGORIES=	x11-fonts
#MASTER_SITES=	https://github.com/notofonts/notofonts.github.io/raw/NotoSerifHebrew-v${PORTVERSION}/fonts/ \
#		https://github.com/notofonts/notofonts.github.io/raw/NotoSerifHebrew-v${PORTVERSION}/fonts/NotoSerifHebrew/hinted/ttf/:fonts
MASTER_SITES=	https://github.com/notofonts/notofonts.github.io/raw/noto-monthly-release-23.2.1/fonts/ \
		https://github.com/notofonts/notofonts.github.io/raw/noto-monthly-release-23.2.1/fonts/NotoSerifHebrew/hinted/ttf/:fonts
PKGNAMESUFFIX=	-serif-hebrew
DISTFILES=	LICENSE \
		${FONTS:S|$|:fonts|}
DIST_SUBDIR=	Noto/SerifHebrew/${PORTVERSION}
EXTRACT_ONLY=	# empty

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Noto Serif Hebrew
WWW=		https://fonts.google.com/noto \
		https://notofonts.github.io/ \
		https://github.com/notofonts/hebrew \
		https://github.com/notofonts/notofonts.github.io/tree/main/fonts/NotoSerifHebrew

LICENSE=	OFL11
LICENSE_FILE=	${DISTDIR}/${DIST_SUBDIR}/LICENSE

USES=		fonts

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

FONTS=		NotoSerifHebrew-Black.ttf \
		NotoSerifHebrew-Bold.ttf \
		NotoSerifHebrew-Condensed.ttf \
		NotoSerifHebrew-CondensedBlack.ttf \
		NotoSerifHebrew-CondensedBold.ttf \
		NotoSerifHebrew-CondensedExtraBold.ttf \
		NotoSerifHebrew-CondensedExtraLight.ttf \
		NotoSerifHebrew-CondensedLight.ttf \
		NotoSerifHebrew-CondensedMedium.ttf \
		NotoSerifHebrew-CondensedSemiBold.ttf \
		NotoSerifHebrew-CondensedThin.ttf \
		NotoSerifHebrew-ExtraBold.ttf \
		NotoSerifHebrew-ExtraCondensed.ttf \
		NotoSerifHebrew-ExtraCondensedBlack.ttf \
		NotoSerifHebrew-ExtraCondensedBold.ttf \
		NotoSerifHebrew-ExtraCondensedExtraBold.ttf \
		NotoSerifHebrew-ExtraCondensedExtraLight.ttf \
		NotoSerifHebrew-ExtraCondensedLight.ttf \
		NotoSerifHebrew-ExtraCondensedMedium.ttf \
		NotoSerifHebrew-ExtraCondensedSemiBold.ttf \
		NotoSerifHebrew-ExtraCondensedThin.ttf \
		NotoSerifHebrew-ExtraLight.ttf \
		NotoSerifHebrew-Light.ttf \
		NotoSerifHebrew-Medium.ttf \
		NotoSerifHebrew-Regular.ttf \
		NotoSerifHebrew-SemiBold.ttf \
		NotoSerifHebrew-SemiCondensed.ttf \
		NotoSerifHebrew-SemiCondensedBlack.ttf \
		NotoSerifHebrew-SemiCondensedBold.ttf \
		NotoSerifHebrew-SemiCondensedExtraBold.ttf \
		NotoSerifHebrew-SemiCondensedExtraLight.ttf \
		NotoSerifHebrew-SemiCondensedLight.ttf \
		NotoSerifHebrew-SemiCondensedMedium.ttf \
		NotoSerifHebrew-SemiCondensedSemiBold.ttf \
		NotoSerifHebrew-SemiCondensedThin.ttf \
		NotoSerifHebrew-Thin.ttf

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${INSTALL_DATA} ${FONTS} ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
