# New ports collection makefile for:	faces-1.6.1
# Version required:	1.6.1
# Date created:		09 December 96
# Whom:			Lars Koeller <Lars_Koeller@odie.physik2.uni-rostock.de>
#			Andreas Klemm <andreas@FreeBSD.ORG>
#
# $Id: Makefile,v 1.1.1.1 1996/12/14 22:27:51 andreas Exp $
#

DISTNAME=	faces-1.6.1
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.cs.indiana.edu/pub/faces/faces/ \
		ftp://odie.physik2.uni-rostock.de/pub/
EXTRACT_SUFX=	.tar.Z
		
MAINTAINER=	Lars_Koeller@odie.physik2.uni-rostock.de

WRKSRC=		$(WRKDIR)/faces

post-install:
	/sbin/ldconfig -m ${PREFIX}/lib

.include <bsd.port.mk>
