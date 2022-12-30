PORTNAME=	noto
PORTVERSION=	2.004
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/googlefonts/noto-cjk/raw/Sans${PORTVERSION}/ \
		https://github.com/googlefonts/noto-cjk/raw/Sans${PORTVERSION}/Sans/OTF/SimplifiedChinese/:cjk \
		https://github.com/googlefonts/noto-cjk/raw/Sans${PORTVERSION}/Sans/Mono/:mono \
		https://github.com/googlefonts/noto-cjk/raw/Sans${PORTVERSION}/Sans/SubsetOTF/SC/:subset
PKGNAMESUFFIX=	-sans-sc
DISTFILES=	LICENSE \
		${CJK_FONTS:S|$|:cjk|} \
		${MONO_FONTS:S|$|:mono|} \
		${SUBSET_FONTS:S|$|:subset|}
DIST_SUBDIR=	Noto/CJK/${PORTVERSION}
EXTRACT_ONLY=	# empty

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Noto Sans (Simplified Chinese)
WWW=		https://www.google.com/get/noto/ \
		https://github.com/googlefonts/noto-cjk

LICENSE=	OFL11
LICENSE_FILE=	${DISTDIR}/${DIST_SUBDIR}/LICENSE

USES=		fonts

NO_ARCH=	yes
NO_BUILD=	yes

CJK_FONTS=	NotoSansCJKsc-Black.otf \
		NotoSansCJKsc-Bold.otf \
		NotoSansCJKsc-DemiLight.otf \
		NotoSansCJKsc-Light.otf \
		NotoSansCJKsc-Medium.otf \
		NotoSansCJKsc-Regular.otf \
		NotoSansCJKsc-Thin.otf
MONO_FONTS=	NotoSansMonoCJKsc-Bold.otf \
		NotoSansMonoCJKsc-Regular.otf
SUBSET_FONTS=	NotoSansSC-Black.otf \
		NotoSansSC-Bold.otf \
		NotoSansSC-DemiLight.otf \
		NotoSansSC-Light.otf \
		NotoSansSC-Medium.otf \
		NotoSansSC-Regular.otf \
		NotoSansSC-Thin.otf

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${INSTALL_DATA} ${CJK_FONTS} ${MONO_FONTS} ${SUBSET_FONTS} ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
