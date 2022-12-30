PORTNAME=	noto
PORTVERSION=	2.004
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/googlefonts/noto-cjk/raw/Sans${PORTVERSION}/ \
		https://github.com/googlefonts/noto-cjk/raw/Sans${PORTVERSION}/Sans/OTF/Korean/:cjk \
		https://github.com/googlefonts/noto-cjk/raw/Sans${PORTVERSION}/Sans/Mono/:mono \
		https://github.com/googlefonts/noto-cjk/raw/Sans${PORTVERSION}/Sans/SubsetOTF/KR/:subset
PKGNAMESUFFIX=	-sans-kr
DISTFILES=	LICENSE \
		${CJK_FONTS:S|$|:cjk|} \
		${MONO_FONTS:S|$|:mono|} \
		${SUBSET_FONTS:S|$|:subset|}
DIST_SUBDIR=	Noto/CJK/${PORTVERSION}
EXTRACT_ONLY=	# empty

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Noto Sans (Korean)
WWW=		https://www.google.com/get/noto/ \
		https://github.com/googlefonts/noto-cjk

LICENSE=	OFL11
LICENSE_FILE=	${DISTDIR}/${DIST_SUBDIR}/LICENSE

USES=		fonts

NO_ARCH=	yes
NO_BUILD=	yes

CJK_FONTS=	NotoSansCJKkr-Black.otf \
		NotoSansCJKkr-Bold.otf \
		NotoSansCJKkr-DemiLight.otf \
		NotoSansCJKkr-Light.otf \
		NotoSansCJKkr-Medium.otf \
		NotoSansCJKkr-Regular.otf \
		NotoSansCJKkr-Thin.otf
MONO_FONTS=	NotoSansMonoCJKkr-Bold.otf \
		NotoSansMonoCJKkr-Regular.otf
SUBSET_FONTS=	NotoSansKR-Black.otf \
		NotoSansKR-Bold.otf \
		NotoSansKR-DemiLight.otf \
		NotoSansKR-Light.otf \
		NotoSansKR-Medium.otf \
		NotoSansKR-Regular.otf \
		NotoSansKR-Thin.otf

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${INSTALL_DATA} ${CJK_FONTS} ${MONO_FONTS} ${SUBSET_FONTS} ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
