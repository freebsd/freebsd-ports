# Created by: Kris Kennaway <kris@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dsniff
PORTVERSION=	2.3
PORTREVISION=	4
CATEGORIES=	security
MASTER_SITES=	http://www.monkey.org/~dugsong/${PORTNAME}/ \
		LOCAL/sbz

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Various sniffing utilities for penetration testing

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/lib/libnet10/libnet.a:${PORTSDIR}/net/libnet10 \
		${LOCALBASE}/lib/libnids.a:${PORTSDIR}/net/libnids

GNU_CONFIGURE=	yes
USES=		pkgconfig
WANT_GNOME=	yes

OPTIONS_DEFINE=	X11
OPTIONS_DEFAULT=	X11
OPTIONS_SUB=	yes

X11_USE=	xorg=x11,xmu
X11_CONFIGURE_WITH=x

LIBNET_VERSION=	10
LIBNET_CONFIG?=	${LOCALBASE}/bin/libnet${LIBNET_VERSION}-config
LIBNET_INC=	"`${LIBNET_CONFIG} --defines` `${LIBNET_CONFIG} --cflags`"
# ugly hack because net/libnet10 doesn't install shared library, only static archive
# so we can't use libnet-config10 --libs to retrieve linker flags
LIBNET_LIB=	"-L${LOCALBASE}/include/libnet${LIBNET_VERSION} \
		${LOCALBASE}/lib/libnet${LIBNET_VERSION}/libnet.a"

.include <bsd.port.pre.mk>
# If net/libnids has been compiled with the GLIB2 option then this port needs
# the corresponding library and additional linker flags.
LIBNIDS_GLIB2?=
.if exists(${LOCALBASE}/lib/libnids.a)
LIBNIDS_GLIB2!=	nm -u ${LOCALBASE}/lib/libnids.a | ${GREP} g_thread_init || ${ECHO_CMD}
.endif

.if !empty(LIBNIDS_GLIB2)
USE_GNOME+=	glib20
.endif

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

.if !empty(LIBNIDS_GLIB2)
pre-configure:
	@${REINPLACE_CMD} -e 's|@NIDSLIB@|& `pkg-config --libs gthread-2.0`|' \
		${WRKSRC}/Makefile.in
.endif

.include <bsd.port.post.mk>
