# New ports collection makefile for:	ntp
# Version required:	4.0.72
# Date created:		Di   5 Mai 1998 21:31:03 CEST
# Whom:			andreas
#
# $Id$
#

DISTNAME=	ntp-4.0.72g
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.udel.edu/pub/ntp/testing/

MAINTAINER=	andreas@FreeBSD.ORG

GNU_CONFIGURE=	yes

post-install:
	${MKDIR} ${PREFIX}/share/doc/ntp
	${CP} -r ${WRKSRC}/html/* ${PREFIX}/share/doc/ntp

.include <bsd.port.mk>
