# New ports collection makefile for:	mc
# Version required:	2.1
# Date created:		15 Jul 1995
# Whom:			torstenb@FreeBSD.ORG
#
# $Id$
#

DISTNAME=	mc-2.1
CATEGORIES=	utilities
MASTER_SITES=	ftp://prep.ai.mit.edu/pub/gnu/

GNU_CONFIGURE=	YES

post-install:
	@gzip -9nf ${PREFIX}/man/man1/mc.1

.include <bsd.port.mk>
