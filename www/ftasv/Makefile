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
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
USES=		apache:2.2+

PLIST_FILES=	sbin/ftasv
PORTDOCS=	AUTHORS ChangeLog README

OPTIONS_DEFINE=	DOCS

DOCS_SUB_FILES=	pkg-message

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for docs in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${docs} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
