# New ports collection makefile for:	tkman
# Version required:     1.8b5
# Date created:         27 Dec 1994
# Whom:                 thomas@ghpc8.ihf.rwth-aachen.de
#
# $Id: Makefile,v 1.17 1996/10/21 06:46:52 tg Exp $
#

DISTNAME=	tkman-1.8b5
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.cs.berkeley.edu/ucb/people/phelps/tcltk/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	tg@freebsd.org

LIB_DEPENDS=	tk41\\.1\\.:${PORTSDIR}/x11/tk41
RUN_DEPENDS=	rman:${PORTSDIR}/misc/rman \
		glimpse:${PORTSDIR}/misc/glimpse

NO_CDROM=	yes	# Don't sell for profit

post-install:
.if !defined(NOMANCOMPRESS)
	gzip -9nf ${PREFIX}/man/man1/tkman.1
.endif

.include <bsd.port.mk>
