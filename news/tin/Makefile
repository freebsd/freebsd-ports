# New ports collection makefile for:	tin
# Version required:	1.2pl2
# Date created:		29 Jun 1995
# Whom:			peter@haywire.dialix.oz.au
#
# $Id$
#

DISTNAME=	tin-1.22
CATEGORIES+=	news
MASTER_SITES=	ftp://ftp.germany.eu.net/pub/news/newsreader/unix/tin/

post-install:
	gzip -9nf ${PREFIX}/man/man1/tin.1

.include <bsd.port.mk>
