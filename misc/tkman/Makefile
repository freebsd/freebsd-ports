# New ports collection makefile for:	tkman
# Version required:     1.6
# Date created:         27 Dec 1994
# Whom:                 thomas@ghpc8.ihf.rwth-aachen.de
#
# $Id: Makefile,v 1.5 1995/04/12 20:31:41 asami Exp $
#

DISTNAME=	tkman-1.6
CATEGORIES+=	x11
MASTER_SITES=	ftp://ftp.cs.berkeley.edu/ucb/people/phelps/tcltk/
EXTRACT_SUFX=	.tar.Z

EXEC_DEPENDS=	wish:${PORTSDIR}/x11/tk \
		rman:${PORTSDIR}/utils/rman

# Restrictive copyright
NO_PACKAGE=	yes

.include <bsd.port.mk>
