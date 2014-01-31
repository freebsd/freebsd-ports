# Created by: Matt Peterson <matt@peterson.org>
# $FreeBSD$

PORTNAME=	libtrace
PORTVERSION=	3.0.15
CATEGORIES=	net
MASTER_SITES=	http://research.wand.net.nz/software/libtrace/

MAINTAINER=	matt@peterson.org
COMMENT=	C library for network packet capture and processing

LIB_DEPENDS=	pcap:${PORTSDIR}/net/libpcap

CONFIGURE_ARGS=	--with-libpcap=${LOCALBASE}

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		gmake
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|g' \
	${WRKSRC}/configure

.include <bsd.port.mk>
