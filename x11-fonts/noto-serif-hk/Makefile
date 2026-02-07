PORTNAME=	noto
PORTVERSION=	2.003
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/notofonts/noto-cjk/raw/Serif${PORTVERSION}/Serif/ \
		https://github.com/notofonts/noto-cjk/raw/Serif${PORTVERSION}/Serif/OTF/TraditionalChineseHK/:cjk \
		https://github.com/notofonts/noto-cjk/raw/Serif${PORTVERSION}/Serif/SubsetOTF/HK/:subset
PKGNAMESUFFIX=	-serif-hk
DISTFILES=	LICENSE \
		${CJK_FONTS:S|$|:cjk|} \
		${SUBSET_FONTS:S|$|:subset|}
DIST_SUBDIR=	Noto/CJK/${PORTVERSION}
EXTRACT_ONLY=	# empty

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Noto Serif (Traditional Chinese Hong Kong)
WWW=		https://fonts.google.com/noto \
		https://github.com/notofonts/noto-cjk

LICENSE=	OFL11
LICENSE_FILE=	${DISTDIR}/${DIST_SUBDIR}/LICENSE

USES=		fonts

NO_ARCH=	yes
NO_BUILD=	yes

CJK_FONTS=	NotoSerifCJKhk-Black.otf \
		NotoSerifCJKhk-Bold.otf \
		NotoSerifCJKhk-ExtraLight.otf \
		NotoSerifCJKhk-Light.otf \
		NotoSerifCJKhk-Medium.otf \
		NotoSerifCJKhk-Regular.otf \
		NotoSerifCJKhk-SemiBold.otf
SUBSET_FONTS=	NotoSerifHK-Black.otf \
		NotoSerifHK-Bold.otf \
		NotoSerifHK-ExtraLight.otf \
		NotoSerifHK-Light.otf \
		NotoSerifHK-Medium.otf \
		NotoSerifHK-Regular.otf \
		NotoSerifHK-SemiBold.otf

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${INSTALL_DATA} ${CJK_FONTS} ${MONO_FONTS} ${SUBSET_FONTS} ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
