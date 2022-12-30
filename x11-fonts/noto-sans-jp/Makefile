PORTNAME=	noto
PORTVERSION=	2.004
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/googlefonts/noto-cjk/raw/Sans${PORTVERSION}/ \
		https://github.com/googlefonts/noto-cjk/raw/Sans${PORTVERSION}/Sans/OTF/Japanese/:cjk \
		https://github.com/googlefonts/noto-cjk/raw/Sans${PORTVERSION}/Sans/Mono/:mono \
		https://github.com/googlefonts/noto-cjk/raw/Sans${PORTVERSION}/Sans/SubsetOTF/JP/:subset
PKGNAMESUFFIX=	-sans-jp
DISTFILES=	LICENSE \
		${CJK_FONTS:S|$|:cjk|} \
		${MONO_FONTS:S|$|:mono|} \
		${SUBSET_FONTS:S|$|:subset|}
DIST_SUBDIR=	Noto/CJK/${PORTVERSION}
EXTRACT_ONLY=	# empty

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Noto Sans (Japanese)
WWW=		https://www.google.com/get/noto/ \
		https://github.com/googlefonts/noto-cjk

LICENSE=	OFL11
LICENSE_FILE=	${DISTDIR}/${DIST_SUBDIR}/LICENSE

USES=		fonts

NO_ARCH=	yes
NO_BUILD=	yes

CJK_FONTS=	NotoSansCJKjp-Black.otf \
		NotoSansCJKjp-Bold.otf \
		NotoSansCJKjp-DemiLight.otf \
		NotoSansCJKjp-Light.otf \
		NotoSansCJKjp-Medium.otf \
		NotoSansCJKjp-Regular.otf \
		NotoSansCJKjp-Thin.otf
MONO_FONTS=	NotoSansMonoCJKjp-Bold.otf \
		NotoSansMonoCJKjp-Regular.otf
SUBSET_FONTS=	NotoSansJP-Black.otf \
		NotoSansJP-Bold.otf \
		NotoSansJP-DemiLight.otf \
		NotoSansJP-Light.otf \
		NotoSansJP-Medium.otf \
		NotoSansJP-Regular.otf \
		NotoSansJP-Thin.otf

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${INSTALL_DATA} ${CJK_FONTS} ${MONO_FONTS} ${SUBSET_FONTS} ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
