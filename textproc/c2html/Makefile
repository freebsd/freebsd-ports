# New ports collection makefile for:	c2html
# Version required:			0.4
# Date created:				28 October 1997
# Whom:					Andrey Zakhvatov
#
# $Id: Makefile,v 1.1.1.1 1997/11/22 00:30:17 jseger Exp $
#

DISTNAME=		c2html-0.4
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
