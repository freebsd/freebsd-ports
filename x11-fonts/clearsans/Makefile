# $FreeBSD$

PORTNAME=	clearsans
PORTVERSION=	1.00
CATEGORIES=	x11-fonts
MASTER_SITES=	https://01.org/sites/default/files/downloads/

MAINTAINER=	rakuco@FreeBSD.org
COMMENT=	Versatile OpenType font for screen, print, and Web

LICENSE=	APACHE20

USES=		zip
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

FONTDIR=	${STAGEDIR}${PREFIX}/lib/X11/fonts/${PORTNAME}

do-install:
	${MKDIR} ${FONTDIR}
	cd ${WRKSRC}/TTF && \
		${INSTALL_DATA} *.ttf ${FONTDIR}

.include <bsd.port.mk>
