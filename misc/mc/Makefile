# New ports collection makefile for:	mc
# Version required:	3.2.1
# Date created:		15 Jul 1995
# Whom:			torstenb@FreeBSD.ORG
#
# $Id: Makefile,v 1.7 1996/11/11 05:49:48 obrien Exp $
#

DISTNAME=	mc-3.2.1
CATEGORIES=	misc
MASTER_SITES=	ftp://prep.ai.mit.edu/pub/gnu/

MAINTAINER=	torstenb@FreeBSD.ORG

GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--with-ncurses
STRIP=
MAN1=		mc.1
MAN8=		mcserv.8

post-install:
	@/usr/bin/strip ${PREFIX}/bin/mc ${PREFIX}/sbin/mcserv

.include <bsd.port.mk>
