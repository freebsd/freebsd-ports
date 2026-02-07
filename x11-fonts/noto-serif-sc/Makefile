PORTNAME=	noto
PORTVERSION=	2.003
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/notofonts/noto-cjk/raw/Serif${PORTVERSION}/Serif/ \
		https://github.com/notofonts/noto-cjk/raw/Serif${PORTVERSION}/Serif/OTF/SimplifiedChinese/:cjk \
		https://github.com/notofonts/noto-cjk/raw/Serif${PORTVERSION}/Serif/SubsetOTF/SC/:subset
PKGNAMESUFFIX=	-serif-sc
DISTFILES=	LICENSE \
		${CJK_FONTS:S|$|:cjk|} \
		${SUBSET_FONTS:S|$|:subset|}
DIST_SUBDIR=	Noto/CJK/${PORTVERSION}
EXTRACT_ONLY=	# empty

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Noto Serif (Simplified Chinese)
WWW=		https://fonts.google.com/noto \
		https://github.com/notofonts/noto-cjk

LICENSE=	OFL11
LICENSE_FILE=	${DISTDIR}/${DIST_SUBDIR}/LICENSE

USES=		fonts

NO_ARCH=	yes
NO_BUILD=	yes

CJK_FONTS=	NotoSerifCJKsc-Black.otf \
		NotoSerifCJKsc-Bold.otf \
		NotoSerifCJKsc-ExtraLight.otf \
		NotoSerifCJKsc-Light.otf \
		NotoSerifCJKsc-Medium.otf \
		NotoSerifCJKsc-Regular.otf \
		NotoSerifCJKsc-SemiBold.otf
SUBSET_FONTS=	NotoSerifSC-Black.otf \
		NotoSerifSC-Bold.otf \
		NotoSerifSC-ExtraLight.otf \
		NotoSerifSC-Light.otf \
		NotoSerifSC-Medium.otf \
		NotoSerifSC-Regular.otf \
		NotoSerifSC-SemiBold.otf

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${INSTALL_DATA} ${CJK_FONTS} ${MONO_FONTS} ${SUBSET_FONTS} ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
