# New ports collection makefile for:	mc
# Version required:	4.1.11
# Date created:		15 Jul 1995
# Whom:			torstenb@FreeBSD.ORG
#
# $Id: Makefile,v 1.14 1997/10/10 11:50:09 tg Exp $
#

DISTNAME=	mc-4.1.11
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	utils/file/managers/mc

MAINTAINER=	vanilla@MinJe.com.TW

GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--with-ncurses --without-edit --without-subshell
MAN1=		midc.1 mcedit.1
MAN8=		mcserv.8

post-install:
	@ ${RMDIR} ${PREFIX}/lib/mc/icons

.include <bsd.port.mk>
