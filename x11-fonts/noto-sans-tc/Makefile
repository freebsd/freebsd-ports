PORTNAME=	noto
PORTVERSION=	2.004
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/googlefonts/noto-cjk/raw/Sans${PORTVERSION}/ \
		https://github.com/googlefonts/noto-cjk/raw/Sans${PORTVERSION}/Sans/OTF/TraditionalChinese/:cjk \
		https://github.com/googlefonts/noto-cjk/raw/Sans${PORTVERSION}/Sans/Mono/:mono \
		https://github.com/googlefonts/noto-cjk/raw/Sans${PORTVERSION}/Sans/SubsetOTF/TC/:subset
PKGNAMESUFFIX=	-sans-tc
DISTFILES=	LICENSE \
		${CJK_FONTS:S|$|:cjk|} \
		${MONO_FONTS:S|$|:mono|} \
		${SUBSET_FONTS:S|$|:subset|}
DIST_SUBDIR=	Noto/CJK/${PORTVERSION}
EXTRACT_ONLY=	# empty

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Noto Sans (Traditional Chinese)
WWW=		https://www.google.com/get/noto/ \
		https://github.com/googlefonts/noto-cjk

LICENSE=	OFL11
LICENSE_FILE=	${DISTDIR}/${DIST_SUBDIR}/LICENSE

USES=		fonts

NO_ARCH=	yes
NO_BUILD=	yes

CJK_FONTS=	NotoSansCJKtc-Black.otf \
		NotoSansCJKtc-Bold.otf \
		NotoSansCJKtc-DemiLight.otf \
		NotoSansCJKtc-Light.otf \
		NotoSansCJKtc-Medium.otf \
		NotoSansCJKtc-Regular.otf \
		NotoSansCJKtc-Thin.otf
MONO_FONTS=	NotoSansMonoCJKtc-Bold.otf \
		NotoSansMonoCJKtc-Regular.otf
SUBSET_FONTS=	NotoSansTC-Black.otf \
		NotoSansTC-Bold.otf \
		NotoSansTC-DemiLight.otf \
		NotoSansTC-Light.otf \
		NotoSansTC-Medium.otf \
		NotoSansTC-Regular.otf \
		NotoSansTC-Thin.otf

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${INSTALL_DATA} ${CJK_FONTS} ${MONO_FONTS} ${SUBSET_FONTS} ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
