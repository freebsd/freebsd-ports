# New ports collection makefile for:	mc
# Version required:	4.1.35
# Date created:		15 Jul 1995
# Whom:			torstenb@FreeBSD.ORG
#
# $Id: Makefile,v 1.23 1998/09/18 02:29:28 vanilla Exp $
#

DISTNAME=	mc-4.1.35
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	utils/file/managers/mc

MAINTAINER=	ports@FreeBSD.ORG

VERSION!=	sysctl -n kern.osreldate
.if ${VERSION} < 300000
BROKEN=		mountlist.c
.endif

GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--with-ncurses --without-edit --with-dusum --disable-nls
CONFIGURE_ENV=	CCOPTS="$(CFLAGS)" INSTALL="$${INSTALL} -c"

MAN1=		midc.1
MAN8=		mcserv.8

.include <bsd.port.mk>
