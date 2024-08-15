PORTNAME=	noto
PORTVERSION=	2.005
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/notofonts/notofonts.github.io/raw/NotoSerifKannada-v${PORTVERSION}/fonts/ \
		https://github.com/notofonts/notofonts.github.io/raw/NotoSerifKannada-v${PORTVERSION}/fonts/NotoSerifKannada/hinted/ttf/:fonts
PKGNAMESUFFIX=	-serif-kannada
DISTFILES=	LICENSE \
		${FONTS:S|$|:fonts|}
DIST_SUBDIR=	Noto/SerifKannada/${PORTVERSION}
EXTRACT_ONLY=	# empty

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Noto Serif Kannada
WWW=		https://fonts.google.com/noto \
		https://notofonts.github.io/ \
		https://github.com/notofonts/kannada \
		https://github.com/notofonts/notofonts.github.io/tree/main/fonts/NotoSerifKannada

LICENSE=	OFL11
LICENSE_FILE=	${DISTDIR}/${DIST_SUBDIR}/LICENSE

USES=		fonts

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

FONTS=		NotoSerifKannada-Black.ttf \
		NotoSerifKannada-Bold.ttf \
		NotoSerifKannada-ExtraBold.ttf \
		NotoSerifKannada-ExtraLight.ttf \
		NotoSerifKannada-Light.ttf \
		NotoSerifKannada-Medium.ttf \
		NotoSerifKannada-Regular.ttf \
		NotoSerifKannada-SemiBold.ttf \
		NotoSerifKannada-Thin.ttf

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${INSTALL_DATA} ${FONTS} ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
