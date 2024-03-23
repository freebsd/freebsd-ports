PORTNAME=	noto
PORTVERSION=	2.008
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/notofonts/armenian/releases/download/NotoSerifArmenian-v${PORTVERSION}/
PKGNAMESUFFIX=	-serif-armenian
DISTNAME=	NotoSerifArmenian-v${PORTVERSION}
DIST_SUBDIR=	Noto

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Noto Serif Armenian
WWW=		https://fonts.google.com/noto \
		https://notofonts.github.io/ \
		https://github.com/notofonts/armenian

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/OFL.txt

USES=		fonts zip

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/NotoSerifArmenian/hinted/ttf/*.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
