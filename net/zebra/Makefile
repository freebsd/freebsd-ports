# New ports collection makefile for:	zebra
# Version required:	SNAP 981222
# Date created:		So  31 Mai 1998 11:00:30 CEST
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $Id: Makefile,v 1.8 1999/01/07 06:28:35 itojun Exp $
#

DISTNAME=	zebra-981222
PKGNAME=	zebra-19981222
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.zebra.org/pub/zebra/
# you might need debugging, it's a developer release !
#CFLAGS+=	-g

MAINTAINER=	andreas@FreeBSD.ORG

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--sysconfdir=${PREFIX}/etc/zebra

.include <bsd.port.mk>
