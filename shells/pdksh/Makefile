# New ports collection makefile for:	pdksh
# Version required:	5.2.11
# Date created:		23 May 1995
# Whom:			thomas@ghpc8.ihf.rwth-aachen.de
#
# $Id: Makefile,v 1.13 1996/10/01 06:54:09 tg Exp $
#

DISTNAME=	pdksh-5.2.11
CATEGORIES+=	shells
MASTER_SITES=	ftp://ftp.cs.mun.ca/pub/pdksh/

MAINTAINER=	tg@freebsd.org

GNU_CONFIGURE=  yes

post-install:
.if !defined(NOMANCOMPRESS)
	gzip -9nf ${PREFIX}/man/man1/ksh.1
.endif

.include <bsd.port.mk>
