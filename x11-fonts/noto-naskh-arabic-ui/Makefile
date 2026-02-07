PORTNAME=	noto
PORTVERSION=	2.017
CATEGORIES=	x11-fonts
#MASTER_SITES=	https://github.com/notofonts/notofonts.github.io/raw/NotoNaskhArabicUI-v${PORTVERSION}/fonts/ \
#		https://github.com/notofonts/notofonts.github.io/raw/NotoNaskhArabicUI-v${PORTVERSION}/fonts/NotoNaskhArabicUI/hinted/ttf/:fonts
MASTER_SITES=	https://github.com/notofonts/notofonts.github.io/raw/25cbaa805a25e183d65250ae6f9b0a397f6417e8/fonts/ \
		https://github.com/notofonts/notofonts.github.io/raw/25cbaa805a25e183d65250ae6f9b0a397f6417e8/fonts/NotoNaskhArabicUI/hinted/ttf/:fonts
PKGNAMESUFFIX=	-naskh-arabic-ui
DISTFILES=	LICENSE \
		${FONTS:S|$|:fonts|}
DIST_SUBDIR=	Noto/NaskhArabicUI/${PORTVERSION}
EXTRACT_ONLY=	# empty

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Noto Naskh Arabic UI
WWW=		https://fonts.google.com/noto \
		https://notofonts.github.io/ \
		https://github.com/notofonts/arabic \
		https://github.com/notofonts/notofonts.github.io/tree/main/fonts/NotoNaskhArabicUI

LICENSE=	OFL11
LICENSE_FILE=	${DISTDIR}/${DIST_SUBDIR}/LICENSE

USES=		fonts

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

FONTS=		NotoNaskhArabicUI-Bold.ttf \
		NotoNaskhArabicUI-Medium.ttf \
		NotoNaskhArabicUI-Regular.ttf \
		NotoNaskhArabicUI-SemiBold.ttf

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${INSTALL_DATA} ${FONTS} ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
