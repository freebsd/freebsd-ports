# New ports collection makefile for:	arts++
# Date created:		Di   7 Nov 2000 19:48:50 CET
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	arts++
PORTVERSION=	1.1.a11
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	ftp://ftp.caida.org/pub/arts++/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A network data storage and analysis library from CAIDA

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--enable-shared
INSTALLS_SHLIB=	yes
USE_GCC=	2.95

MANL=		artsportagg.l artsports.l artsprotos.l artsnets.l artsdump.l \
		artsases.l artstoc.l artsagg.l artsprotoagg.l artsnetagg.l \
		artsasagg.l artsportms.l artsportmagg.l artsintfms.l \
		artsintfmagg.l artsnexthops.l artsnexthopagg.l artstos.l

post-configure:
	@${REINPLACE_CMD} -E -e "s,( gcc\*),\1 | g++\*,g" ${WRKSRC}/libtool

.include <bsd.port.mk>
