# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	liberation-fonts-ttf
PORTVERSION=	2.1.0
PORTEPOCH=	2
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/liberationfonts/liberation-fonts/files/4178407/

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Liberation fonts from Red Hat to replace MS TTF fonts

LICENSE=	OFL11

USES=		fonts

NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	pkg-message

FONTNAME=	Liberation

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
