PORTNAME=	noto
PORTVERSION=	2.004
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/notofonts/notofonts.github.io/raw/NotoSansKhmer-v${PORTVERSION}/fonts/ \
		https://github.com/notofonts/notofonts.github.io/raw/NotoSansKhmer-v${PORTVERSION}/fonts/NotoSansKhmer/hinted/ttf/:fonts
PKGNAMESUFFIX=	-sans-khmer
DISTFILES=	LICENSE \
		${FONTS:S|$|:fonts|}
DIST_SUBDIR=	Noto/SansKhmer/${PORTVERSION}
EXTRACT_ONLY=	# empty

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Noto Sans Khmer
WWW=		https://fonts.google.com/noto \
		https://notofonts.github.io/ \
		https://github.com/notofonts/khmer \
		https://github.com/notofonts/notofonts.github.io/tree/main/fonts/NotoSansKhmer

LICENSE=	OFL11
LICENSE_FILE=	${DISTDIR}/${DIST_SUBDIR}/LICENSE

USES=		fonts

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

FONTS=		NotoSansKhmer-Black.ttf \
		NotoSansKhmer-Bold.ttf \
		NotoSansKhmer-Condensed.ttf \
		NotoSansKhmer-CondensedBlack.ttf \
		NotoSansKhmer-CondensedBold.ttf \
		NotoSansKhmer-CondensedExtraBold.ttf \
		NotoSansKhmer-CondensedExtraLight.ttf \
		NotoSansKhmer-CondensedLight.ttf \
		NotoSansKhmer-CondensedMedium.ttf \
		NotoSansKhmer-CondensedSemiBold.ttf \
		NotoSansKhmer-CondensedThin.ttf \
		NotoSansKhmer-ExtraBold.ttf \
		NotoSansKhmer-ExtraCondensed.ttf \
		NotoSansKhmer-ExtraCondensedBlack.ttf \
		NotoSansKhmer-ExtraCondensedBold.ttf \
		NotoSansKhmer-ExtraCondensedExtraBold.ttf \
		NotoSansKhmer-ExtraCondensedExtraLight.ttf \
		NotoSansKhmer-ExtraCondensedLight.ttf \
		NotoSansKhmer-ExtraCondensedMedium.ttf \
		NotoSansKhmer-ExtraCondensedSemiBold.ttf \
		NotoSansKhmer-ExtraCondensedThin.ttf \
		NotoSansKhmer-ExtraLight.ttf \
		NotoSansKhmer-Light.ttf \
		NotoSansKhmer-Medium.ttf \
		NotoSansKhmer-Regular.ttf \
		NotoSansKhmer-SemiBold.ttf \
		NotoSansKhmer-SemiCondensed.ttf \
		NotoSansKhmer-SemiCondensedBlack.ttf \
		NotoSansKhmer-SemiCondensedBold.ttf \
		NotoSansKhmer-SemiCondensedExtraBold.ttf \
		NotoSansKhmer-SemiCondensedExtraLight.ttf \
		NotoSansKhmer-SemiCondensedLight.ttf \
		NotoSansKhmer-SemiCondensedMedium.ttf \
		NotoSansKhmer-SemiCondensedSemiBold.ttf \
		NotoSansKhmer-SemiCondensedThin.ttf \
		NotoSansKhmer-Thin.ttf

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${INSTALL_DATA} ${FONTS} ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
