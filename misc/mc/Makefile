# New ports collection makefile for:	mc
# Version required:	4.1.11
# Date created:		15 Jul 1995
# Whom:			torstenb@FreeBSD.ORG
#
# $Id: Makefile,v 1.15 1997/11/29 09:18:18 vanilla Exp $
#

DISTNAME=	mc-4.1.11
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	utils/file/managers/mc

MAINTAINER=	vanilla@FreeBSD.ORG

GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--with-ncurses --without-edit --without-subshell
MAN1=		midc.1 mcedit.1
MAN8=		mcserv.8

post-install:
	@ ${RMDIR} ${PREFIX}/lib/mc/icons

.include <bsd.port.mk>
