# New ports collection makefile for:	tkman
# Version required:     1.7.3
# Date created:         27 Dec 1994
# Whom:                 thomas@ghpc8.ihf.rwth-aachen.de
#
# $Id: Makefile,v 1.7 1995/05/19 09:40:05 asami Exp $
#

DISTNAME=	tkman-1.7.3
CATEGORIES+=	utilities
MASTER_SITES=	ftp://ftp.cs.berkeley.edu/ucb/people/phelps/tcltk/
EXTRACT_SUFX=	.tar.Z

EXEC_DEPENDS=	wish4.0:${PORTSDIR}/x11/tk4 \
		rman:${PORTSDIR}/utils/rman

# Restrictive copyright
NO_PACKAGE=	yes

post-install:
.if !defined(NOMANCOMPRESS)
	gzip -9nf ${PREFIX}/man/man1/tkman.1
.endif

.include <bsd.port.mk>
