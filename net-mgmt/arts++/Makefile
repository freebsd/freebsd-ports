# New ports collection makefile for:	arts++
# Date created:		Di   7 Nov 2000 19:48:50 CET
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	arts++
PORTVERSION=	1-1-a8
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.caida.org/pub/arts++/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	andreas@FreeBSD.org

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_NEWGCC=	yes
CONFIGURE_ARGS+=--enable-shared

MANL=		artsportagg.l artsports.l artsprotos.l artsnets.l artsdump.l \
		artsases.l artstoc.l artsagg.l artsprotoagg.l artsnetagg.l \
		artsasagg.l artsportms.l artsportmagg.l artsintfms.l \
		artsintfmagg.l artsnexthops.l artsnexthopagg.l artstos.l

.include <bsd.port.mk>
