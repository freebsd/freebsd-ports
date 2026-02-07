PORTNAME=	noto
PORTVERSION=	2.005
CATEGORIES=	x11-fonts
#MASTER_SITES=	https://github.com/notofonts/notofonts.github.io/raw/NotoSansCham-v${PORTVERSION}/fonts/ \
#		https://github.com/notofonts/notofonts.github.io/raw/NotoSansCham-v${PORTVERSION}/fonts/NotoSansCham/hinted/ttf/:fonts
MASTER_SITES=	https://github.com/notofonts/notofonts.github.io/raw/NotoZnamennyMusicalNotation-v1.003/fonts/ \
		https://github.com/notofonts/notofonts.github.io/raw/NotoZnamennyMusicalNotation-v1.003/fonts/NotoSansCham/hinted/ttf/:fonts
PKGNAMESUFFIX=	-sans-cham
DISTFILES=	LICENSE \
		${FONTS:S|$|:fonts|}
DIST_SUBDIR=	Noto/SansCham/${PORTVERSION}
EXTRACT_ONLY=	# empty

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Noto Sans Cham
WWW=		https://fonts.google.com/noto \
		https://notofonts.github.io/ \
		https://github.com/notofonts/cham \
		https://github.com/notofonts/notofonts.github.io/tree/main/fonts/NotoSansCham

LICENSE=	OFL11
LICENSE_FILE=	${DISTDIR}/${DIST_SUBDIR}/LICENSE

USES=		fonts

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

FONTS=		NotoSansCham-Black.ttf \
		NotoSansCham-Bold.ttf \
		NotoSansCham-ExtraBold.ttf \
		NotoSansCham-ExtraLight.ttf \
		NotoSansCham-Light.ttf \
		NotoSansCham-Medium.ttf \
		NotoSansCham-Regular.ttf \
		NotoSansCham-SemiBold.ttf \
		NotoSansCham-Thin.ttf

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${INSTALL_DATA} ${FONTS} ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
