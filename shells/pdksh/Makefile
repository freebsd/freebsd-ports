# New ports collection makefile for:	pdksh
# Version required:	5.2.3
# Date created:		23 May 1995
# Whom:			thomas@ghpc8.ihf.rwth-aachen.de
#
# $Id: Makefile,v 1.6 1995/07/29 09:57:17 asami Exp $
#

DISTNAME=	pdksh-5.2.4
CATEGORIES+=	shells
MASTER_SITES=	ftp://ftp.cs.mun.ca/pub/pdksh/

MAINTAINER=	thomas@ghpc8.ihf.rwth-aachen.de

PATCHFILES=	pdksh-5.2.4.patch-1 pdksh-5.2.4.patch-2
PATCH_SITES=	${MASTER_SITES}

GNU_CONFIGURE=  yes

post-install:
.if !defined(NOMANCOMPRESS)
	gzip -9nf ${PREFIX}/man/man1/ksh.1
.endif

.include <bsd.port.mk>
