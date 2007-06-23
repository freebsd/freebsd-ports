# New ports collection makefile for:	avahi
# Date created:		18 November 2005
# Whom:			Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/net/avahi/Makefile,v 1.19 2006/10/12 16:44:41 marcus Exp $

PORTNAME=	avahi
PORTVERSION=	0.6.20
PORTREVISION?=	0
CATEGORIES?=	net dns
MASTER_SITES=	http://www.avahi.org/download/

MAINTAINER?=	gnome@FreeBSD.org
COMMENT?=	Service discovery on a local network

LIB_DEPENDS?=	expat.6:${PORTSDIR}/textproc/expat2 \
		daemon.0:${PORTSDIR}/devel/libdaemon \
		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
		gdbm.3:${PORTSDIR}/databases/gdbm

USE_GNOME?=	gnomehack ltverhack glib20
USE_GNOME_SUBR=yes
USE_RC_SUBR=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
USE_LDCONFIG=	yes
USE_GETOPT_LONG=yes
CONFIGURE_ARGS?=--with-distro=freebsd \
		--with-dbus-system-address=unix:path=/var/run/dbus/system_bus_socket \
		--disable-qt3 \
		--disable-qt4 \
		--disable-python \
		--disable-mono \
		--disable-monodoc \
		--disable-doxygen-doc \
		--disable-doxygen-dot \
		--localstatedir=/var \
		--enable-compat-howl \
		--disable-autoipd \
		--mandir=${PREFIX}/man
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -DHAVE_KQUEUE" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

.if !defined(AVAHI_SLAVE)
CONFLICTS=	howl-[0-9]*

MAN1=	avahi-browse.1 avahi-publish.1 avahi-resolve.1 avahi-set-host-name.1
MAN5=	avahi-daemon.conf.5 avahi.service.5 avahi.hosts.5
MAN8=	avahi-daemon.8 avahi-dnsconfd.8 avahi-dnsconfd.action.8

MLINKS=	avahi-browse.1 avahi-browse-domains.1 \
	avahi-publish.1 avahi-publish-address.1 \
	avahi-publish.1 avahi-publish-service.1 \
	avahi-resolve.1 avahi-resolve-address.1 \
	avahi-resolve.1 avahi-resolve-host-name.1

OPTIONS=	GTK2 "Build a GTK+ 2 browser utility and other tools" off \
		LIBDNS "Enable mDNSResponder compatibility" off
.endif

.include <bsd.port.pre.mk>

.if !defined(AVAHI_SLAVE)
.if defined(WITH_LIBDNS)
CONFIGURE_ARGS+=--enable-compat-libdns_sd
PLIST_SUB+=	LIBDNS=""
CONFLICTS+=	mDNSResponder-[0-9]*
PKGNAMESUFFIX:=	${PKGNAMESUFFIX}+libdns
.else
CONFIGURE_ARGS+=--disable-compat-libdns_sd
PLIST_SUB+=	LIBDNS="@comment "
.endif

.if defined(WITH_GTK2)
USE_GNOME+=	libglade2
PLIST_SUB+=	GTK=""
MAN1+=		bssh.1
MLINKS+=	bssh.1 bvnc.1
.else
CONFIGURE_ARGS+=--disable-gtk
PLIST_SUB+=	GTK="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-ldl||g ; s|netdev|network|g' \
		${WRKSRC}/configure \
		${WRKSRC}/avahi-client/Makefile.in \
		${WRKSRC}/avahi-daemon/Makefile.in
	@${REINPLACE_CMD} -e 's|%%RC_SUBR%%|${RC_SUBR}| ; \
	    	s|%%GNOME_SUBR%%|${GNOME_SUBR}|' \
		${WRKSRC}/initscript/freebsd/avahi-dnsconfd.sh.in \
		${WRKSRC}/initscript/freebsd/avahi-daemon.sh.in

post-install:
.if !defined(PACKAGE_BUILDING)
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif

.endif

.include <bsd.port.post.mk>
