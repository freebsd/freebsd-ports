# New ports collection makefile for:	c2html
# Version required:			0.4
# Date created:				28 October 1997
# Whom:					Andrey Zakhvatov
#
# $Id: Makefile,v 1.3 1999/05/07 05:27:30 mharo Exp $
#

DISTNAME=		c2html-0.6.1
CATEGORIES=		textproc www
MASTER_SITES=		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/www/converters

MAINTAINER=		mkamm@gmx.net

USE_AUTOCONF=		yes

MAN1=			c2html.1

post-install:
	strip ${PREFIX}/bin/c2html
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/c2html
.for file in AUTHORS NEWS README
	${INSTALL_MAN} ${WRKSRC}/${file} ${PREFIX}/share/doc/c2html
.endfor
.endif

.include <bsd.port.mk>
