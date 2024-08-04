PORTNAME=	noto
PORTVERSION=	2.003
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/notofonts/noto-cjk/raw/Serif${PORTVERSION}/Serif/ \
		https://github.com/notofonts/noto-cjk/raw/Serif${PORTVERSION}/Serif/OTF/TraditionalChinese/:cjk \
		https://github.com/notofonts/noto-cjk/raw/Serif${PORTVERSION}/Serif/SubsetOTF/TC/:subset
PKGNAMESUFFIX=	-serif-tc
DISTFILES=	LICENSE \
		${CJK_FONTS:S|$|:cjk|} \
		${SUBSET_FONTS:S|$|:subset|}
DIST_SUBDIR=	Noto/CJK/${PORTVERSION}
EXTRACT_ONLY=	# empty

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Noto Serif (Traditional Chinese)
WWW=		https://fonts.google.com/noto \
		https://github.com/notofonts/noto-cjk

LICENSE=	OFL11
LICENSE_FILE=	${DISTDIR}/${DIST_SUBDIR}/LICENSE

USES=		fonts

NO_ARCH=	yes
NO_BUILD=	yes

CJK_FONTS=	NotoSerifCJKtc-Black.otf \
		NotoSerifCJKtc-Bold.otf \
		NotoSerifCJKtc-ExtraLight.otf \
		NotoSerifCJKtc-Light.otf \
		NotoSerifCJKtc-Medium.otf \
		NotoSerifCJKtc-Regular.otf \
		NotoSerifCJKtc-SemiBold.otf
SUBSET_FONTS=	NotoSerifTC-Black.otf \
		NotoSerifTC-Bold.otf \
		NotoSerifTC-ExtraLight.otf \
		NotoSerifTC-Light.otf \
		NotoSerifTC-Medium.otf \
		NotoSerifTC-Regular.otf \
		NotoSerifTC-SemiBold.otf

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${INSTALL_DATA} ${CJK_FONTS} ${MONO_FONTS} ${SUBSET_FONTS} ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
