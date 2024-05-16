PORTNAME=	noto
PORTVERSION=	2.002
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/notofonts/notofonts.github.io/raw/NotoSansThai-v${PORTVERSION}/fonts/ \
		https://github.com/notofonts/notofonts.github.io/raw/NotoSansThai-v${PORTVERSION}/fonts/NotoSansThai/hinted/ttf/:fonts
PKGNAMESUFFIX=	-sans-thai
DISTFILES=	LICENSE \
		${FONTS:S|$|:fonts|}
DIST_SUBDIR=	Noto/SansThai/${PORTVERSION}
EXTRACT_ONLY=	# empty

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Noto Sans Thai
WWW=		https://fonts.google.com/noto \
		https://notofonts.github.io/ \
		https://github.com/notofonts/thai \
		https://github.com/notofonts/notofonts.github.io/tree/main/fonts/NotoSansThai

LICENSE=	OFL11
LICENSE_FILE=	${DISTDIR}/${DIST_SUBDIR}/LICENSE

USES=		fonts

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

FONTS=		NotoSansThai-Black.ttf \
		NotoSansThai-Bold.ttf \
		NotoSansThai-Condensed.ttf \
		NotoSansThai-CondensedBlack.ttf \
		NotoSansThai-CondensedBold.ttf \
		NotoSansThai-CondensedExtraBold.ttf \
		NotoSansThai-CondensedExtraLight.ttf \
		NotoSansThai-CondensedLight.ttf \
		NotoSansThai-CondensedMedium.ttf \
		NotoSansThai-CondensedSemiBold.ttf \
		NotoSansThai-CondensedThin.ttf \
		NotoSansThai-ExtraBold.ttf \
		NotoSansThai-ExtraCondensed.ttf \
		NotoSansThai-ExtraCondensedBlack.ttf \
		NotoSansThai-ExtraCondensedBold.ttf \
		NotoSansThai-ExtraCondensedExtraBold.ttf \
		NotoSansThai-ExtraCondensedExtraLight.ttf \
		NotoSansThai-ExtraCondensedLight.ttf \
		NotoSansThai-ExtraCondensedMedium.ttf \
		NotoSansThai-ExtraCondensedSemiBold.ttf \
		NotoSansThai-ExtraCondensedThin.ttf \
		NotoSansThai-ExtraLight.ttf \
		NotoSansThai-Light.ttf \
		NotoSansThai-Medium.ttf \
		NotoSansThai-Regular.ttf \
		NotoSansThai-SemiBold.ttf \
		NotoSansThai-SemiCondensed.ttf \
		NotoSansThai-SemiCondensedBlack.ttf \
		NotoSansThai-SemiCondensedBold.ttf \
		NotoSansThai-SemiCondensedExtraBold.ttf \
		NotoSansThai-SemiCondensedExtraLight.ttf \
		NotoSansThai-SemiCondensedLight.ttf \
		NotoSansThai-SemiCondensedMedium.ttf \
		NotoSansThai-SemiCondensedSemiBold.ttf \
		NotoSansThai-SemiCondensedThin.ttf \
		NotoSansThai-Thin.ttf

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${INSTALL_DATA} ${FONTS} ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
