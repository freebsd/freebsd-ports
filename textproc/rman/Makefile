# New ports collection makefile for:	rman
# Version required:     2.4
# Date created:         27 Dec 1994
# Whom:                 thomas@ghpc8.ihf.rwth-aachen.de
#
# $Id: Makefile,v 1.4 1995/04/15 03:45:54 asami Exp $
#

DISTNAME=       rman-2.4
CATEGORIES+=	utilities
MASTER_SITES=   ftp://ftp.cs.berkeley.edu/ucb/people/phelps/tcltk/
EXTRACT_SUFX=	.tar.Z

# Restrictive copyright
NO_PACKAGE=	yes

post-install:
.if !defined(NOMANCOMPRESS)
	gzip -9nf ${PREFIX}/man/man1/rman.1
.endif

.include <bsd.port.mk>
