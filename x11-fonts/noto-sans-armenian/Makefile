PORTNAME=	noto
PORTVERSION=	2.008
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/notofonts/notofonts.github.io/raw/NotoSansArmenian-v${PORTVERSION}/fonts/ \
		https://github.com/notofonts/notofonts.github.io/raw/NotoSansArmenian-v${PORTVERSION}/fonts/NotoSansArmenian/hinted/ttf/:fonts
PKGNAMESUFFIX=	-sans-armenian
DISTFILES=	LICENSE \
		${FONTS:S|$|:fonts|}
DIST_SUBDIR=	Noto/SansArmenian/${PORTVERSION}
EXTRACT_ONLY=	# empty

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Noto Sans Armenian
WWW=		https://fonts.google.com/noto \
		https://notofonts.github.io/ \
		https://github.com/notofonts/armenian \
		https://github.com/notofonts/notofonts.github.io/tree/main/fonts/NotoSansArmenian

LICENSE=	OFL11
LICENSE_FILE=	${DISTDIR}/${DIST_SUBDIR}/LICENSE

USES=		fonts

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

FONTS=		NotoSansArmenian-Black.ttf \
		NotoSansArmenian-Bold.ttf \
		NotoSansArmenian-Condensed.ttf \
		NotoSansArmenian-CondensedBlack.ttf \
		NotoSansArmenian-CondensedBold.ttf \
		NotoSansArmenian-CondensedExtraBold.ttf \
		NotoSansArmenian-CondensedExtraLight.ttf \
		NotoSansArmenian-CondensedLight.ttf \
		NotoSansArmenian-CondensedMedium.ttf \
		NotoSansArmenian-CondensedSemiBold.ttf \
		NotoSansArmenian-CondensedThin.ttf \
		NotoSansArmenian-ExtraBold.ttf \
		NotoSansArmenian-ExtraCondensed.ttf \
		NotoSansArmenian-ExtraCondensedBlack.ttf \
		NotoSansArmenian-ExtraCondensedBold.ttf \
		NotoSansArmenian-ExtraCondensedExtraBold.ttf \
		NotoSansArmenian-ExtraCondensedExtraLight.ttf \
		NotoSansArmenian-ExtraCondensedLight.ttf \
		NotoSansArmenian-ExtraCondensedMedium.ttf \
		NotoSansArmenian-ExtraCondensedSemiBold.ttf \
		NotoSansArmenian-ExtraCondensedThin.ttf \
		NotoSansArmenian-ExtraLight.ttf \
		NotoSansArmenian-Light.ttf \
		NotoSansArmenian-Medium.ttf \
		NotoSansArmenian-Regular.ttf \
		NotoSansArmenian-SemiBold.ttf \
		NotoSansArmenian-SemiCondensed.ttf \
		NotoSansArmenian-SemiCondensedBlack.ttf \
		NotoSansArmenian-SemiCondensedBold.ttf \
		NotoSansArmenian-SemiCondensedExtraBold.ttf \
		NotoSansArmenian-SemiCondensedExtraLight.ttf \
		NotoSansArmenian-SemiCondensedLight.ttf \
		NotoSansArmenian-SemiCondensedMedium.ttf \
		NotoSansArmenian-SemiCondensedSemiBold.ttf \
		NotoSansArmenian-SemiCondensedThin.ttf \
		NotoSansArmenian-Thin.ttf

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${INSTALL_DATA} ${FONTS} ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
