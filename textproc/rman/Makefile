# New ports collection makefile for:	rman
# Version required:     2.4
# Date created:         27 Dec 1994
# Whom:                 thomas@ghpc8.ihf.rwth-aachen.de
#
# $Id: Makefile,v 1.8 1996/06/15 06:24:19 asami Exp $
#

DISTNAME=       rman-2.5a6
CATEGORIES+=	misc
MASTER_SITES=   ftp://ftp.cs.berkeley.edu/ucb/people/phelps/tcltk/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	thomas@ghpc8.ihf.rwth-aachen.de

NO_CDROM=	yes	# don't sell for profit

post-install:
.if !defined(NOMANCOMPRESS)
	gzip -9nf ${PREFIX}/man/man1/rman.1
.endif

.include <bsd.port.mk>
