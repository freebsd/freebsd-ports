PORTNAME=	noto
PORTVERSION=	2.001
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/googlefonts/noto-cjk/raw/NotoSansV2.001/
PKGNAMESUFFIX=	-kr
DISTFILES=	LICENSE \
		${NOTO_KR_FONTS}
DIST_SUBDIR=	Noto
EXTRACT_ONLY=	# empty

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Noto Fonts family (Korean)

LICENSE=	OFL11
LICENSE_FILE=	${DISTDIR}/${DIST_SUBDIR}/LICENSE

USES=		fonts

NO_ARCH=	yes
NO_BUILD=	yes

NOTO_KR_FONTS=	NotoSansCJKkr-Black.otf \
		NotoSansCJKkr-Bold.otf \
		NotoSansCJKkr-DemiLight.otf \
		NotoSansCJKkr-Light.otf \
		NotoSansCJKkr-Medium.otf \
		NotoSansCJKkr-Regular.otf \
		NotoSansCJKkr-Thin.otf \
		NotoSansKR-Black.otf \
		NotoSansKR-Bold.otf \
		NotoSansKR-DemiLight.otf \
		NotoSansKR-Light.otf \
		NotoSansKR-Medium.otf \
		NotoSansKR-Regular.otf \
		NotoSansKR-Thin.otf \
		NotoSansMonoCJKkr-Bold.otf \
		NotoSansMonoCJKkr-Regular.otf \
		NotoSerifCJKkr-Black.otf \
		NotoSerifCJKkr-Bold.otf \
		NotoSerifCJKkr-ExtraLight.otf \
		NotoSerifCJKkr-Light.otf \
		NotoSerifCJKkr-Medium.otf \
		NotoSerifCJKkr-Regular.otf \
		NotoSerifCJKkr-SemiBold.otf \
		NotoSerifKR-Black.otf \
		NotoSerifKR-Bold.otf \
		NotoSerifKR-ExtraLight.otf \
		NotoSerifKR-Light.otf \
		NotoSerifKR-Medium.otf \
		NotoSerifKR-Regular.otf \
		NotoSerifKR-SemiBold.otf

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${INSTALL_DATA} ${NOTO_KR_FONTS} ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
