# New ports collection makefile for:	pdksh
# Version required:	5.2.4 + patch 1, 2
# Date created:		23 May 1995
# Whom:			thomas@ghpc8.ihf.rwth-aachen.de
#
# $Id: Makefile,v 1.7 1996/02/15 16:25:29 tg Exp $
#

DISTNAME=	pdksh-5.2.4
PKGNAME=	pdksh-5.2.4.2
CATEGORIES+=	shells
MASTER_SITES=	ftp://ftp.cs.mun.ca/pub/pdksh/

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	pdksh-5.2.4.patch-1 pdksh-5.2.4.patch-2

MAINTAINER=	thomas@ghpc8.ihf.rwth-aachen.de

GNU_CONFIGURE=  yes

post-install:
.if !defined(NOMANCOMPRESS)
	gzip -9nf ${PREFIX}/man/man1/ksh.1
.endif

.include <bsd.port.mk>
