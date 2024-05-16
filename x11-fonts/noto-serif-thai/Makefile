PORTNAME=	noto
PORTVERSION=	2.002
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/notofonts/notofonts.github.io/raw/NotoSerifThai-v${PORTVERSION}/fonts/ \
		https://github.com/notofonts/notofonts.github.io/raw/NotoSerifThai-v${PORTVERSION}/fonts/NotoSerifThai/hinted/ttf/:fonts
PKGNAMESUFFIX=	-serif-thai
DISTFILES=	LICENSE \
		${FONTS:S|$|:fonts|}
DIST_SUBDIR=	Noto/SerifThai/${PORTVERSION}
EXTRACT_ONLY=	# empty

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Noto Serif Thai
WWW=		https://fonts.google.com/noto \
		https://notofonts.github.io/ \
		https://github.com/notofonts/thai \
		https://github.com/notofonts/notofonts.github.io/tree/main/fonts/NotoSerifThai

LICENSE=	OFL11
LICENSE_FILE=	${DISTDIR}/${DIST_SUBDIR}/LICENSE

USES=		fonts

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

FONTS=		NotoSerifThai-Black.ttf \
		NotoSerifThai-Bold.ttf \
		NotoSerifThai-Condensed.ttf \
		NotoSerifThai-CondensedBlack.ttf \
		NotoSerifThai-CondensedBold.ttf \
		NotoSerifThai-CondensedExtraBold.ttf \
		NotoSerifThai-CondensedExtraLight.ttf \
		NotoSerifThai-CondensedLight.ttf \
		NotoSerifThai-CondensedMedium.ttf \
		NotoSerifThai-CondensedSemiBold.ttf \
		NotoSerifThai-CondensedThin.ttf \
		NotoSerifThai-ExtraBold.ttf \
		NotoSerifThai-ExtraCondensed.ttf \
		NotoSerifThai-ExtraCondensedBlack.ttf \
		NotoSerifThai-ExtraCondensedBold.ttf \
		NotoSerifThai-ExtraCondensedExtraBold.ttf \
		NotoSerifThai-ExtraCondensedExtraLight.ttf \
		NotoSerifThai-ExtraCondensedLight.ttf \
		NotoSerifThai-ExtraCondensedMedium.ttf \
		NotoSerifThai-ExtraCondensedSemiBold.ttf \
		NotoSerifThai-ExtraCondensedThin.ttf \
		NotoSerifThai-ExtraLight.ttf \
		NotoSerifThai-Light.ttf \
		NotoSerifThai-Medium.ttf \
		NotoSerifThai-Regular.ttf \
		NotoSerifThai-SemiBold.ttf \
		NotoSerifThai-SemiCondensed.ttf \
		NotoSerifThai-SemiCondensedBlack.ttf \
		NotoSerifThai-SemiCondensedBold.ttf \
		NotoSerifThai-SemiCondensedExtraBold.ttf \
		NotoSerifThai-SemiCondensedExtraLight.ttf \
		NotoSerifThai-SemiCondensedLight.ttf \
		NotoSerifThai-SemiCondensedMedium.ttf \
		NotoSerifThai-SemiCondensedSemiBold.ttf \
		NotoSerifThai-SemiCondensedThin.ttf \
		NotoSerifThai-Thin.ttf

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${INSTALL_DATA} ${FONTS} ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
