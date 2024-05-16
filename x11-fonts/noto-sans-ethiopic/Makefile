PORTNAME=	noto
PORTVERSION=	2.102
CATEGORIES=	x11-fonts
#MASTER_SITES=	https://github.com/notofonts/notofonts.github.io/raw/NotoSansEthiopic-v${PORTVERSION}/fonts/ \
#		https://github.com/notofonts/notofonts.github.io/raw/NotoSansEthiopic-v${PORTVERSION}/fonts/NotoSansEthiopic/hinted/ttf/:fonts
MASTER_SITES=	https://github.com/notofonts/notofonts.github.io/raw/noto-monthly-release-23.2.1/fonts/ \
		https://github.com/notofonts/notofonts.github.io/raw/noto-monthly-release-23.2.1/fonts/NotoSansEthiopic/hinted/ttf/:fonts
PKGNAMESUFFIX=	-sans-ethiopic
DISTFILES=	LICENSE \
		${FONTS:S|$|:fonts|}
DIST_SUBDIR=	Noto/SansEthiopic/${PORTVERSION}
EXTRACT_ONLY=	# empty

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Noto Sans Ethiopic
WWW=		https://fonts.google.com/noto \
		https://notofonts.github.io/ \
		https://github.com/notofonts/ethiopic \
		https://github.com/notofonts/notofonts.github.io/tree/main/fonts/NotoSansEthiopic

LICENSE=	OFL11
LICENSE_FILE=	${DISTDIR}/${DIST_SUBDIR}/LICENSE

USES=		fonts

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

FONTS=		NotoSansEthiopic-Black.ttf \
		NotoSansEthiopic-Bold.ttf \
		NotoSansEthiopic-Condensed.ttf \
		NotoSansEthiopic-CondensedBlack.ttf \
		NotoSansEthiopic-CondensedBold.ttf \
		NotoSansEthiopic-CondensedExtraBold.ttf \
		NotoSansEthiopic-CondensedExtraLight.ttf \
		NotoSansEthiopic-CondensedLight.ttf \
		NotoSansEthiopic-CondensedMedium.ttf \
		NotoSansEthiopic-CondensedSemiBold.ttf \
		NotoSansEthiopic-CondensedThin.ttf \
		NotoSansEthiopic-ExtraBold.ttf \
		NotoSansEthiopic-ExtraCondensed.ttf \
		NotoSansEthiopic-ExtraCondensedBlack.ttf \
		NotoSansEthiopic-ExtraCondensedBold.ttf \
		NotoSansEthiopic-ExtraCondensedExtraBold.ttf \
		NotoSansEthiopic-ExtraCondensedExtraLight.ttf \
		NotoSansEthiopic-ExtraCondensedLight.ttf \
		NotoSansEthiopic-ExtraCondensedMedium.ttf \
		NotoSansEthiopic-ExtraCondensedSemiBold.ttf \
		NotoSansEthiopic-ExtraCondensedThin.ttf \
		NotoSansEthiopic-ExtraLight.ttf \
		NotoSansEthiopic-Light.ttf \
		NotoSansEthiopic-Medium.ttf \
		NotoSansEthiopic-Regular.ttf \
		NotoSansEthiopic-SemiBold.ttf \
		NotoSansEthiopic-SemiCondensed.ttf \
		NotoSansEthiopic-SemiCondensedBlack.ttf \
		NotoSansEthiopic-SemiCondensedBold.ttf \
		NotoSansEthiopic-SemiCondensedExtraBold.ttf \
		NotoSansEthiopic-SemiCondensedExtraLight.ttf \
		NotoSansEthiopic-SemiCondensedLight.ttf \
		NotoSansEthiopic-SemiCondensedMedium.ttf \
		NotoSansEthiopic-SemiCondensedSemiBold.ttf \
		NotoSansEthiopic-SemiCondensedThin.ttf \
		NotoSansEthiopic-Thin.ttf

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${INSTALL_DATA} ${FONTS} ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
