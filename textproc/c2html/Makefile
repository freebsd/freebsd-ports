# New ports collection makefile for:	c2html
# Version required:			0.4
# Date created:				28 October 1997
# Whom:					Andrey Zakhvatov
#
# $Id: Makefile,v 1.2 1999/04/02 03:58:53 steve Exp $
#

DISTNAME=		c2html-0.5
CATEGORIES=		textproc www
MASTER_SITES=		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/www/converters

MAINTAINER=		mkamm@gmx.net

USE_AUTOCONF=		yes

MAN1=			c2html.1

#this doesn't seem like it should be necessary
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/c2html ${PREFIX}/bin/c2html
	${INSTALL_MAN} ${WRKSRC}/c2html.1 ${PREFIX}/man/man1/c2html.1

post-install:
	strip ${PREFIX}/bin/c2html
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/c2html
.for file in AUTHORS NEWS README
	${INSTALL_MAN} ${WRKSRC}/${file} ${PREFIX}/share/doc/c2html
.endfor
.endif

.include <bsd.port.mk>
