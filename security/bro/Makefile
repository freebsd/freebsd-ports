# Ports collection makefile for:  bro
# Date created:			  Sat Feb 28, 1998
# Whom:				  David O'Brien (obrien@FreeBSD.org)
#
# $FreeBSD$
#

PORTNAME=	bro
PORTVERSION=	1.5.3
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.bro-ids.org/

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	System for detecting Network Intruders in real-time

MAKE_JOBS_UNSAFE=	yes

USE_PERL5=	yes

LIB_DEPENDS=	GeoIP:${PORTSDIR}/net/GeoIP

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-perftools \
		--disable-broccoli \
		--disable-broctl \
		--enable-brov6
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-I${LOCALBASE}/include

.include <bsd.port.mk>
