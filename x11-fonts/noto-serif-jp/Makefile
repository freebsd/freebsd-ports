PORTNAME=	noto
PORTVERSION=	2.003
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/notofonts/noto-cjk/raw/Serif${PORTVERSION}/Serif/ \
		https://github.com/notofonts/noto-cjk/raw/Serif${PORTVERSION}/Serif/OTF/Japanese/:cjk \
		https://github.com/notofonts/noto-cjk/raw/Serif${PORTVERSION}/Serif/SubsetOTF/JP/:subset
PKGNAMESUFFIX=	-serif-jp
DISTFILES=	LICENSE \
		${CJK_FONTS:S|$|:cjk|} \
		${SUBSET_FONTS:S|$|:subset|}
DIST_SUBDIR=	Noto/CJK/${PORTVERSION}
EXTRACT_ONLY=	# empty

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Noto Serif (Japanese)
WWW=		https://fonts.google.com/noto \
		https://github.com/notofonts/noto-cjk

LICENSE=	OFL11
LICENSE_FILE=	${DISTDIR}/${DIST_SUBDIR}/LICENSE

USES=		fonts

NO_ARCH=	yes
NO_BUILD=	yes

CJK_FONTS=	NotoSerifCJKjp-Black.otf \
		NotoSerifCJKjp-Bold.otf \
		NotoSerifCJKjp-ExtraLight.otf \
		NotoSerifCJKjp-Light.otf \
		NotoSerifCJKjp-Medium.otf \
		NotoSerifCJKjp-Regular.otf \
		NotoSerifCJKjp-SemiBold.otf
SUBSET_FONTS=	NotoSerifJP-Black.otf \
		NotoSerifJP-Bold.otf \
		NotoSerifJP-ExtraLight.otf \
		NotoSerifJP-Light.otf \
		NotoSerifJP-Medium.otf \
		NotoSerifJP-Regular.otf \
		NotoSerifJP-SemiBold.otf

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${INSTALL_DATA} ${CJK_FONTS} ${MONO_FONTS} ${SUBSET_FONTS} ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
