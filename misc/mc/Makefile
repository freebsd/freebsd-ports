# New ports collection makefile for:	mc
# Version required:	4.5.1
# Date created:		15 Jul 1995
# Whom:			torstenb@FreeBSD.ORG
#
# $Id: Makefile,v 1.25 1998/12/06 09:39:22 vanilla Exp $
#

DISTNAME=	mc-4.5.1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	utils/file/managers/mc/devel

MAINTAINER=	ports@FreeBSD.ORG

GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--with-ncurses --without-edit --with-dusum --disable-nls
CONFIGURE_ENV=	CCOPTS="$(CFLAGS)" INSTALL="$${INSTALL} -c"

MAN1=		midc.1
MAN8=		mcserv.8

.include <bsd.port.mk>
