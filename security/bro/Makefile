# Ports collection makefile for:  bro
# Date created:			  Sat Feb 28, 1998
# Whom:				  David O'Brien (obrien@FreeBSD.org)
#
# $FreeBSD$
#

PORTNAME=	bro
PORTVERSION=	1.5.1
CATEGORIES=	security
MASTER_SITES=	ftp://bro-ids.org/

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	System for detecting Network Intruders in real-time

USE_PERL5=	yes

LIB_DEPENDS=	GeoIP:${PORTSDIR}/net/GeoIP

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-perftools \
		--disable-broccoli \
		--disable-broctl
CONFIGURE_ENV=	CFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
BROKEN=		does not package
.endif

.include <bsd.port.post.mk>
