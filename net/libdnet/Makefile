# Created by: Dominic Marks <dominic.marks@btinternet.com>
# $FreeBSD$

PORTNAME=	libdnet
PORTVERSION=	1.11
PORTREVISION?=	3
CATEGORIES?=	net
MASTER_SITES=	SF/libdnet/libdnet/libdnet-${PORTVERSION}

MAINTAINER?=	onatan@gmail.com
COMMENT=	A simple interface to low level networking routines

GNU_CONFIGURE=	yes
USES=		gmake

.if !defined(LIBDNET_SLAVE)
CONFIGURE_ARGS+=	--without-python
USE_LDCONFIG=	yes
.endif

.include <bsd.port.pre.mk>

.if !defined(LIBDNET_SLAVE)

post-patch:
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|' ${WRKSRC}/configure

post-build:
	@cd ${WRKSRC}/src ; ${CC} ${CFLAGS} -shared -o libdnet.so .libs/addr-util.o .libs/addr.o .libs/blob.o .libs/ip-util.o .libs/ip6.o .libs/rand.o .libs/arp-bsd.o .libs/eth-bsd.o .libs/fw-pf.o .libs/intf.o .libs/ip.o .libs/route-bsd.o .libs/tun-bsd.o

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME}.so ${STAGEDIR}${PREFIX}/lib/
	@${LN} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}.so ${STAGEDIR}${PREFIX}/lib/${PORTNAME}.so.1
.endif

.include <bsd.port.post.mk>
