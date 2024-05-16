PORTNAME=	noto
PORTVERSION=	2.003
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/notofonts/notofonts.github.io/raw/NotoSerifGeorgian-v${PORTVERSION}/fonts/ \
		https://github.com/notofonts/notofonts.github.io/raw/NotoSerifGeorgian-v${PORTVERSION}/fonts/NotoSerifGeorgian/hinted/ttf/:fonts
PKGNAMESUFFIX=	-serif-georgian
DISTFILES=	LICENSE \
		${FONTS:S|$|:fonts|}
DIST_SUBDIR=	Noto/SerifGeorgian/${PORTVERSION}
EXTRACT_ONLY=	# empty

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Noto Serif Georgian
WWW=		https://fonts.google.com/noto \
		https://notofonts.github.io/ \
		https://github.com/notofonts/georgian \
		https://github.com/notofonts/notofonts.github.io/tree/main/fonts/NotoSerifGeorgian

LICENSE=	OFL11
LICENSE_FILE=	${DISTDIR}/${DIST_SUBDIR}/LICENSE

USES=		fonts

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

FONTS=		NotoSerifGeorgian-Black.ttf \
		NotoSerifGeorgian-Bold.ttf \
		NotoSerifGeorgian-Condensed.ttf \
		NotoSerifGeorgian-CondensedBlack.ttf \
		NotoSerifGeorgian-CondensedBold.ttf \
		NotoSerifGeorgian-CondensedExtraBold.ttf \
		NotoSerifGeorgian-CondensedExtraLight.ttf \
		NotoSerifGeorgian-CondensedLight.ttf \
		NotoSerifGeorgian-CondensedMedium.ttf \
		NotoSerifGeorgian-CondensedSemiBold.ttf \
		NotoSerifGeorgian-CondensedThin.ttf \
		NotoSerifGeorgian-ExtraBold.ttf \
		NotoSerifGeorgian-ExtraCondensed.ttf \
		NotoSerifGeorgian-ExtraCondensedBlack.ttf \
		NotoSerifGeorgian-ExtraCondensedBold.ttf \
		NotoSerifGeorgian-ExtraCondensedExtraBold.ttf \
		NotoSerifGeorgian-ExtraCondensedExtraLight.ttf \
		NotoSerifGeorgian-ExtraCondensedLight.ttf \
		NotoSerifGeorgian-ExtraCondensedMedium.ttf \
		NotoSerifGeorgian-ExtraCondensedSemiBold.ttf \
		NotoSerifGeorgian-ExtraCondensedThin.ttf \
		NotoSerifGeorgian-ExtraLight.ttf \
		NotoSerifGeorgian-Light.ttf \
		NotoSerifGeorgian-Medium.ttf \
		NotoSerifGeorgian-Regular.ttf \
		NotoSerifGeorgian-SemiBold.ttf \
		NotoSerifGeorgian-SemiCondensed.ttf \
		NotoSerifGeorgian-SemiCondensedBlack.ttf \
		NotoSerifGeorgian-SemiCondensedBold.ttf \
		NotoSerifGeorgian-SemiCondensedExtraBold.ttf \
		NotoSerifGeorgian-SemiCondensedExtraLight.ttf \
		NotoSerifGeorgian-SemiCondensedLight.ttf \
		NotoSerifGeorgian-SemiCondensedMedium.ttf \
		NotoSerifGeorgian-SemiCondensedSemiBold.ttf \
		NotoSerifGeorgian-SemiCondensedThin.ttf \
		NotoSerifGeorgian-Thin.ttf

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${INSTALL_DATA} ${FONTS} ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
