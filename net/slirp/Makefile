# New ports collection makefile for:	slirp
# Version required:	0.95f
# Date created:		25 Aug 1995
# Whom:			Alain Kalker <A.C.P.M.Kalker@student.utwente.nl>
#
# $Id: Makefile,v 1.4 1995/10/06 05:18:34 asami Exp $
#

DISTNAME=	slirp-0.95f
CATEGORIES+=	net
MASTER_SITES=	ftp://blitzen.canberra.edu.au/pub/slirp/ \
		ftp://freedom.wit.com/misc4/danjo/SLiRP/

MAINTAINER=	A.C.P.M.Kalker@student.utwente.nl

WRKSRC=		${WRKDIR}/slirp-0.95f/src
HAS_CONFIGURE=	yes

post-install:
.if !defined(NOMANCOMPRESS)
	gzip -9nf ${PREFIX}/man/man1/slirp.1
.endif

.include <bsd.port.mk>
