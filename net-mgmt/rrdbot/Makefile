# Created by: Jeremy Chadwick <koitsu@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rrdbot
PORTVERSION=	0.9.7
PORTREVISION=	4
CATEGORIES=	net-mgmt
MASTER_SITES=	http://thewalter.net/stef/software/rrdbot/

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Threaded SNMP polling daemon which stores data in RRDs

BROKEN=		unfetchable

LIB_DEPENDS=	librrd.so:databases/rrdtool

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--libdir=${LOCALBASE}/lib --includedir=${LOCALBASE}/include \
			--datarootdir=${PREFIX}/share/rrdbot

SUB_FILES=	pkg-message
USE_RC_SUBR=	rrdbot

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.include <bsd.port.mk>
