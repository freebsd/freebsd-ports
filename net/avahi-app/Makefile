PORTNAME=	avahi
PORTVERSION=	0.8
CATEGORIES?=	net dns
MASTER_SITES=	http://www.avahi.org/download/
PKGNAMESUFFIX?=	-app

MAINTAINER?=	desktop@FreeBSD.org
COMMENT?=	Service discovery on a local network

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LICENSE

AVAHI_SLAVE?=	no

.if ${AVAHI_SLAVE} != header
LIB_DEPENDS?=	libexpat.so:textproc/expat2 \
		libdaemon.so:devel/libdaemon \
		libdbus-glib-1.so:devel/dbus-glib \
		libdbus-1.so:devel/dbus \
		libgdbm.so:databases/gdbm \
		libevent.so:devel/libevent

USERS?=		${PORTNAME}
GROUPS?=	${USERS}

USES+=		alias cpe gettext gmake gnome libtool pathfix pkgconfig
USE_GNOME+=	glib20 intltool introspection:build
USE_GNOME_SUBR=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS?=--with-distro=freebsd \
		--with-dbus-system-socket=unix:path=/var/run/dbus/system_bus_socket \
		--enable-introspection=yes \
		--disable-static \
		--disable-monodoc \
		--disable-doxygen-doc \
		--disable-doxygen-dot \
		--disable-qt3 \
		--disable-qt4 \
		--localstatedir=/var \
		--enable-compat-howl
CPPFLAGS+=	-I${LOCALBASE}/include -DHAVE_KQUEUE
LDFLAGS+=	-L${LOCALBASE}/lib -lintl
INSTALL_TARGET=	install-strip

.if ${AVAHI_SLAVE} == no
CONFLICTS=	howl

DAEMON_CONFIG_FILES=	hosts avahi-daemon.conf
.endif
.endif # !avahi-header

.include <bsd.port.options.mk>

.if ${AVAHI_SLAVE} != header
.if ${AVAHI_SLAVE} == autoipd
CONFIGURE_ARGS+=--enable-autoipd
.else
CONFIGURE_ARGS+=--disable-autoipd
.endif
.if ${AVAHI_SLAVE} == gtk
# We disable man pages, because bssh.1 is not generated (no xmltoman port)
CONFIGURE_ARGS+=--enable-gtk \
		--disable-manpages
.else
CONFIGURE_ARGS+=--disable-gtk
.endif
.if ${AVAHI_SLAVE} == gtk3
CONFIGURE_ARGS+=--enable-gtk3
.else
CONFIGURE_ARGS+=--disable-gtk3
.endif
.if ${AVAHI_SLAVE} == libdns
CONFIGURE_ARGS+=--enable-compat-libdns_sd
.else
CONFIGURE_ARGS+=--disable-compat-libdns_sd
.endif
.if ${AVAHI_SLAVE} == python
CONFIGURE_ARGS+=--enable-python
.else
CONFIGURE_ARGS+=--disable-python
.endif
.if ${AVAHI_SLAVE} == qt5
CONFIGURE_ARGS+=--enable-qt5 \
		--disable-expat \
		--disable-gdbm
.else
CONFIGURE_ARGS+=--disable-qt5
.endif
.if ${AVAHI_SLAVE} == sharp
CONFIGURE_ARGS+=--enable-mono
.else
CONFIGURE_ARGS+=--disable-mono
.endif
CONFIGURE_ARGS+=--disable-stack-protector

post-patch: avahi-post-patch

avahi-post-patch:
	@${REINPLACE_CMD} -e 's|avahi_runtime_dir="/run"|avahi_runtime_dir="/var/run"|' \
		${WRKSRC}/configure
	@${RM} ${WRKSRC}/man/*.bak
	@${REINPLACE_CMD} -e 's|-ldl||g ; s|netdev|network|g' \
		${WRKSRC}/configure \
		${WRKSRC}/avahi-client/Makefile.in \
		${WRKSRC}/avahi-daemon/Makefile.in
	@${REINPLACE_CMD} -e 's|have_inotify=yes|have_inotify=no|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|%%GNOME_SUBR%%|${GNOME_SUBR}|' \
		${WRKSRC}/initscript/freebsd/avahi-dnsconfd.sh.in \
		${WRKSRC}/initscript/freebsd/avahi-daemon.sh.in

post-build: avahi-post-build

avahi-post-build:
.for f in ${AVAHI_PKGCONFIG}
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} \
		${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${f}
.endfor

pre-su-install: avahi-pre-su-install

avahi-pre-su-install:
.if ${AVAHI_SLAVE}=="no"
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/avahi
	@${TOUCH} -f ${STAGEDIR}${PREFIX}/lib/avahi/.keep
.endif

post-install: avahi-post-install

avahi-post-install:
.if defined(MANPAGES) && ${AVAHI_SLAVE} != gtk
.for f in ${MANPAGES}
	${INSTALL_DATA} ${WRKSRC}/man/${f} ${STAGEDIR}${PREFIX}/man/man${f:E}/${f}
.endfor
.endif
.for f in ${AVAHI_PKGCONFIG}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/libdata/pkgconfig
.endfor
.for f in ${DAEMON_CONFIG_FILES}
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/avahi
	${INSTALL_DATA} ${WRKSRC}/avahi-daemon/${f} \
		${STAGEDIR}${PREFIX}/etc/avahi/${f}.sample
.endfor
.if ${AVAHI_SLAVE}==no
	${MKDIR} ${STAGEDIR}${PREFIX}/share/dbus-1/system-services
	${INSTALL_DATA} ${WRKSRC}/avahi-daemon/org.freedesktop.Avahi.service \
		${STAGEDIR}${PREFIX}/share/dbus-1/system-services
.endif
.endif # ! avahi-header

.include <bsd.port.mk>
