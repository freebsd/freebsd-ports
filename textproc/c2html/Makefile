# New ports collection makefile for:	c2html
# Version required:			0.1
# Date created:				28 October 1997
# Whom:					Andrey Zakhvatov
#
# $Id$
#

DISTNAME=		c2html-0.1
CATEGORIES=		textproc www
MASTER_SITES=		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/www/converters

MAINTAINER=		andy@icc.surw.chel.su

MAN1=			c2html.1

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/c2html ${PREFIX}/bin
	@ ${INSTALL_MAN} ${WRKSRC}/c2html.1 ${PREFIX}/man/man1
	@ ${MKDIR} ${PREFIX}/share/doc/c2html
.for file in COPYING README
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/c2html
.endfor

.include <bsd.port.mk>
