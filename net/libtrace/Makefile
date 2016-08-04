# Created by: Matt Peterson <matt@peterson.org>
# $FreeBSD$

PORTNAME=	libtrace
PORTVERSION=	3.0.19
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://research.wand.net.nz/software/libtrace/

MAINTAINER=	matt@peterson.org
COMMENT=	C library for network packet capture and processing

LIB_DEPENDS=	libpcap.so.1:net/libpcap

CONFIGURE_ARGS=	--with-libpcap=${LOCALBASE} \
		libtrace_doxygen=false

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		gmake libtool ncurses
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
