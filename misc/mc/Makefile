# New ports collection makefile for:	mc
# Version required:	4.0
# Date created:		15 Jul 1995
# Whom:			torstenb@FreeBSD.ORG
#
# $Id: Makefile,v 1.10 1997/05/25 21:24:32 torstenb Exp $
#

DISTNAME=	mc-4.0
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	utils/file/managers/mc

MAINTAINER=	ports@FreeBSD.org

GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--with-ncurses --without-edit --without-subshell
MAN1=		mc.1 mcedit.1
MAN8=		mcserv.8

.include <bsd.port.mk>
