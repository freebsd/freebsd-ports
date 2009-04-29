# New ports collection makefile for:	libdnet
# Date created:				15 April 2002
# Whom:			Dominic Marks <dominic.marks@btinternet.com>
#
# $FreeBSD$
#

PORTNAME=	libdnet
PORTVERSION=	1.11
PORTREVISION?=	3
CATEGORIES?=	net
MASTER_SITES=	SF

MAINTAINER?=	onatan@gmail.com
COMMENT=	A simple interface to low level networking routines

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

.if !defined(LIBDNET_SLAVE)
CONFIGURE_ARGS+=	--without-python
USE_LDCONFIG=	yes

MAN3=	dnet.3
MAN8=	dnet.8
.endif

.include <bsd.port.pre.mk>

.if !defined(LIBDNET_SLAVE)

post-patch:
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|' ${WRKSRC}/configure

post-build:
	@cd ${WRKSRC}/src ; ${CC} ${CFLAGS} -shared -o libdnet.so .libs/addr-util.o .libs/addr.o .libs/blob.o .libs/ip-util.o .libs/ip6.o .libs/rand.o .libs/arp-bsd.o .libs/eth-bsd.o .libs/fw-pf.o .libs/intf.o .libs/ip.o .libs/route-bsd.o .libs/tun-bsd.o

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME}.so ${PREFIX}/lib/
	@${LN} ${PREFIX}/lib/${PORTNAME}.so ${PREFIX}/lib/${PORTNAME}.so.1
.endif

.include <bsd.port.post.mk>
