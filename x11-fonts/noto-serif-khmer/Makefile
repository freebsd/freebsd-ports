PORTNAME=	noto
PORTVERSION=	2.004
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/notofonts/khmer/releases/download/NotoSerifKhmer-v${PORTVERSION}/
PKGNAMESUFFIX=	-serif-khmer
DISTNAME=	NotoSerifKhmer-v${PORTVERSION}
DIST_SUBDIR=	Noto

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Noto Serif Khmer
WWW=		https://fonts.google.com/noto \
		https://notofonts.github.io/ \
		https://github.com/notofonts/khmer

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/OFL.txt

USES=		fonts zip

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/NotoSerifKhmer/hinted/ttf/*.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
