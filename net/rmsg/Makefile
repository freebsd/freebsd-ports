# New ports collection makefile for:	rmsg
# Version required:	1.64
# Date created:		9 October 1995
# Whom:			torstenb@FreeBSD.ORG
#
# $Id$
#

DISTNAME=	rmsg-1.64
CATEGORIES=	networking
MASTER_SITES=	ftp://ftp.funet.fi/pub/networking/tcpip/ \
		ftp://proton.elka.pw.edu.pl/pub/unix/network/

WRKSRC=		${WRKDIR}/rmsg

post-install:
	gzip -9nf ${PREFIX}/man/man1/rmsg.1 ${PREFIX}/man/man8/rmsgd.8

.include <bsd.port.mk>
