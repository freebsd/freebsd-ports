# New ports collection makefile for:	dsniff
# Date created:		08 Jan 2000
# Whom:			kris@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	dsniff
PORTVERSION=	2.3
PORTREVISION=	4
CATEGORIES=	security
MASTER_SITES=	http://naughty.monkey.org/~dugsong/dsniff/

MAINTAINER=	sbrabez@gmail.com
COMMENT=	Various sniffing utilities for penetration testing

BUILD_DEPENDS=	${LIBNET_CONFIG}:${PORTSDIR}/net/libnet10 \
		${LOCALBASE}/lib/libnids.a:${PORTSDIR}/net/libnids

GNU_CONFIGURE=	yes
WANT_GNOME=	yes

OPTIONS=	X11 "Enable X11 support" on

MAN8=		arpspoof.8 dsniff.8 macof.8 mailsnarf.8 tcpkill.8 \
		tcpnice.8 urlsnarf.8 filesnarf.8 dnsspoof.8 msgsnarf.8 \
		sshmitm.8 webmitm.8

LIBNET_CONFIG?=	${LOCALBASE}/bin/libnet10-config

.include <bsd.port.pre.mk>

# If net/libnids has been compiled with the GLIB2 option then this port needs
# the corresponding library and additional linker flags.
LIBNIDS_GLIB2?=
.if exists(${LOCALBASE}/lib/libnids.a)
LIBNIDS_GLIB2!=	nm -u ${LOCALBASE}/lib/libnids.a | ${GREP} g_thread_init || ${TRUE}
.endif

.if !empty(LIBNIDS_GLIB2)
USE_GNOME+=	glib20
.endif

.if !defined(WITHOUT_X11)
USE_XORG=	x11 xmu
PLIST_SUB+=	X11=''
MAN8+=		webspy.8
.else
CONFIGURE_ARGS+=--without-x
PLIST_SUB+=	X11='@comment '
.endif

post-patch:
	@${REINPLACE_CMD} -Ee \
		's|libnet-config|${LIBNET_CONFIG:T}|; \
		 s|test -f \$${prefix}/include/libnet.h|${TRUE}|; \
		 s|(LNETINC=).*|\1"`${LIBNET_CONFIG} --cflags`"|; \
		 s|(LNETLIB=).*|\1"`${LIBNET_CONFIG} --libs`"|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

.if !empty(LIBNIDS_GLIB2)
pre-configure:
	@${REINPLACE_CMD} -e 's|@NIDSLIB@|& `pkg-config --libs gthread-2.0`|' \
		${WRKSRC}/Makefile.in
.endif

.include <bsd.port.post.mk>
