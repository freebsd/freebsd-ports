# New ports collection makefile for:	cflowd
# Date created:		Di   7 Nov 2000 19:48:50 CET
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	cflowd
PORTVERSION=	2-1-b1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.caida.org/pub/cflowd/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	andreas@FreeBSD.org

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS+=--enable-shared --with-artspp=${PREFIX}

MANL=		cfdases.l cfdifmatrix.l cfdnets.l cfdnexthops.l \
		cfdportmatrix.l cfdprotos.l cfdtos.l flowdump.l flowwatch.l

.include <bsd.port.mk>
