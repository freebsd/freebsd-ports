# New ports collection makefile for:	mh
# Version required:	6.8.3
# Date created:		Oct 4, 1994
# Whom:			pst
#
# $Id: Makefile,v 1.4 1995/04/12 02:03:21 asami Exp $
#

DISTNAME=	mh-6.8.3
CATEGORIES+=	mail
MASTER_SITES=	ftp://ftp.ics.uci.edu/pub/mh/tar/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	markm@FreeBSD.ORG

post-install:
	ldconfig -m ${PREFIX}/lib

.include <bsd.port.mk>
