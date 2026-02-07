PORTNAME=	noto
PORTVERSION=	3.001
CATEGORIES=	x11-fonts
#MASTER_SITES=	https://github.com/notofonts/notofonts.github.io/raw/NotoSansHebrew-v${PORTVERSION}/fonts/ \
#		https://github.com/notofonts/notofonts.github.io/raw/NotoSansHebrew-v${PORTVERSION}/fonts/NotoSansHebrew/hinted/ttf/:fonts
MASTER_SITES=	https://github.com/notofonts/notofonts.github.io/raw/40ae54ff25c9e0ad997f62fde48297dd9dfe51c8/fonts/ \
		https://github.com/notofonts/notofonts.github.io/raw/40ae54ff25c9e0ad997f62fde48297dd9dfe51c8/fonts/NotoSansHebrew/hinted/ttf/:fonts
PKGNAMESUFFIX=	-sans-hebrew
DISTFILES=	LICENSE \
		${FONTS:S|$|:fonts|}
DIST_SUBDIR=	Noto/SansHebrew/${PORTVERSION}
EXTRACT_ONLY=	# empty

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Noto Sans Hebrew
WWW=		https://fonts.google.com/noto \
		https://notofonts.github.io/ \
		https://github.com/notofonts/hebrew \
		https://github.com/notofonts/notofonts.github.io/tree/main/fonts/NotoSansHebrew

LICENSE=	OFL11
LICENSE_FILE=	${DISTDIR}/${DIST_SUBDIR}/LICENSE

USES=		fonts

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

FONTS=		NotoSansHebrew-Black.ttf \
		NotoSansHebrew-Bold.ttf \
		NotoSansHebrew-Condensed.ttf \
		NotoSansHebrew-CondensedBlack.ttf \
		NotoSansHebrew-CondensedBold.ttf \
		NotoSansHebrew-CondensedExtraBold.ttf \
		NotoSansHebrew-CondensedExtraLight.ttf \
		NotoSansHebrew-CondensedLight.ttf \
		NotoSansHebrew-CondensedMedium.ttf \
		NotoSansHebrew-CondensedSemiBold.ttf \
		NotoSansHebrew-CondensedThin.ttf \
		NotoSansHebrew-ExtraBold.ttf \
		NotoSansHebrew-ExtraCondensed.ttf \
		NotoSansHebrew-ExtraCondensedBlack.ttf \
		NotoSansHebrew-ExtraCondensedBold.ttf \
		NotoSansHebrew-ExtraCondensedExtraBold.ttf \
		NotoSansHebrew-ExtraCondensedExtraLight.ttf \
		NotoSansHebrew-ExtraCondensedLight.ttf \
		NotoSansHebrew-ExtraCondensedMedium.ttf \
		NotoSansHebrew-ExtraCondensedSemiBold.ttf \
		NotoSansHebrew-ExtraCondensedThin.ttf \
		NotoSansHebrew-ExtraLight.ttf \
		NotoSansHebrew-Light.ttf \
		NotoSansHebrew-Medium.ttf \
		NotoSansHebrew-Regular.ttf \
		NotoSansHebrew-SemiBold.ttf \
		NotoSansHebrew-SemiCondensed.ttf \
		NotoSansHebrew-SemiCondensedBlack.ttf \
		NotoSansHebrew-SemiCondensedBold.ttf \
		NotoSansHebrew-SemiCondensedExtraBold.ttf \
		NotoSansHebrew-SemiCondensedExtraLight.ttf \
		NotoSansHebrew-SemiCondensedLight.ttf \
		NotoSansHebrew-SemiCondensedMedium.ttf \
		NotoSansHebrew-SemiCondensedSemiBold.ttf \
		NotoSansHebrew-SemiCondensedThin.ttf \
		NotoSansHebrew-Thin.ttf

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${INSTALL_DATA} ${FONTS} ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
