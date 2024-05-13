PORTNAME=	noto
PORTVERSION=	2.014
PORTREVISION=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/notofonts/notofonts.github.io/raw/NotoSansMono-v${PORTVERSION}/fonts/ \
		https://github.com/notofonts/notofonts.github.io/raw/NotoSansMono-v${PORTVERSION}/fonts/NotoSansMono/hinted/ttf/:fonts
PKGNAMESUFFIX=	-sans-mono
DISTFILES=	LICENSE \
		${FONTS:S|$|:fonts|}
DIST_SUBDIR=	Noto/SansMono/${PORTVERSION}
EXTRACT_ONLY=	# empty

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Noto Sans Mono
WWW=		https://fonts.google.com/noto \
		https://notofonts.github.io/ \
		https://github.com/notofonts/latin-greek-cyrillic \
		https://github.com/notofonts/notofonts.github.io/tree/main/fonts/NotoSansMono

LICENSE=	OFL11
LICENSE_FILE=	${DISTDIR}/${DIST_SUBDIR}/LICENSE

USES=		fonts

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

FONTS=		NotoSansMono-Black.ttf \
		NotoSansMono-Bold.ttf \
		NotoSansMono-Condensed.ttf \
		NotoSansMono-CondensedBlack.ttf \
		NotoSansMono-CondensedBold.ttf \
		NotoSansMono-CondensedExtraBold.ttf \
		NotoSansMono-CondensedExtraLight.ttf \
		NotoSansMono-CondensedLight.ttf \
		NotoSansMono-CondensedMedium.ttf \
		NotoSansMono-CondensedSemiBold.ttf \
		NotoSansMono-CondensedThin.ttf \
		NotoSansMono-ExtraBold.ttf \
		NotoSansMono-ExtraCondensed.ttf \
		NotoSansMono-ExtraCondensedBlack.ttf \
		NotoSansMono-ExtraCondensedBold.ttf \
		NotoSansMono-ExtraCondensedExtraBold.ttf \
		NotoSansMono-ExtraCondensedExtraLight.ttf \
		NotoSansMono-ExtraCondensedLight.ttf \
		NotoSansMono-ExtraCondensedMedium.ttf \
		NotoSansMono-ExtraCondensedSemiBold.ttf \
		NotoSansMono-ExtraCondensedThin.ttf \
		NotoSansMono-ExtraLight.ttf \
		NotoSansMono-Light.ttf \
		NotoSansMono-Medium.ttf \
		NotoSansMono-Regular.ttf \
		NotoSansMono-SemiBold.ttf \
		NotoSansMono-SemiCondensed.ttf \
		NotoSansMono-SemiCondensedBlack.ttf \
		NotoSansMono-SemiCondensedBold.ttf \
		NotoSansMono-SemiCondensedExtraBold.ttf \
		NotoSansMono-SemiCondensedExtraLight.ttf \
		NotoSansMono-SemiCondensedLight.ttf \
		NotoSansMono-SemiCondensedMedium.ttf \
		NotoSansMono-SemiCondensedSemiBold.ttf \
		NotoSansMono-SemiCondensedThin.ttf \
		NotoSansMono-Thin.ttf

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${INSTALL_DATA} ${FONTS} ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
