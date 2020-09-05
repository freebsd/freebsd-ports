# $FreeBSD$

PORTNAME=	noto
PORTVERSION=	2.001
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/googlefonts/noto-cjk/raw/NotoSansV2.001/
PKGNAMESUFFIX=	-sc
DISTFILES=	NotoSansCJKsc-Black.otf \
		NotoSansCJKsc-Bold.otf \
		NotoSansCJKsc-DemiLight.otf \
		NotoSansCJKsc-Light.otf \
		NotoSansCJKsc-Medium.otf \
		NotoSansCJKsc-Regular.otf \
		NotoSansCJKsc-Thin.otf \
		NotoSansMonoCJKsc-Bold.otf \
		NotoSansMonoCJKsc-Regular.otf \
		NotoSansSC-Black.otf \
		NotoSansSC-Bold.otf \
		NotoSansSC-DemiLight.otf \
		NotoSansSC-Light.otf \
		NotoSansSC-Medium.otf \
		NotoSansSC-Regular.otf \
		NotoSansSC-Thin.otf \
		NotoSerifCJKsc-Black.otf \
		NotoSerifCJKsc-Bold.otf \
		NotoSerifCJKsc-ExtraLight.otf \
		NotoSerifCJKsc-Light.otf \
		NotoSerifCJKsc-Medium.otf \
		NotoSerifCJKsc-Regular.otf \
		NotoSerifCJKsc-SemiBold.otf \
		NotoSerifSC-Black.otf \
		NotoSerifSC-Bold.otf \
		NotoSerifSC-ExtraLight.otf \
		NotoSerifSC-Light.otf \
		NotoSerifSC-Medium.otf \
		NotoSerifSC-Regular.otf \
		NotoSerifSC-SemiBold.otf
DIST_SUBDIR=	Noto
EXTRACT_ONLY=	# empty

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Noto Fonts family (Simplified Chinese)

LICENSE=	OFL11

USES=		fonts

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${INSTALL_DATA} ${DISTFILES} ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
