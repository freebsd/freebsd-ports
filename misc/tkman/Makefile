# New ports collection makefile for:	tkman
# Version required:     1.7.3
# Date created:         27 Dec 1994
# Whom:                 thomas@ghpc8.ihf.rwth-aachen.de
#
# $Id: Makefile,v 1.10 1995/11/26 10:48:46 asami Exp $
#

DISTNAME=	tkman-1.7.3
CATEGORIES+=	misc
MASTER_SITES=	ftp://ftp.cs.berkeley.edu/ucb/people/phelps/tcltk/
EXTRACT_SUFX=	.tar.Z

LIB_DEPENDS=	tk40\\.1\\.:${PORTSDIR}/x11/tk4
RUN_DEPENDS=	rman:${PORTSDIR}/misc/rman

# Restrictive copyright
NO_PACKAGE=	yes

post-install:
.if !defined(NOMANCOMPRESS)
	gzip -9nf ${PREFIX}/man/man1/tkman.1
.endif

.include <bsd.port.mk>
