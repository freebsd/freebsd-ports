# New ports collection makefile for:	tkman
# Version required:     1.8
# Date created:         27 Dec 1994
# Whom:                 thomas@ghpc8.ihf.rwth-aachen.de
#
# $Id: Makefile,v 1.20 1996/11/17 09:06:37 obrien Exp $
#

DISTNAME=	tkman-1.8
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.cs.berkeley.edu/ucb/people/phelps/tcltk/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	tg@freebsd.org

LIB_DEPENDS=	tk41\\.1\\.:${PORTSDIR}/x11/tk41
RUN_DEPENDS=	rman:${PORTSDIR}/misc/rman \
		glimpse:${PORTSDIR}/misc/glimpse

NO_CDROM=	"Don't sell for profit"
MAN1=		tkman.1

.include <bsd.port.mk>
