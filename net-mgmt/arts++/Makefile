# New ports collection makefile for:	arts++
# Date created:		Di   7 Nov 2000 19:48:50 CET
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	arts++
PORTVERSION=	1.1.a8
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	ftp://ftp.caida.org/pub/arts++/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/./-/g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A network data storage and analysis library from CAIDA

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS+=--enable-shared
INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes

MANL=		artsportagg.l artsports.l artsprotos.l artsnets.l artsdump.l \
		artsases.l artstoc.l artsagg.l artsprotoagg.l artsnetagg.l \
		artsasagg.l artsportms.l artsportmagg.l artsintfms.l \
		artsintfmagg.l artsnexthops.l artsnexthopagg.l artstos.l

.include <bsd.port.pre.mk>


post-patch:
	cd ${WRKSRC}/classes/src; \
		${REINPLACE_CMD} -e "s,<strstream.h>,<strstream>," \
		ArtsBgp4AsPathSegment.cc ArtsIfIndexSelectionSet.lex \
		ArtsObjectTypeSelectionSet.lex  ArtsTimeIntervalSelectionSet.lex

.include <bsd.port.post.mk>
