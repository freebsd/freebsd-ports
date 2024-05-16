PORTNAME=	noto
PORTVERSION=	2.003
CATEGORIES=	x11-fonts
#MASTER_SITES=	https://github.com/notofonts/notofonts.github.io/raw/NotoSansLao-v${PORTVERSION}/fonts/ \
#		https://github.com/notofonts/notofonts.github.io/raw/NotoSansLao-v${PORTVERSION}/fonts/NotoSansLao/hinted/ttf/:fonts
MASTER_SITES=	https://github.com/notofonts/notofonts.github.io/raw/noto-monthly-release-23.7.1/fonts/ \
		https://github.com/notofonts/notofonts.github.io/raw/noto-monthly-release-23.7.1/fonts/NotoSansLao/hinted/ttf/:fonts
PKGNAMESUFFIX=	-sans-lao
DISTFILES=	LICENSE \
		${FONTS:S|$|:fonts|}
DIST_SUBDIR=	Noto/SansLao/${PORTVERSION}
EXTRACT_ONLY=	# empty

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Noto Sans Lao
WWW=		https://fonts.google.com/noto \
		https://notofonts.github.io/ \
		https://github.com/notofonts/lao \
		https://github.com/notofonts/notofonts.github.io/tree/main/fonts/NotoSansLao

LICENSE=	OFL11
LICENSE_FILE=	${DISTDIR}/${DIST_SUBDIR}/LICENSE

USES=		fonts

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

FONTS=		NotoSansLao-Black.ttf \
		NotoSansLao-Bold.ttf \
		NotoSansLao-Condensed.ttf \
		NotoSansLao-CondensedBlack.ttf \
		NotoSansLao-CondensedBold.ttf \
		NotoSansLao-CondensedExtraBold.ttf \
		NotoSansLao-CondensedExtraLight.ttf \
		NotoSansLao-CondensedLight.ttf \
		NotoSansLao-CondensedMedium.ttf \
		NotoSansLao-CondensedSemiBold.ttf \
		NotoSansLao-CondensedThin.ttf \
		NotoSansLao-ExtraBold.ttf \
		NotoSansLao-ExtraCondensed.ttf \
		NotoSansLao-ExtraCondensedBlack.ttf \
		NotoSansLao-ExtraCondensedBold.ttf \
		NotoSansLao-ExtraCondensedExtraBold.ttf \
		NotoSansLao-ExtraCondensedExtraLight.ttf \
		NotoSansLao-ExtraCondensedLight.ttf \
		NotoSansLao-ExtraCondensedMedium.ttf \
		NotoSansLao-ExtraCondensedSemiBold.ttf \
		NotoSansLao-ExtraCondensedThin.ttf \
		NotoSansLao-ExtraLight.ttf \
		NotoSansLao-Light.ttf \
		NotoSansLao-Medium.ttf \
		NotoSansLao-Regular.ttf \
		NotoSansLao-SemiBold.ttf \
		NotoSansLao-SemiCondensed.ttf \
		NotoSansLao-SemiCondensedBlack.ttf \
		NotoSansLao-SemiCondensedBold.ttf \
		NotoSansLao-SemiCondensedExtraBold.ttf \
		NotoSansLao-SemiCondensedExtraLight.ttf \
		NotoSansLao-SemiCondensedLight.ttf \
		NotoSansLao-SemiCondensedMedium.ttf \
		NotoSansLao-SemiCondensedSemiBold.ttf \
		NotoSansLao-SemiCondensedThin.ttf \
		NotoSansLao-Thin.ttf

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${INSTALL_DATA} ${FONTS} ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
