# New ports collection makefile for:	zebra
# Version required:	SNAP 980401
# Date created:		So  31 Mai 1998 11:00:30 CEST
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $Id: Makefile,v 1.3 1998/06/03 06:30:49 andreas Exp $
#

DISTNAME=	zebra-980401
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.zebra.org/pub/zebra/
# you might need debugging, it's a developer release !
#CFLAGS+=	-g

MAINTAINER=	andreas@FreeBSD.org

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-confdir=${PREFIX}/etc/zebra

.include <bsd.port.mk>
