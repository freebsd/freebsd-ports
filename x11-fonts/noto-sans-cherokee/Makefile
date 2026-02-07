PORTNAME=	noto
PORTVERSION=	2.001
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/notofonts/notofonts.github.io/raw/NotoSansCherokee-v${PORTVERSION}/fonts/ \
		https://github.com/notofonts/notofonts.github.io/raw/NotoSansCherokee-v${PORTVERSION}/fonts/NotoSansCherokee/hinted/ttf/:fonts
PKGNAMESUFFIX=	-sans-cherokee
DISTFILES=	LICENSE \
		${FONTS:S|$|:fonts|}
DIST_SUBDIR=	Noto/SansCherokee/${PORTVERSION}
EXTRACT_ONLY=	# empty

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Noto Sans Cherokee
WWW=		https://fonts.google.com/noto \
		https://notofonts.github.io/ \
		https://github.com/notofonts/cherokee \
		https://github.com/notofonts/notofonts.github.io/tree/main/fonts/NotoSansCherokee

LICENSE=	OFL11
LICENSE_FILE=	${DISTDIR}/${DIST_SUBDIR}/LICENSE

USES=		fonts

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

FONTS=		NotoSansCherokee-Black.ttf \
		NotoSansCherokee-Bold.ttf \
		NotoSansCherokee-ExtraBold.ttf \
		NotoSansCherokee-ExtraLight.ttf \
		NotoSansCherokee-Light.ttf \
		NotoSansCherokee-Medium.ttf \
		NotoSansCherokee-Regular.ttf \
		NotoSansCherokee-SemiBold.ttf \
		NotoSansCherokee-Thin.ttf

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${INSTALL_DATA} ${FONTS} ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
