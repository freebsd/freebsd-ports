PORTNAME=	noto
PORTVERSION=	2.005
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/notofonts/notofonts.github.io/raw/NotoSansTelugu-v${PORTVERSION}/fonts/ \
		https://github.com/notofonts/notofonts.github.io/raw/NotoSansTelugu-v${PORTVERSION}/fonts/NotoSansTelugu/hinted/ttf/:fonts
PKGNAMESUFFIX=	-sans-telugu
DISTFILES=	LICENSE \
		${FONTS:S|$|:fonts|}
DIST_SUBDIR=	Noto/SansTelugu/${PORTVERSION}
EXTRACT_ONLY=	# empty

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Noto Sans Telugu
WWW=		https://fonts.google.com/noto \
		https://notofonts.github.io/ \
		https://github.com/notofonts/telugu \
		https://github.com/notofonts/notofonts.github.io/tree/main/fonts/NotoSansTelugu

LICENSE=	OFL11
LICENSE_FILE=	${DISTDIR}/${DIST_SUBDIR}/LICENSE

USES=		fonts

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

FONTS=		NotoSansTelugu-Black.ttf \
		NotoSansTelugu-Bold.ttf \
		NotoSansTelugu-Condensed.ttf \
		NotoSansTelugu-CondensedBlack.ttf \
		NotoSansTelugu-CondensedBold.ttf \
		NotoSansTelugu-CondensedExtraBold.ttf \
		NotoSansTelugu-CondensedExtraLight.ttf \
		NotoSansTelugu-CondensedLight.ttf \
		NotoSansTelugu-CondensedMedium.ttf \
		NotoSansTelugu-CondensedSemiBold.ttf \
		NotoSansTelugu-CondensedThin.ttf \
		NotoSansTelugu-ExtraBold.ttf \
		NotoSansTelugu-ExtraCondensed.ttf \
		NotoSansTelugu-ExtraCondensedBlack.ttf \
		NotoSansTelugu-ExtraCondensedBold.ttf \
		NotoSansTelugu-ExtraCondensedExtraBold.ttf \
		NotoSansTelugu-ExtraCondensedExtraLight.ttf \
		NotoSansTelugu-ExtraCondensedLight.ttf \
		NotoSansTelugu-ExtraCondensedMedium.ttf \
		NotoSansTelugu-ExtraCondensedSemiBold.ttf \
		NotoSansTelugu-ExtraCondensedThin.ttf \
		NotoSansTelugu-ExtraLight.ttf \
		NotoSansTelugu-Light.ttf \
		NotoSansTelugu-Medium.ttf \
		NotoSansTelugu-Regular.ttf \
		NotoSansTelugu-SemiBold.ttf \
		NotoSansTelugu-SemiCondensed.ttf \
		NotoSansTelugu-SemiCondensedBlack.ttf \
		NotoSansTelugu-SemiCondensedBold.ttf \
		NotoSansTelugu-SemiCondensedExtraBold.ttf \
		NotoSansTelugu-SemiCondensedExtraLight.ttf \
		NotoSansTelugu-SemiCondensedLight.ttf \
		NotoSansTelugu-SemiCondensedMedium.ttf \
		NotoSansTelugu-SemiCondensedSemiBold.ttf \
		NotoSansTelugu-SemiCondensedThin.ttf \
		NotoSansTelugu-Thin.ttf \
		NotoSansTeluguUI-Black.ttf \
		NotoSansTeluguUI-Bold.ttf \
		NotoSansTeluguUI-Condensed.ttf \
		NotoSansTeluguUI-CondensedBlack.ttf \
		NotoSansTeluguUI-CondensedBold.ttf \
		NotoSansTeluguUI-CondensedExtraBold.ttf \
		NotoSansTeluguUI-CondensedExtraLight.ttf \
		NotoSansTeluguUI-CondensedLight.ttf \
		NotoSansTeluguUI-CondensedMedium.ttf \
		NotoSansTeluguUI-CondensedSemiBold.ttf \
		NotoSansTeluguUI-CondensedThin.ttf \
		NotoSansTeluguUI-ExtraBold.ttf \
		NotoSansTeluguUI-ExtraCondensed.ttf \
		NotoSansTeluguUI-ExtraCondensedBlack.ttf \
		NotoSansTeluguUI-ExtraCondensedBold.ttf \
		NotoSansTeluguUI-ExtraCondensedExtraBold.ttf \
		NotoSansTeluguUI-ExtraCondensedExtraLight.ttf \
		NotoSansTeluguUI-ExtraCondensedLight.ttf \
		NotoSansTeluguUI-ExtraCondensedMedium.ttf \
		NotoSansTeluguUI-ExtraCondensedSemiBold.ttf \
		NotoSansTeluguUI-ExtraCondensedThin.ttf \
		NotoSansTeluguUI-ExtraLight.ttf \
		NotoSansTeluguUI-Light.ttf \
		NotoSansTeluguUI-Medium.ttf \
		NotoSansTeluguUI-Regular.ttf \
		NotoSansTeluguUI-SemiBold.ttf \
		NotoSansTeluguUI-SemiCondensed.ttf \
		NotoSansTeluguUI-SemiCondensedBlack.ttf \
		NotoSansTeluguUI-SemiCondensedBold.ttf \
		NotoSansTeluguUI-SemiCondensedExtraBold.ttf \
		NotoSansTeluguUI-SemiCondensedExtraLight.ttf \
		NotoSansTeluguUI-SemiCondensedLight.ttf \
		NotoSansTeluguUI-SemiCondensedMedium.ttf \
		NotoSansTeluguUI-SemiCondensedSemiBold.ttf \
		NotoSansTeluguUI-SemiCondensedThin.ttf \
		NotoSansTeluguUI-Thin.ttf

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${INSTALL_DATA} ${FONTS} ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
