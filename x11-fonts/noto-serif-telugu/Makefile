PORTNAME=	noto
PORTVERSION=	2.005
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/notofonts/notofonts.github.io/raw/NotoSerifTelugu-v${PORTVERSION}/fonts/ \
		https://github.com/notofonts/notofonts.github.io/raw/NotoSerifTelugu-v${PORTVERSION}/fonts/NotoSerifTelugu/hinted/ttf/:fonts
PKGNAMESUFFIX=	-serif-telugu
DISTFILES=	LICENSE \
		${FONTS:S|$|:fonts|}
DIST_SUBDIR=	Noto/SerifTelugu/${PORTVERSION}
EXTRACT_ONLY=	# empty

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Noto Serif Telugu
WWW=		https://fonts.google.com/noto \
		https://notofonts.github.io/ \
		https://github.com/notofonts/telugu \
		https://github.com/notofonts/notofonts.github.io/tree/main/fonts/NotoSerifTelugu

LICENSE=	OFL11
LICENSE_FILE=	${DISTDIR}/${DIST_SUBDIR}/LICENSE

USES=		fonts

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

FONTS=		NotoSerifTelugu-Black.ttf \
		NotoSerifTelugu-Bold.ttf \
		NotoSerifTelugu-ExtraBold.ttf \
		NotoSerifTelugu-ExtraLight.ttf \
		NotoSerifTelugu-Light.ttf \
		NotoSerifTelugu-Medium.ttf \
		NotoSerifTelugu-Regular.ttf \
		NotoSerifTelugu-SemiBold.ttf \
		NotoSerifTelugu-Thin.ttf

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${INSTALL_DATA} ${FONTS} ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
