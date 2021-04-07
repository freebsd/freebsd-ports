PORTNAME=	noto
PORTVERSION=	2.001
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/googlefonts/noto-cjk/raw/NotoSansV2.001/
PKGNAMESUFFIX=	-hk
DISTFILES=	LICENSE \
		${NOTO_HK_FONTS}
DIST_SUBDIR=	Noto
EXTRACT_ONLY=	# empty

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Noto Fonts family (Traditional Chinese Hong Kong)

LICENSE=	OFL11
LICENSE_FILE=	${DISTDIR}/${DIST_SUBDIR}/LICENSE

USES=		fonts

NO_ARCH=	yes
NO_BUILD=	yes

NOTO_HK_FONTS=	NotoSansCJKhk-Black.otf \
		NotoSansCJKhk-Bold.otf \
		NotoSansCJKhk-DemiLight.otf \
		NotoSansCJKhk-Light.otf \
		NotoSansCJKhk-Medium.otf \
		NotoSansCJKhk-Regular.otf \
		NotoSansCJKhk-Thin.otf \
		NotoSansHK-Black.otf \
		NotoSansHK-Bold.otf \
		NotoSansHK-DemiLight.otf \
		NotoSansHK-Light.otf \
		NotoSansHK-Medium.otf \
		NotoSansHK-Regular.otf \
		NotoSansHK-Thin.otf \
		NotoSansMonoCJKhk-Bold.otf \
		NotoSansMonoCJKhk-Regular.otf

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${INSTALL_DATA} ${NOTO_HK_FONTS} ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
