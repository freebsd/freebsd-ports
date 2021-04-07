PORTNAME=	noto
PORTVERSION=	2.001
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/googlefonts/noto-cjk/raw/NotoSansV2.001/
PKGNAMESUFFIX=	-tc
DISTFILES=	LICENSE \
		${NOTO_TC_FONTS}
DIST_SUBDIR=	Noto
EXTRACT_ONLY=	# empty

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Noto Fonts family (Traditional Chinese)

LICENSE=	OFL11
LICENSE_FILE=	${DISTDIR}/${DIST_SUBDIR}/LICENSE

USES=		fonts

NO_ARCH=	yes
NO_BUILD=	yes

NOTO_TC_FONTS=	NotoSansCJKtc-Black.otf \
		NotoSansCJKtc-Bold.otf \
		NotoSansCJKtc-DemiLight.otf \
		NotoSansCJKtc-Light.otf \
		NotoSansCJKtc-Medium.otf \
		NotoSansCJKtc-Regular.otf \
		NotoSansCJKtc-Thin.otf \
		NotoSansMonoCJKtc-Bold.otf \
		NotoSansMonoCJKtc-Regular.otf \
		NotoSansTC-Black.otf \
		NotoSansTC-Bold.otf \
		NotoSansTC-DemiLight.otf \
		NotoSansTC-Light.otf \
		NotoSansTC-Medium.otf \
		NotoSansTC-Regular.otf \
		NotoSansTC-Thin.otf \
		NotoSerifCJKtc-Black.otf \
		NotoSerifCJKtc-Bold.otf \
		NotoSerifCJKtc-ExtraLight.otf \
		NotoSerifCJKtc-Light.otf \
		NotoSerifCJKtc-Medium.otf \
		NotoSerifCJKtc-Regular.otf \
		NotoSerifCJKtc-SemiBold.otf \
		NotoSerifTC-Black.otf \
		NotoSerifTC-Bold.otf \
		NotoSerifTC-ExtraLight.otf \
		NotoSerifTC-Light.otf \
		NotoSerifTC-Medium.otf \
		NotoSerifTC-Regular.otf \
		NotoSerifTC-SemiBold.otf

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${INSTALL_DATA} ${NOTO_TC_FONTS} ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
