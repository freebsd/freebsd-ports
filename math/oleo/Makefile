# New ports collection makefile for:	oleo
# Version required:	1.6
# Date created:		3 September 1994
# Whom:			mr
#
# $Id: Makefile,v 1.7 1996/03/10 00:05:48 asami Exp $
#

DISTNAME=	oleo-1.6
CATEGORIES+=	math
MASTER_SITES=	ftp://prep.ai.mit.edu/pub/gnu/

HAS_CONFIGURE=yes

post-install:
	install -c $(FILESDIR)/oleo.1 $(PREFIX)/man/man1
.if !defined(NOMANCOMPRESS)
	gzip -9nf $(PREFIX)/man/man1/oleo.1
.endif
	
.include <bsd.port.mk>
