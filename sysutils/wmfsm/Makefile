# New ports collection makefile for:	wmfsm
# Date created:				2 January 2001
# Whom:					Steven Enderle <panic@subphase.de>
#
# $FreeBSD$
#

PORTNAME=	wmfsm
PORTVERSION=	0.31
CATEGORIES=	sysutils windowmaker
MASTER_SITES=	http://netpedia.net/hosting/wmfsm/source/ \
		http://e.dyn.mdn.de/mirror/wmfsm/

MAINTAINER=	panic@subphase.de
COMMENT=	Displays filesystem usage of mountpoints in a nice WindowMaker dockapp

WRKSRC=		${WRKDIR}/${DISTNAME}/wmfsm

MAKEFILE=	Makefile.bsd
PLIST_FILES=	bin/wmfsm

USE_X_PREFIX=	yes
USE_XPM=	yes

.include <bsd.port.mk>
