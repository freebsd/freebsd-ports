# New ports collection makefile for:	buffer
# Version required:     1.17
# Date created:         17 Nov 1995
# Whom:                 markm
#
# $Id: Makefile,v 1.3 1995/11/20 13:43:45 asami Exp $
#

DISTNAME=       buffer-1.17
CATEGORIES+=	misc
MASTER_SITES=   ftp://ftp.sun.ac.za/pub/unix/misc/

MAINTAINER=	markm@FreeBSD.ORG

NO_WRKSUBDIR=	yes

post-install:
.if !defined(NOMANCOMPRESS)
	gzip -9nf ${PREFIX}/man/manl/buffer.l
.endif

.include <bsd.port.mk>
