# New ports collection makefile for:	mc
# Version required:	4.1.31
# Date created:		15 Jul 1995
# Whom:			torstenb@FreeBSD.ORG
#
# $Id: Makefile,v 1.19 1998/04/11 20:02:34 vanilla Exp $
#

DISTNAME=	mc-4.1.31
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	utils/file/managers/mc/devel

MAINTAINER=	ports@FreeBSD.ORG

GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--with-ncurses --without-edit --without-subshell --disable-nls
CONFIGURE_ENV=	INSTALL="/usr/bin/install -c"
MAKE_ENV=	CCOPTS="$(CFLAGS)"
MAN1=		midc.1
MAN8=		mcserv.8

.include <bsd.port.mk>
