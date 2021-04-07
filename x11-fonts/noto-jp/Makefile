PORTNAME=	noto
PORTVERSION=	2.001
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/googlefonts/noto-cjk/raw/NotoSansV2.001/
PKGNAMESUFFIX=	-jp
DISTFILES=	LICENSE \
		${NOTO_JP_FONTS}
DIST_SUBDIR=	Noto
EXTRACT_ONLY=	# empty

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Noto Fonts family (Japanese)

LICENSE=	OFL11
LICENSE_FILE=	${DISTDIR}/${DIST_SUBDIR}/LICENSE

USES=		fonts

NO_ARCH=	yes
NO_BUILD=	yes

NOTO_JP_FONTS=	NotoSansCJKjp-Black.otf \
		NotoSansCJKjp-Bold.otf \
		NotoSansCJKjp-DemiLight.otf \
		NotoSansCJKjp-Light.otf \
		NotoSansCJKjp-Medium.otf \
		NotoSansCJKjp-Regular.otf \
		NotoSansCJKjp-Thin.otf \
		NotoSansJP-Black.otf \
		NotoSansJP-Bold.otf \
		NotoSansJP-DemiLight.otf \
		NotoSansJP-Light.otf \
		NotoSansJP-Medium.otf \
		NotoSansJP-Regular.otf \
		NotoSansJP-Thin.otf \
		NotoSansMonoCJKjp-Bold.otf \
		NotoSansMonoCJKjp-Regular.otf \
		NotoSerifCJKjp-Black.otf \
		NotoSerifCJKjp-Bold.otf \
		NotoSerifCJKjp-ExtraLight.otf \
		NotoSerifCJKjp-Light.otf \
		NotoSerifCJKjp-Medium.otf \
		NotoSerifCJKjp-Regular.otf \
		NotoSerifCJKjp-SemiBold.otf \
		NotoSerifJP-Black.otf \
		NotoSerifJP-Bold.otf \
		NotoSerifJP-ExtraLight.otf \
		NotoSerifJP-Light.otf \
		NotoSerifJP-Medium.otf \
		NotoSerifJP-Regular.otf \
		NotoSerifJP-SemiBold.otf

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${INSTALL_DATA} ${NOTO_JP_FONTS} ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
