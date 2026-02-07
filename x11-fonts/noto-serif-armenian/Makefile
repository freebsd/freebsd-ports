PORTNAME=	noto
PORTVERSION=	2.008
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/notofonts/notofonts.github.io/raw/NotoSerifArmenian-v${PORTVERSION}/fonts/ \
		https://github.com/notofonts/notofonts.github.io/raw/NotoSerifArmenian-v${PORTVERSION}/fonts/NotoSerifArmenian/hinted/ttf/:fonts
PKGNAMESUFFIX=	-serif-armenian
DISTFILES=	LICENSE \
		${FONTS:S|$|:fonts|}
DIST_SUBDIR=	Noto/SerifArmenian/${PORTVERSION}
EXTRACT_ONLY=	# empty

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Noto Serif Armenian
WWW=		https://fonts.google.com/noto \
		https://notofonts.github.io/ \
		https://github.com/notofonts/armenian \
		https://github.com/notofonts/notofonts.github.io/tree/main/fonts/NotoSerifArmenian

LICENSE=	OFL11
LICENSE_FILE=	${DISTDIR}/${DIST_SUBDIR}/LICENSE

USES=		fonts

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

FONTS=		NotoSerifArmenian-Black.ttf \
		NotoSerifArmenian-Bold.ttf \
		NotoSerifArmenian-Condensed.ttf \
		NotoSerifArmenian-CondensedBlack.ttf \
		NotoSerifArmenian-CondensedBold.ttf \
		NotoSerifArmenian-CondensedExtraBold.ttf \
		NotoSerifArmenian-CondensedExtraLight.ttf \
		NotoSerifArmenian-CondensedLight.ttf \
		NotoSerifArmenian-CondensedMedium.ttf \
		NotoSerifArmenian-CondensedSemiBold.ttf \
		NotoSerifArmenian-CondensedThin.ttf \
		NotoSerifArmenian-ExtraBold.ttf \
		NotoSerifArmenian-ExtraCondensed.ttf \
		NotoSerifArmenian-ExtraCondensedBlack.ttf \
		NotoSerifArmenian-ExtraCondensedBold.ttf \
		NotoSerifArmenian-ExtraCondensedExtraBold.ttf \
		NotoSerifArmenian-ExtraCondensedExtraLight.ttf \
		NotoSerifArmenian-ExtraCondensedLight.ttf \
		NotoSerifArmenian-ExtraCondensedMedium.ttf \
		NotoSerifArmenian-ExtraCondensedSemiBold.ttf \
		NotoSerifArmenian-ExtraCondensedThin.ttf \
		NotoSerifArmenian-ExtraLight.ttf \
		NotoSerifArmenian-Light.ttf \
		NotoSerifArmenian-Medium.ttf \
		NotoSerifArmenian-Regular.ttf \
		NotoSerifArmenian-SemiBold.ttf \
		NotoSerifArmenian-SemiCondensed.ttf \
		NotoSerifArmenian-SemiCondensedBlack.ttf \
		NotoSerifArmenian-SemiCondensedBold.ttf \
		NotoSerifArmenian-SemiCondensedExtraBold.ttf \
		NotoSerifArmenian-SemiCondensedExtraLight.ttf \
		NotoSerifArmenian-SemiCondensedLight.ttf \
		NotoSerifArmenian-SemiCondensedMedium.ttf \
		NotoSerifArmenian-SemiCondensedSemiBold.ttf \
		NotoSerifArmenian-SemiCondensedThin.ttf \
		NotoSerifArmenian-Thin.ttf

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${INSTALL_DATA} ${FONTS} ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
