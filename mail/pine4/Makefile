# New ports collection makefile for:	pine
# Version required:	3.95
# Date created:		03 September 1994
# Whom:			mr
#
# $Id: Makefile,v 1.12 1996/07/17 03:57:57 asami Exp $
#

DISTNAME=	pine3.95
PKGNAME=	pine-3.95
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.cac.washington.edu/pine/

post-install:
.if !defined(NOMANCOMPRESS)
	gzip -9nf ${PREFIX}/man/man1/pine.1
	gzip -9nf ${PREFIX}/man/man1/pico.1
	gzip -9nf ${PREFIX}/man/man1/pilot.1
	gzip -9nf ${PREFIX}/man/man8/imapd.8c
	gzip -9nf ${PREFIX}/man/man8/ipopd.8c
.endif

.include <bsd.port.mk>
