PORTNAME=	noto
PORTVERSION=	2.004
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/notofonts/notofonts.github.io/raw/NotoSerifKhmer-v${PORTVERSION}/fonts/ \
		https://github.com/notofonts/notofonts.github.io/raw/NotoSerifKhmer-v${PORTVERSION}/fonts/NotoSerifKhmer/hinted/ttf/:fonts
PKGNAMESUFFIX=	-serif-khmer
DISTFILES=	LICENSE \
		${FONTS:S|$|:fonts|}
DIST_SUBDIR=	Noto/SerifKhmer/${PORTVERSION}
EXTRACT_ONLY=	# empty

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Noto Serif Khmer
WWW=		https://fonts.google.com/noto \
		https://notofonts.github.io/ \
		https://github.com/notofonts/khmer \
		https://github.com/notofonts/notofonts.github.io/tree/main/fonts/NotoSerifKhmer

LICENSE=	OFL11
LICENSE_FILE=	${DISTDIR}/${DIST_SUBDIR}/LICENSE

USES=		fonts

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

FONTS=		NotoSerifKhmer-Black.ttf \
		NotoSerifKhmer-Bold.ttf \
		NotoSerifKhmer-Condensed.ttf \
		NotoSerifKhmer-CondensedBlack.ttf \
		NotoSerifKhmer-CondensedBold.ttf \
		NotoSerifKhmer-CondensedExtraBold.ttf \
		NotoSerifKhmer-CondensedExtraLight.ttf \
		NotoSerifKhmer-CondensedLight.ttf \
		NotoSerifKhmer-CondensedMedium.ttf \
		NotoSerifKhmer-CondensedSemiBold.ttf \
		NotoSerifKhmer-CondensedThin.ttf \
		NotoSerifKhmer-ExtraBold.ttf \
		NotoSerifKhmer-ExtraCondensed.ttf \
		NotoSerifKhmer-ExtraCondensedBlack.ttf \
		NotoSerifKhmer-ExtraCondensedBold.ttf \
		NotoSerifKhmer-ExtraCondensedExtraBold.ttf \
		NotoSerifKhmer-ExtraCondensedExtraLight.ttf \
		NotoSerifKhmer-ExtraCondensedLight.ttf \
		NotoSerifKhmer-ExtraCondensedMedium.ttf \
		NotoSerifKhmer-ExtraCondensedSemiBold.ttf \
		NotoSerifKhmer-ExtraCondensedThin.ttf \
		NotoSerifKhmer-ExtraLight.ttf \
		NotoSerifKhmer-Light.ttf \
		NotoSerifKhmer-Medium.ttf \
		NotoSerifKhmer-Regular.ttf \
		NotoSerifKhmer-SemiBold.ttf \
		NotoSerifKhmer-SemiCondensed.ttf \
		NotoSerifKhmer-SemiCondensedBlack.ttf \
		NotoSerifKhmer-SemiCondensedBold.ttf \
		NotoSerifKhmer-SemiCondensedExtraBold.ttf \
		NotoSerifKhmer-SemiCondensedExtraLight.ttf \
		NotoSerifKhmer-SemiCondensedLight.ttf \
		NotoSerifKhmer-SemiCondensedMedium.ttf \
		NotoSerifKhmer-SemiCondensedSemiBold.ttf \
		NotoSerifKhmer-SemiCondensedThin.ttf \
		NotoSerifKhmer-Thin.ttf

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${INSTALL_DATA} ${FONTS} ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
