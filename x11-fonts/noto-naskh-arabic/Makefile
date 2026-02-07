PORTNAME=	noto
PORTVERSION=	2.020
CATEGORIES=	x11-fonts
#MASTER_SITES=	https://github.com/notofonts/notofonts.github.io/raw/NotoNaskhArabic-v${PORTVERSION}/fonts/ \
#		https://github.com/notofonts/notofonts.github.io/raw/NotoNaskhArabic-v${PORTVERSION}/fonts/NotoNaskhArabic/hinted/ttf/:fonts
MASTER_SITES=	https://github.com/notofonts/notofonts.github.io/raw/40ff3d2422daeef927f4cebce11c1323e1d8e95b/fonts/ \
		https://github.com/notofonts/notofonts.github.io/raw/40ff3d2422daeef927f4cebce11c1323e1d8e95b/fonts/NotoNaskhArabic/hinted/ttf/:fonts
PKGNAMESUFFIX=	-naskh-arabic
DISTFILES=	LICENSE \
		${FONTS:S|$|:fonts|}
DIST_SUBDIR=	Noto/NaskhArabic/${PORTVERSION}
EXTRACT_ONLY=	# empty

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Noto Naskh Arabic
WWW=		https://fonts.google.com/noto \
		https://notofonts.github.io/ \
		https://github.com/notofonts/arabic \
		https://github.com/notofonts/notofonts.github.io/tree/main/fonts/NotoNaskhArabic

LICENSE=	OFL11
LICENSE_FILE=	${DISTDIR}/${DIST_SUBDIR}/LICENSE

USES=		fonts

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

FONTS=		NotoNaskhArabic-Bold.ttf \
		NotoNaskhArabic-Medium.ttf \
		NotoNaskhArabic-Regular.ttf \
		NotoNaskhArabic-SemiBold.ttf

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${INSTALL_DATA} ${FONTS} ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
