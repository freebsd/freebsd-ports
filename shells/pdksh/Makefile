# New ports collection makefile for:	pdksh
# Version required:	5.2.3
# Date created:		23 May 1995
# Whom:			thomas@ghpc8.ihf.rwth-aachen.de
#
# $Id: Makefile,v 1.5 1995/04/11 19:26:34 asami Exp $
#

DISTNAME=	pdksh-5.2.3
CATEGORIES+=	shells
MASTER_SITES=	ftp://ftp.cs.mun.ca/pub/pdksh/

MAINTAINER=	thomas@ghpc8.ihf.rwth-aachen.de

GNU_CONFIGURE=  yes

post-install:
	gzip -9nf ${PREFIX}/man/man1/ksh.1

.include <bsd.port.mk>
