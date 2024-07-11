PORTNAME=	noto
PORTVERSION=	3.000
CATEGORIES=	x11-fonts
#MASTER_SITES=	https://github.com/notofonts/notofonts.github.io/raw/NotoSansMath-v${PORTVERSION}/fonts/ \
#		https://github.com/notofonts/notofonts.github.io/raw/NotoSansMath-v${PORTVERSION}/fonts/NotoSansMath/hinted/ttf/:fonts
MASTER_SITES=	https://github.com/notofonts/notofonts.github.io/raw/55773c3eb233b5a0eaa07de6226da189b136b4f0/fonts/ \
		https://github.com/notofonts/notofonts.github.io/raw/55773c3eb233b5a0eaa07de6226da189b136b4f0/fonts/NotoSansMath/hinted/ttf/:fonts
PKGNAMESUFFIX=	-sans-math
DISTFILES=	LICENSE \
		${FONTS:S|$|:fonts|}
DIST_SUBDIR=	Noto/SansMath/${PORTVERSION}
EXTRACT_ONLY=	# empty

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Noto Sans Math
WWW=		https://fonts.google.com/noto \
		https://notofonts.github.io/ \
		https://github.com/notofonts/math \
		https://github.com/notofonts/notofonts.github.io/tree/main/fonts/NotoSansMath

LICENSE=	OFL11
LICENSE_FILE=	${DISTDIR}/${DIST_SUBDIR}/LICENSE

USES=		fonts

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	${FONTSDIR}/NotoSansMath-Regular.ttf

FONTS=		NotoSansMath-Regular.ttf

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${INSTALL_DATA} ${FONTS} ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
