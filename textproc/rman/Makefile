# New ports collection makefile for:	rman
# Version required:     3.0.3a11
# Date created:         27 Dec 1994
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $Id: Makefile,v 1.14 1997/05/30 19:59:34 max Exp $
#

DISTNAME=       rman-3.0.3a11
CATEGORIES=	textproc
MASTER_SITES=   ftp://ftp.cs.berkeley.edu/ucb/people/phelps/tcltk/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	tg@FreeBSD.org

NO_CDROM=	"Don't sell for profit"
MAN1=		rman.1

post-install:
	@strip ${PREFIX}/bin/rman

.include <bsd.port.mk>
