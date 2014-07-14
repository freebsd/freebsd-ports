# Created by: Max Khon <fjoe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fonulator
PORTVERSION=	2.0.1
PORTREVISION=	2
CATEGORIES=	net net-mgmt
MASTER_SITES=	http://support.red-fone.com/fonulator/

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	FoneBRIDGE configuration utility

BUILD_DEPENDS=	${LOCALBASE}/lib/libargtable2.a:${PORTSDIR}/devel/argtable\
		${LOCALBASE}/lib/libfb.a:${PORTSDIR}/net/libfb
LIB_DEPENDS=	libnet.so:${PORTSDIR}/net/libnet

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include ${LIBNET_CPPFLAGS}
LDFLAGS+=	${LIBNET_LIBS:N-l*}
CONFIGURE_ARGS=	--disable-shared

LIBNET_CONFIG=	${LOCALBASE}/bin/libnet11-config

PLIST_FILES=	bin/fonulator \
		man/man1/fonulator.1.gz

post-patch:
	@${REINPLACE_CMD}\
	    -e 's,/usr/lib/libargtable2.a,${LOCALBASE}/lib/libargtable2.a,'\
	    -e 's,/usr/lib/libnet.a,${LIBNET_LIBS:N-l*:S,-L,,}/libnet.a,'\
	    ${WRKSRC}/Makefile.in ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's,/etc/redfone.conf,${LOCALBASE}/etc/redfone.conf,'\
	    ${WRKSRC}/fonulator.c ${WRKSRC}/fonulator.1

.if 0
# this does not work when LIBNET_CONFIG does not exist prior to building this port
LIBNET_CPPFLAGS!=	${LIBNET_CONFIG} --cflags --defines
LIBNET_LIBS!=		${LIBNET_CONFIG} --libs
.else
LIBNET_CPPFLAGS=	-I${LOCALBASE}/include/libnet11
LIBNET_LIBS=		-L${LOCALBASE}/lib/libnet11
.endif

.include <bsd.port.mk>
