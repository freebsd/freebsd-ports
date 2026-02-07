PORTNAME=	noto
PORTVERSION=	2.003
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/notofonts/noto-cjk/raw/Serif${PORTVERSION}/Serif/ \
		https://github.com/notofonts/noto-cjk/raw/Serif${PORTVERSION}/Serif/OTF/Korean/:cjk \
		https://github.com/notofonts/noto-cjk/raw/Serif${PORTVERSION}/Serif/SubsetOTF/KR/:subset
PKGNAMESUFFIX=	-serif-kr
DISTFILES=	LICENSE \
		${CJK_FONTS:S|$|:cjk|} \
		${SUBSET_FONTS:S|$|:subset|}
DIST_SUBDIR=	Noto/CJK/${PORTVERSION}
EXTRACT_ONLY=	# empty

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Noto Serif (Korean)
WWW=		https://fonts.google.com/noto \
		https://github.com/notofonts/noto-cjk

LICENSE=	OFL11
LICENSE_FILE=	${DISTDIR}/${DIST_SUBDIR}/LICENSE

USES=		fonts

NO_ARCH=	yes
NO_BUILD=	yes

CJK_FONTS=	NotoSerifCJKkr-Black.otf \
		NotoSerifCJKkr-Bold.otf \
		NotoSerifCJKkr-ExtraLight.otf \
		NotoSerifCJKkr-Light.otf \
		NotoSerifCJKkr-Medium.otf \
		NotoSerifCJKkr-Regular.otf \
		NotoSerifCJKkr-SemiBold.otf
SUBSET_FONTS=	NotoSerifKR-Black.otf \
		NotoSerifKR-Bold.otf \
		NotoSerifKR-ExtraLight.otf \
		NotoSerifKR-Light.otf \
		NotoSerifKR-Medium.otf \
		NotoSerifKR-Regular.otf \
		NotoSerifKR-SemiBold.otf

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${INSTALL_DATA} ${CJK_FONTS} ${MONO_FONTS} ${SUBSET_FONTS} ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
