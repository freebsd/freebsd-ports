# New ports collection makefile for:	ntp
# Version required:	4.0.72
# Date created:		Di   5 Mai 1998 21:31:03 CEST
# Whom:			andreas
#
# $Id: Makefile,v 1.2 1998/07/18 15:06:36 andreas Exp $
#

DISTNAME=	ntp-4.0.90h
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.udel.edu/pub/ntp/testing/

MAINTAINER=	andreas@FreeBSD.ORG

GNU_CONFIGURE=	yes

post-install:
	${MKDIR} ${PREFIX}/share/doc/ntp
	${CP} -r ${WRKSRC}/html/* ${PREFIX}/share/doc/ntp

.include <bsd.port.mk>
