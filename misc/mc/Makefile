# New ports collection makefile for:	mc
# Version required:	3.2.1
# Date created:		15 Jul 1995
# Whom:			torstenb@FreeBSD.ORG
#
# $Id: Makefile,v 1.4 1996/10/01 03:53:49 gpalmer Exp $
#

DISTNAME=	mc-3.2.1
CATEGORIES=	misc
MASTER_SITES=	ftp://prep.ai.mit.edu/pub/gnu/

GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--with-ncurses

STRIP=

post-install:
.if !defined(NOMANCOMPRESS)
	@gzip -9nf ${PREFIX}/man/man1/mc.1 ${PREFIX}/man/man8/mcserv.8
.endif

.include <bsd.port.mk>
