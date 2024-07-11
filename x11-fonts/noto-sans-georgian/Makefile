PORTNAME=	noto
PORTVERSION=	2.005
CATEGORIES=	x11-fonts
#MASTER_SITES=	https://github.com/notofonts/notofonts.github.io/raw/NotoSansGeorgian-v${PORTVERSION}/fonts/ \
		https://github.com/notofonts/notofonts.github.io/raw/NotoSansGeorgian-v${PORTVERSION}/fonts/NotoSansGeorgian/hinted/ttf/:fonts
MASTER_SITES=	https://github.com/notofonts/notofonts.github.io/raw/noto-monthly-release-24.3.1/fonts/ \
		https://github.com/notofonts/notofonts.github.io/raw/noto-monthly-release-24.3.1/fonts/NotoSansGeorgian/hinted/ttf/:fonts
PKGNAMESUFFIX=	-sans-georgian
DISTFILES=	LICENSE \
		${FONTS:S|$|:fonts|}
DIST_SUBDIR=	Noto/SansGeorgian/${PORTVERSION}
EXTRACT_ONLY=	# empty

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Noto Sans Georgian
WWW=		https://fonts.google.com/noto \
		https://notofonts.github.io/ \
		https://github.com/notofonts/georgian \
		https://github.com/notofonts/notofonts.github.io/tree/main/fonts/NotoSansGeorgian

LICENSE=	OFL11
LICENSE_FILE=	${DISTDIR}/${DIST_SUBDIR}/LICENSE

USES=		fonts

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

FONTS=		NotoSansGeorgian-Black.ttf \
		NotoSansGeorgian-Bold.ttf \
		NotoSansGeorgian-Condensed.ttf \
		NotoSansGeorgian-CondensedBlack.ttf \
		NotoSansGeorgian-CondensedBold.ttf \
		NotoSansGeorgian-CondensedExtraBold.ttf \
		NotoSansGeorgian-CondensedExtraLight.ttf \
		NotoSansGeorgian-CondensedLight.ttf \
		NotoSansGeorgian-CondensedMedium.ttf \
		NotoSansGeorgian-CondensedSemiBold.ttf \
		NotoSansGeorgian-CondensedThin.ttf \
		NotoSansGeorgian-ExtraBold.ttf \
		NotoSansGeorgian-ExtraCondensed.ttf \
		NotoSansGeorgian-ExtraCondensedBlack.ttf \
		NotoSansGeorgian-ExtraCondensedBold.ttf \
		NotoSansGeorgian-ExtraCondensedExtraBold.ttf \
		NotoSansGeorgian-ExtraCondensedExtraLight.ttf \
		NotoSansGeorgian-ExtraCondensedLight.ttf \
		NotoSansGeorgian-ExtraCondensedMedium.ttf \
		NotoSansGeorgian-ExtraCondensedSemiBold.ttf \
		NotoSansGeorgian-ExtraCondensedThin.ttf \
		NotoSansGeorgian-ExtraLight.ttf \
		NotoSansGeorgian-Light.ttf \
		NotoSansGeorgian-Medium.ttf \
		NotoSansGeorgian-Regular.ttf \
		NotoSansGeorgian-SemiBold.ttf \
		NotoSansGeorgian-SemiCondensed.ttf \
		NotoSansGeorgian-SemiCondensedBlack.ttf \
		NotoSansGeorgian-SemiCondensedBold.ttf \
		NotoSansGeorgian-SemiCondensedExtraBold.ttf \
		NotoSansGeorgian-SemiCondensedExtraLight.ttf \
		NotoSansGeorgian-SemiCondensedLight.ttf \
		NotoSansGeorgian-SemiCondensedMedium.ttf \
		NotoSansGeorgian-SemiCondensedSemiBold.ttf \
		NotoSansGeorgian-SemiCondensedThin.ttf \
		NotoSansGeorgian-Thin.ttf

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${INSTALL_DATA} ${FONTS} ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
