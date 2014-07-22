# Created by: Kris Kennaway <kris@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dsniff
DISTVERSION=	2.4b1
CATEGORIES=	security
MASTER_SITES=	http://www.monkey.org/~dugsong/${PORTNAME}/beta/ \
		LOCAL/sbz

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Various sniffing utilities for penetration testing

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libnet.so:${PORTSDIR}/net/libnet
BUILD_DEPENDS=	${LOCALBASE}/lib/libnids.a:${PORTSDIR}/net/libnids

GNU_CONFIGURE=	yes
USES=		pkgconfig
WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION:C/(.*)..$/\1/}

OPTIONS_DEFINE=	X11
OPTIONS_DEFAULT=	X11
OPTIONS_SUB=	yes

X11_USE=	xorg=x11,xmu
X11_CONFIGURE_WITH=x

LIBNET_VERSION=	11
LIBNET_CONFIG=	${LOCALBASE}/bin/libnet${LIBNET_VERSION}-config
LIBNET_INC=	"`${LIBNET_CONFIG} --defines` `${LIBNET_CONFIG} --cflags`"
LIBNET_LIB=	"`${LIBNET_CONFIG} --libs`"

pre-configure:
	@${REINPLACE_CMD} -e 's|@NIDSLIB@|& `pkg-config --libs gthread-2.0`|' \
		${WRKSRC}/Makefile.in

post-patch:
	@${REINPLACE_CMD} -Ee \
		's|libnet-config|${LIBNET_CONFIG:T}|; \
		 s|test -f \$${prefix}/include/libnet.h|${TRUE}|; \
		 s|(LNETINC=).*|\1${LIBNET_INC}|; \
		 s|(LNETLIB=).*|\1${LIBNET_LIB}|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e 's,csin,_csin,g' \
		${WRKSRC}/webmitm.c \
		${WRKSRC}/sshmitm.c

.include <bsd.port.mk>
