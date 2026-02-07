PORTNAME=	noto
PORTVERSION=	2.110
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/notofonts/notofonts.github.io/raw/NotoKufiArabic-v${PORTVERSION}/fonts/ \
		https://github.com/notofonts/notofonts.github.io/raw/NotoKufiArabic-v${PORTVERSION}/fonts/NotoKufiArabic/hinted/ttf/:fonts
PKGNAMESUFFIX=	-kufi-arabic
DISTFILES=	LICENSE \
		${FONTS:S|$|:fonts|}
DIST_SUBDIR=	Noto/KufiArabic/${PORTVERSION}
EXTRACT_ONLY=	# empty

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Noto Kufi Arabic
WWW=		https://fonts.google.com/noto \
		https://notofonts.github.io/ \
		https://github.com/notofonts/arabic \
		https://github.com/notofonts/notofonts.github.io/tree/main/fonts/NotoKufiArabic

LICENSE=	OFL11
LICENSE_FILE=	${DISTDIR}/${DIST_SUBDIR}/LICENSE

USES=		fonts

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

FONTS=		NotoKufiArabic-Black.ttf \
		NotoKufiArabic-Bold.ttf \
		NotoKufiArabic-ExtraBold.ttf \
		NotoKufiArabic-ExtraLight.ttf \
		NotoKufiArabic-Light.ttf \
		NotoKufiArabic-Medium.ttf \
		NotoKufiArabic-Regular.ttf \
		NotoKufiArabic-SemiBold.ttf \
		NotoKufiArabic-Thin.ttf

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${INSTALL_DATA} ${FONTS} ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
