# New ports collection makefile for:	zebra
# Version required:	SNAP 981222
# Date created:		So  31 Mai 1998 11:00:30 CEST
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $Id: Makefile,v 1.10 1999/04/12 20:12:42 andreas Exp $
#

DISTNAME=	zebra-19990416
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.zebra.org/pub/zebra/
# you might need debugging, it's a developer release !
#CFLAGS+=	-g

MAINTAINER=	andreas@FreeBSD.ORG

BROKEN=		"bug: waiting for a fix from author"

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--sysconfdir=${PREFIX}/etc/zebra

.include <bsd.port.mk>
