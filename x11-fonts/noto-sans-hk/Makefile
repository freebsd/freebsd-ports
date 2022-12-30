PORTNAME=	noto
PORTVERSION=	2.004
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/googlefonts/noto-cjk/raw/Sans${PORTVERSION}/ \
		https://github.com/googlefonts/noto-cjk/raw/Sans${PORTVERSION}/Sans/OTF/TraditionalChineseHK/:cjk \
		https://github.com/googlefonts/noto-cjk/raw/Sans${PORTVERSION}/Sans/Mono/:mono \
		https://github.com/googlefonts/noto-cjk/raw/Sans${PORTVERSION}/Sans/SubsetOTF/HK/:subset
PKGNAMESUFFIX=	-sans-hk
DISTFILES=	LICENSE \
		${CJK_FONTS:S|$|:cjk|} \
		${MONO_FONTS:S|$|:mono|} \
		${SUBSET_FONTS:S|$|:subset|}
DIST_SUBDIR=	Noto/CJK/${PORTVERSION}
EXTRACT_ONLY=	# empty

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Noto Sans (Traditional Chinese Hong Kong)
WWW=		https://www.google.com/get/noto/ \
		https://github.com/googlefonts/noto-cjk

LICENSE=	OFL11
LICENSE_FILE=	${DISTDIR}/${DIST_SUBDIR}/LICENSE

USES=		fonts

NO_ARCH=	yes
NO_BUILD=	yes

CJK_FONTS=	NotoSansCJKhk-Black.otf \
		NotoSansCJKhk-Bold.otf \
		NotoSansCJKhk-DemiLight.otf \
		NotoSansCJKhk-Light.otf \
		NotoSansCJKhk-Medium.otf \
		NotoSansCJKhk-Regular.otf \
		NotoSansCJKhk-Thin.otf
MONO_FONTS=	NotoSansMonoCJKhk-Bold.otf \
		NotoSansMonoCJKhk-Regular.otf
SUBSET_FONTS=	NotoSansHK-Black.otf \
		NotoSansHK-Bold.otf \
		NotoSansHK-DemiLight.otf \
		NotoSansHK-Light.otf \
		NotoSansHK-Medium.otf \
		NotoSansHK-Regular.otf \
		NotoSansHK-Thin.otf

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${INSTALL_DATA} ${CJK_FONTS} ${MONO_FONTS} ${SUBSET_FONTS} ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
