# New ports collection makefile for:	micq
# Version required:			0.4.0
# Date created:				11 Oct 1998
# Whom:					mph
#
# $Id: Makefile,v 1.4 1999/01/07 18:38:53 mph Exp $
#

DISTNAME=	micq-0.4.0
CATEGORIES=	net
MASTER_SITES=	ftp://micq.chatzone.org/pub/micq/V0.4.0/
EXTRACT_SUFX=	.tgz

MAINTAINER=	mph@freebsd.org

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/micq ${PREFIX}/bin
.if !defined(NOPORTDOCS)
		${MKDIR} ${PREFIX}/share/doc/micq
.for file in README TODO WISHLIST commands.txt
		${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/micq
.endfor
.endif

.include <bsd.port.mk>
