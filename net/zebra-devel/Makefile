# New ports collection makefile for:	zebra
# Version required:	SNAP 980604
# Date created:		So  31 Mai 1998 11:00:30 CEST
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $Id: Makefile,v 1.4 1998/06/03 06:32:57 andreas Exp $
#

DISTNAME=	zebra-980604
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.zebra.org/pub/zebra/
# you might need debugging, it's a developer release !
#CFLAGS+=	-g

MAINTAINER=	andreas@FreeBSD.org

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--sysconfdir=${PREFIX}/etc/zebra

.include <bsd.port.mk>
