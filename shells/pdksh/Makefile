# New ports collection makefile for:	pdksh
# Version required:	5.2.5
# Date created:		23 May 1995
# Whom:			thomas@ghpc8.ihf.rwth-aachen.de
#
# $Id: Makefile,v 1.8 1996/02/16 10:45:03 asami Exp $
#

DISTNAME=	pdksh-5.2.5
CATEGORIES+=	shells
MASTER_SITES=	ftp://ftp.cs.mun.ca/pub/pdksh/

MAINTAINER=	thomas@ghpc8.ihf.rwth-aachen.de

GNU_CONFIGURE=  yes

post-install:
.if !defined(NOMANCOMPRESS)
	gzip -9nf ${PREFIX}/man/man1/ksh.1
.endif

.include <bsd.port.mk>
