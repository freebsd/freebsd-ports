# New ports collection makefile for:	avahi
# Date created:		18 November 2005
# Whom:			Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/net/avahi/Makefile,v 1.15 2006/04/28 01:52:15 marcus Exp $

PORTNAME=	avahi
PORTVERSION=	0.6.10
PORTREVISION?=	1
CATEGORIES?=	net dns
MASTER_SITES=	http://www.avahi.org/download/

MAINTAINER?=	gnome@FreeBSD.org
COMMENT?=	Service discovery on a local network

LIB_DEPENDS?=	expat.6:${PORTSDIR}/textproc/expat2 \
		daemon.2:${PORTSDIR}/devel/libdaemon \
		dbus-1.2:${PORTSDIR}/devel/dbus \
		gdbm.3:${PORTSDIR}/databases/gdbm

USE_GNOME?=	gnomehack ltverhack glib20
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS?=--with-distro=freebsd \
		--with-dbus-system-address=unix:path=/var/run/dbus/dbus.pipe \
		--disable-qt3 \
		--disable-qt4 \
		--disable-python \
		--disable-mono \
		--disable-monodoc \
		--disable-doxygen-doc \
		--disable-doxygen-dot \
		--localstatedir=/var \
		--enable-compat-howl
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

.if !defined(AVAHI_SLAVE)
CONFLICTS=	howl-[0-9]*

MAN1=	avahi-browse-domains.1 avahi-browse.1 avahi-publish-address.1 \
	avahi-publish-service.1 avahi-publish.1 avahi-resolve-address.1 \
	avahi-resolve-host-name.1 avahi-resolve.1
MAN5=	avahi-daemon.conf.5 avahi.service.5 avahi.hosts.5
MAN8=	avahi-daemon.8 avahi-dnsconfd.8 avahi-dnsconfd.action.8

OPTIONS=	GTK2 "Build a GTK+ 2 browser utility" off
.endif

.include <bsd.port.pre.mk>

.if !defined(AVAHI_SLAVE)
.if ${OSVERSION} < 500000
IGNORE=	does not work on FreeBSD 4.X
.endif

.if defined(WITH_GTK2)
USE_GNOME+=	libglade2
PLIST_SUB+=	GTK=""
.else
CONFIGURE_ARGS+=--disable-gtk
PLIST_SUB+=	GTK="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-ldl||g' ${WRKSRC}/configure \
		${WRKSRC}/avahi-client/Makefile.in \
		${WRKSRC}/avahi-daemon/Makefile.in

post-install:
.if !defined(PACKAGE_BUILDING)
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif

.endif

.include <bsd.port.post.mk>
