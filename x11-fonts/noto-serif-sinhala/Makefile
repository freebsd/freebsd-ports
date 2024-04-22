PORTNAME=	noto
PORTVERSION=	2.007
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/notofonts/sinhala/releases/download/NotoSerifSinhala-v${PORTVERSION}/
PKGNAMESUFFIX=	-serif-sinhala
DISTNAME=	NotoSerifSinhala-v${PORTVERSION}
DIST_SUBDIR=	Noto

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Noto Serif Sinhala
WWW=		https://fonts.google.com/noto \
		https://notofonts.github.io/ \
		https://github.com/notofonts/sinhala

LICENSE=	OFL11
#LICENSE_FILE=	${WRKSRC}/OFL.txt

USES=		fonts zip

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/NotoSerifSinhala/hinted/ttf/*.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
