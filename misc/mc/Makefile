# New ports collection makefile for:	mc
# Version required:	3.0
# Date created:		15 Jul 1995
# Whom:			torstenb@FreeBSD.ORG
#
# $Id: Makefile,v 1.2 1995/09/27 22:57:28 torstenb Exp $
#

DISTNAME=	mc-3.0
CATEGORIES=	misc
MASTER_SITES=	ftp://prep.ai.mit.edu/pub/gnu/

GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--prefix=${PREFIX} --with-ncurses

STRIP=

post-install:
	@gzip -9nf ${PREFIX}/man/man1/mc.1 ${PREFIX}/man/man8/mc.8

.include <bsd.port.mk>
