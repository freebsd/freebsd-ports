# New ports collection makefile for:	rman
# Version required:     3.0.7
# Date created:         27 Dec 1994
# Whom:                 Thomas Gellekum <tg@FreeBSD.ORG>
#
# $Id: Makefile,v 1.19 1998/07/30 11:06:53 tg Exp $
#

DISTNAME=       rman-3.0.7
CATEGORIES=	textproc
MASTER_SITES=   ftp://ftp.cs.berkeley.edu/ucb/people/phelps/tcltk/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	tg@FreeBSD.ORG

NO_CDROM=	"License required"
MAN1=		rman.1

post-install:
	@strip ${PREFIX}/bin/rman

.include <bsd.port.mk>
