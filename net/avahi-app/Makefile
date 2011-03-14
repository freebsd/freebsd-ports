# New ports collection makefile for:	avahi
# Date created:		18 November 2005
# Whom:			Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/net/avahi-app/Makefile,v 1.17 2011/03/13 17:23:19 kwm Exp $
#

PORTNAME=	avahi
PORTVERSION=	0.6.29
PORTREVISION?=	0
CATEGORIES?=	net dns
MASTER_SITES=	http://www.avahi.org/download/
PKGNAMESUFFIX?=	-app

MAINTAINER?=	gnome@FreeBSD.org
COMMENT?=	Service discovery on a local network

BUILD_DEPENDS?=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection
LIB_DEPENDS?=	expat.6:${PORTSDIR}/textproc/expat2 \
		daemon.0:${PORTSDIR}/devel/libdaemon \
		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
		gdbm.3:${PORTSDIR}/databases/gdbm
RUN_DEPENDS?=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection

USE_GNOME?=	gnomehack ltverhack glib20 intltool
USE_GETTEXT=	yes
USE_GNOME_SUBR=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
AVAHI_SLAVE?=	no
CONFIGURE_ARGS?=--with-distro=freebsd \
		--with-dbus-system-socket=unix:path=/var/run/dbus/system_bus_socket \
		--disable-monodoc \
		--disable-doxygen-doc \
		--disable-doxygen-dot \
		--localstatedir=/var \
		--enable-compat-howl
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -DHAVE_KQUEUE" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

.if ${AVAHI_SLAVE}=="no"
CONFLICTS=	howl-[0-9]*

MAN1=	avahi-browse.1 avahi-publish.1 avahi-resolve.1 avahi-set-host-name.1
MAN5=	avahi-daemon.conf.5 avahi.service.5 avahi.hosts.5
MAN8=	avahi-daemon.8 avahi-dnsconfd.8 avahi-dnsconfd.action.8

MLINKS=	avahi-browse.1 avahi-browse-domains.1 \
	avahi-publish.1 avahi-publish-address.1 \
	avahi-publish.1 avahi-publish-service.1 \
	avahi-resolve.1 avahi-resolve-address.1 \
	avahi-resolve.1 avahi-resolve-host-name.1

DAEMON_CONFIG_FILES=	hosts avahi-daemon.conf
.endif

USE_RC_SUBR=yes

.include <bsd.port.pre.mk>

.if ${AVAHI_SLAVE}=="autoipd"
CONFIGURE_ARGS+=--enable-autoipd
.else
CONFIGURE_ARGS+=--disable-autoipd
.endif
.if ${AVAHI_SLAVE}=="gtk"
CONFIGURE_ARGS+=--enable-gtk
.else
CONFIGURE_ARGS+=--disable-gtk
.endif
.if ${AVAHI_SLAVE}=="gtk3"
CONFIGURE_ARGS+=--enable-gtk3
.else
CONFIGURE_ARGS+=--disable-gtk3
.endif
.if ${AVAHI_SLAVE}=="libdns"
CONFIGURE_ARGS+=--enable-compat-libdns_sd
.else
CONFIGURE_ARGS+=--disable-compat-libdns_sd
.endif
.if ${AVAHI_SLAVE}=="python"
CONFIGURE_ARGS+=--enable-python
.else
CONFIGURE_ARGS+=--disable-python
.endif
.if ${AVAHI_SLAVE}=="qt3"
CONFIGURE_ARGS+=--enable-qt3
.else
CONFIGURE_ARGS+=--disable-qt3
.endif
.if ${AVAHI_SLAVE}=="qt4"
CONFIGURE_ARGS+=--enable-qt4 \
		--disable-expat \
		--disable-gdbm
.else
CONFIGURE_ARGS+=--disable-qt4
.endif
.if ${AVAHI_SLAVE}=="sharp"
CONFIGURE_ARGS+=--enable-mono
.else
CONFIGURE_ARGS+=--disable-mono
.endif

post-patch: avahi-post-patch

avahi-post-patch:
	@${REINPLACE_CMD} -e 's|/etc|${PREFIX}/etc|' \
		${WRKSRC}/man/*.*
	@${RM} -f ${WRKSRC}/man/*.bak
	@${REINPLACE_CMD} -e 's|-ldl||g ; s|netdev|network|g' \
		${WRKSRC}/configure \
		${WRKSRC}/avahi-client/Makefile.in \
		${WRKSRC}/avahi-daemon/Makefile.in
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} \
	    	${REINPLACE_CMD} -e 's|(LIBINTL)|(INTLLIBS)|g ; \
		s|(LIBICONV)|(LTLIBICONV)|g'
	@${REINPLACE_CMD} -e 's|%%RC_SUBR%%|/etc/rc.subr| ; \
	    	s|%%GNOME_SUBR%%|${GNOME_SUBR}|' \
		${WRKSRC}/initscript/freebsd/avahi-dnsconfd.sh.in \
		${WRKSRC}/initscript/freebsd/avahi-daemon.sh.in
	@${REINPLACE_CMD} -e 's|dbus_connection_disconnect|dbus_connection_close|g' \
	    	${WRKSRC}/avahi-client/client.c \
		${WRKSRC}/avahi-daemon/dbus-protocol.c
	@${REINPLACE_CMD} -e 's|^_||g' \
		${WRKSRC}/avahi-ui/*.desktop.in.in

post-build: avahi-post-build

avahi-post-build:
.for f in ${AVAHI_PKGCONFIG}
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} \
		${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${f}
.endfor

pre-su-install: avahi-pre-su-install

avahi-pre-su-install:
.if ${AVAHI_SLAVE}=="no"
	@${MKDIR} ${PREFIX}/lib/avahi
	@${TOUCH} -f ${PREFIX}/lib/avahi/.keep
.endif

post-install: avahi-post-install

avahi-post-install:
.if ${AVAHI_SLAVE}!="no"
.for f in ${MAN1} ${MAN2} ${MAN3} ${MAN4} ${MAN5} ${MAN6} ${MAN7} ${MAN8} ${MAN9}
	${INSTALL_DATA} ${WRKSRC}/man/${f} ${PREFIX}/man/man${f:E}/${f}
.endfor
.endif
.for f in ${AVAHI_PKGCONFIG}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/libdata/pkgconfig
.endfor
	${MKDIR} ${PREFIX}/etc/avahi
.for f in ${DAEMON_CONFIG_FILES}
	${INSTALL_DATA} ${WRKSRC}/avahi-daemon/${f} \
	    	${PREFIX}/etc/avahi/${f}.dist
	if [ ! -f ${PREFIX}/etc/avahi/${f} ]; then \
	    	${INSTALL_DATA} ${WRKSRC}/avahi-daemon/${f} \
			${PREFIX}/etc/avahi; \
	fi
.endfor
.if ${AVAHI_SLAVE}=="no"
	${INSTALL_DATA} ${FILESDIR}/org.freedesktop.Avahi.service \
		${LOCALBASE}/share/dbus-1/system-services
.endif
.if !defined(PACKAGE_BUILDING) && (${AVAHI_SLAVE}=="no" || ${AVAHI_SLAVE}=="autoipd")
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif

.include <bsd.port.post.mk>
