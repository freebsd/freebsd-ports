# New ports collection makefile for:	zebra
# Version required:	SNAP 980604
# Date created:		So  31 Mai 1998 11:00:30 CEST
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $Id: Makefile,v 1.5 1998/06/04 17:03:12 itojun Exp $
#

DISTNAME=	zebra-980604
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.zebra.org/pub/zebra/

MAINTAINER=	andreas@FreeBSD.org

BROKEN=		package

# you might need debugging, it's a developer release !
#CFLAGS+=	-g
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=--sysconfdir=${PREFIX}/etc/zebra

.include <bsd.port.mk>
