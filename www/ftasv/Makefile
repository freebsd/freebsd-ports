# Created by: Sylvio Cesar Teixeira <sylvio@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ftasv
PORTVERSION=	0.9.2
PORTREVISION=	3
CATEGORIES=	www
MASTER_SITES=	http://fabletech.com/${PORTNAME}-download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Is a commandline scoreboard viewer for the Apache server

LICENSE=	APACHE20

GNU_CONFIGURE=	yes
USE_APACHE=	22+

PLIST_FILES=	sbin/ftasv
SUB_FILES=	pkg-message
PORTDOCS=	AUTHORS COPYING ChangeLog README
OPTIONS_DEFINE=	DOCS

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for docs in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${docs} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
