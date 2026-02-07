PORTNAME=	noto
PORTVERSION=	2.003
CATEGORIES=	x11-fonts
#MASTER_SITES=	https://github.com/notofonts/notofonts.github.io/raw/NotoSerifLao-v${PORTVERSION}/fonts/ \
#		https://github.com/notofonts/notofonts.github.io/raw/NotoSerifLao-v${PORTVERSION}/fonts/NotoSerifLao/hinted/ttf/:fonts
MASTER_SITES=	https://github.com/notofonts/notofonts.github.io/raw/noto-monthly-release-23.7.1/fonts/ \
		https://github.com/notofonts/notofonts.github.io/raw/noto-monthly-release-23.7.1/fonts/NotoSerifLao/hinted/ttf/:fonts
PKGNAMESUFFIX=	-serif-lao
DISTFILES=	LICENSE \
		${FONTS:S|$|:fonts|}
DIST_SUBDIR=	Noto/SerifLao/${PORTVERSION}
EXTRACT_ONLY=	# empty

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Noto Serif Lao
WWW=		https://fonts.google.com/noto \
		https://notofonts.github.io/ \
		https://github.com/notofonts/lao \
		https://github.com/notofonts/notofonts.github.io/tree/main/fonts/NotoSerifLao

LICENSE=	OFL11
LICENSE_FILE=	${DISTDIR}/${DIST_SUBDIR}/LICENSE

USES=		fonts

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

FONTS=		NotoSerifLao-Black.ttf \
		NotoSerifLao-Bold.ttf \
		NotoSerifLao-Condensed.ttf \
		NotoSerifLao-CondensedBlack.ttf \
		NotoSerifLao-CondensedBold.ttf \
		NotoSerifLao-CondensedExtraBold.ttf \
		NotoSerifLao-CondensedExtraLight.ttf \
		NotoSerifLao-CondensedLight.ttf \
		NotoSerifLao-CondensedMedium.ttf \
		NotoSerifLao-CondensedSemiBold.ttf \
		NotoSerifLao-CondensedThin.ttf \
		NotoSerifLao-ExtraBold.ttf \
		NotoSerifLao-ExtraCondensed.ttf \
		NotoSerifLao-ExtraCondensedBlack.ttf \
		NotoSerifLao-ExtraCondensedBold.ttf \
		NotoSerifLao-ExtraCondensedExtraBold.ttf \
		NotoSerifLao-ExtraCondensedExtraLight.ttf \
		NotoSerifLao-ExtraCondensedLight.ttf \
		NotoSerifLao-ExtraCondensedMedium.ttf \
		NotoSerifLao-ExtraCondensedSemiBold.ttf \
		NotoSerifLao-ExtraCondensedThin.ttf \
		NotoSerifLao-ExtraLight.ttf \
		NotoSerifLao-Light.ttf \
		NotoSerifLao-Medium.ttf \
		NotoSerifLao-Regular.ttf \
		NotoSerifLao-SemiBold.ttf \
		NotoSerifLao-SemiCondensed.ttf \
		NotoSerifLao-SemiCondensedBlack.ttf \
		NotoSerifLao-SemiCondensedBold.ttf \
		NotoSerifLao-SemiCondensedExtraBold.ttf \
		NotoSerifLao-SemiCondensedExtraLight.ttf \
		NotoSerifLao-SemiCondensedLight.ttf \
		NotoSerifLao-SemiCondensedMedium.ttf \
		NotoSerifLao-SemiCondensedSemiBold.ttf \
		NotoSerifLao-SemiCondensedThin.ttf \
		NotoSerifLao-Thin.ttf

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${INSTALL_DATA} ${FONTS} ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
