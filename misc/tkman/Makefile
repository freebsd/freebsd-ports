# New ports collection makefile for:	tkman
# Version required:     1.6
# Date created:         27 Dec 1994
# Whom:                 thomas@ghpc8.ihf.rwth-aachen.de
#
# $Id: Makefile,v 1.6 1995/05/13 10:22:04 asami Exp $
#

DISTNAME=	tkman-1.6
CATEGORIES+=	utilities
MASTER_SITES=	ftp://ftp.cs.berkeley.edu/ucb/people/phelps/tcltk/
EXTRACT_SUFX=	.tar.Z

EXEC_DEPENDS=	wish:${PORTSDIR}/x11/tk \
		rman:${PORTSDIR}/utils/rman

# Restrictive copyright
NO_PACKAGE=	yes

.include <bsd.port.mk>
