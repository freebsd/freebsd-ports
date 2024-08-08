PORTNAME=	noto
PORTVERSION=	2.005
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/notofonts/notofonts.github.io/raw/NotoSansKannada-v${PORTVERSION}/fonts/ \
		https://github.com/notofonts/notofonts.github.io/raw/NotoSansKannada-v${PORTVERSION}/fonts/NotoSansKannada/hinted/ttf/:fonts
PKGNAMESUFFIX=	-sans-kannada
DISTFILES=	LICENSE \
		${FONTS:S|$|:fonts|}
DIST_SUBDIR=	Noto/SansKannada/${PORTVERSION}
EXTRACT_ONLY=	# empty

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Noto Sans Kannada
WWW=		https://fonts.google.com/noto \
		https://notofonts.github.io/ \
		https://github.com/notofonts/kannada \
		https://github.com/notofonts/notofonts.github.io/tree/main/fonts/NotoSansKannada

LICENSE=	OFL11
LICENSE_FILE=	${DISTDIR}/${DIST_SUBDIR}/LICENSE

USES=		fonts

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

FONTS=		NotoSansKannada-Black.ttf \
		NotoSansKannada-Bold.ttf \
		NotoSansKannada-Condensed.ttf \
		NotoSansKannada-CondensedBlack.ttf \
		NotoSansKannada-CondensedBold.ttf \
		NotoSansKannada-CondensedExtraBold.ttf \
		NotoSansKannada-CondensedExtraLight.ttf \
		NotoSansKannada-CondensedLight.ttf \
		NotoSansKannada-CondensedMedium.ttf \
		NotoSansKannada-CondensedSemiBold.ttf \
		NotoSansKannada-CondensedThin.ttf \
		NotoSansKannada-ExtraBold.ttf \
		NotoSansKannada-ExtraCondensed.ttf \
		NotoSansKannada-ExtraCondensedBlack.ttf \
		NotoSansKannada-ExtraCondensedBold.ttf \
		NotoSansKannada-ExtraCondensedExtraBold.ttf \
		NotoSansKannada-ExtraCondensedExtraLight.ttf \
		NotoSansKannada-ExtraCondensedLight.ttf \
		NotoSansKannada-ExtraCondensedMedium.ttf \
		NotoSansKannada-ExtraCondensedSemiBold.ttf \
		NotoSansKannada-ExtraCondensedThin.ttf \
		NotoSansKannada-ExtraLight.ttf \
		NotoSansKannada-Light.ttf \
		NotoSansKannada-Medium.ttf \
		NotoSansKannada-Regular.ttf \
		NotoSansKannada-SemiBold.ttf \
		NotoSansKannada-SemiCondensed.ttf \
		NotoSansKannada-SemiCondensedBlack.ttf \
		NotoSansKannada-SemiCondensedBold.ttf \
		NotoSansKannada-SemiCondensedExtraBold.ttf \
		NotoSansKannada-SemiCondensedExtraLight.ttf \
		NotoSansKannada-SemiCondensedLight.ttf \
		NotoSansKannada-SemiCondensedMedium.ttf \
		NotoSansKannada-SemiCondensedSemiBold.ttf \
		NotoSansKannada-SemiCondensedThin.ttf \
		NotoSansKannada-Thin.ttf

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${INSTALL_DATA} ${FONTS} ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
