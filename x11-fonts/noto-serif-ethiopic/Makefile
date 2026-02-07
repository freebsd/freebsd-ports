PORTNAME=	noto
PORTVERSION=	2.102
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/notofonts/notofonts.github.io/raw/noto-monthly-release-23.2.1/fonts/ \
		https://github.com/notofonts/notofonts.github.io/raw/noto-monthly-release-23.2.1/fonts/NotoSerifEthiopic/hinted/ttf/:fonts
PKGNAMESUFFIX=	-serif-ethiopic
DISTFILES=	LICENSE \
		${FONTS:S|$|:fonts|}
DIST_SUBDIR=	Noto/SerifEthiopic/${PORTVERSION}
EXTRACT_ONLY=	# empty

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Noto Serif Ethiopic
WWW=		https://fonts.google.com/noto \
		https://notofonts.github.io/ \
		https://github.com/notofonts/ethiopic \
		https://github.com/notofonts/notofonts.github.io/tree/main/fonts/NotoSerifEthiopic

LICENSE=	OFL11
LICENSE_FILE=	${DISTDIR}/${DIST_SUBDIR}/LICENSE

USES=		fonts

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

FONTS=		NotoSerifEthiopic-Black.ttf \
		NotoSerifEthiopic-Bold.ttf \
		NotoSerifEthiopic-Condensed.ttf \
		NotoSerifEthiopic-CondensedBlack.ttf \
		NotoSerifEthiopic-CondensedBold.ttf \
		NotoSerifEthiopic-CondensedExtraBold.ttf \
		NotoSerifEthiopic-CondensedExtraLight.ttf \
		NotoSerifEthiopic-CondensedLight.ttf \
		NotoSerifEthiopic-CondensedMedium.ttf \
		NotoSerifEthiopic-CondensedSemiBold.ttf \
		NotoSerifEthiopic-CondensedThin.ttf \
		NotoSerifEthiopic-ExtraBold.ttf \
		NotoSerifEthiopic-ExtraCondensed.ttf \
		NotoSerifEthiopic-ExtraCondensedBlack.ttf \
		NotoSerifEthiopic-ExtraCondensedBold.ttf \
		NotoSerifEthiopic-ExtraCondensedExtraBold.ttf \
		NotoSerifEthiopic-ExtraCondensedExtraLight.ttf \
		NotoSerifEthiopic-ExtraCondensedLight.ttf \
		NotoSerifEthiopic-ExtraCondensedMedium.ttf \
		NotoSerifEthiopic-ExtraCondensedSemiBold.ttf \
		NotoSerifEthiopic-ExtraCondensedThin.ttf \
		NotoSerifEthiopic-ExtraLight.ttf \
		NotoSerifEthiopic-Light.ttf \
		NotoSerifEthiopic-Medium.ttf \
		NotoSerifEthiopic-Regular.ttf \
		NotoSerifEthiopic-SemiBold.ttf \
		NotoSerifEthiopic-SemiCondensed.ttf \
		NotoSerifEthiopic-SemiCondensedBlack.ttf \
		NotoSerifEthiopic-SemiCondensedBold.ttf \
		NotoSerifEthiopic-SemiCondensedExtraBold.ttf \
		NotoSerifEthiopic-SemiCondensedExtraLight.ttf \
		NotoSerifEthiopic-SemiCondensedLight.ttf \
		NotoSerifEthiopic-SemiCondensedMedium.ttf \
		NotoSerifEthiopic-SemiCondensedSemiBold.ttf \
		NotoSerifEthiopic-SemiCondensedThin.ttf \
		NotoSerifEthiopic-Thin.ttf

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${INSTALL_DATA} ${FONTS} ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
