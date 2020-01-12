# $FreeBSD$

PORTNAME=	victor-mono
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.0
CATEGORIES=	x11-fonts
MASTER_SITES=	https://rubjo.github.io/${PORTNAME}/
PKGNAMESUFFIX=	-ttf
DISTNAME=	VictorMonoAll

MAINTAINER=	vulcan@wired.sh
COMMENT=	Programming font with cursive italics and ligatures

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		fonts zip
FONTNAME=	VictorMono

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/TTF/*.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
