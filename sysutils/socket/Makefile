# New ports collection makefile for: socket
# Version required:     1.1
# Date created:         14 August 1996
# Whom:                 wosch
#
# $Id: Makefile,v 1.1.1.1 1996/08/24 20:37:44 wosch Exp $
#

DISTNAME=       socket-1.1
CATEGORIES+=	sysutils
MASTER_SITES=   ftp://freefall.freebsd.org/pub/FreeBSD/LOCAL_PORTS/

MAINTAINER=     wosch@FreeBSD.org

post-install:
.if !defined(NOMANCOMPRESS)
	gzip -9nf ${PREFIX}/man/man1/socket.1
.endif

.include <bsd.port.mk>
