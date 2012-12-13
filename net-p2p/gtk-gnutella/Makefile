# Created by: rbt@zort.on.ca
# $FreeBSD$

#
# A quick note on configurable make symbols:
#
# INTERACTIVE_CONFIGURE: Launches Configure in its default mode,
#	which is *very* interactive. Disabled here by default to conform to
#	FreeBSD guidelines, this mode is useful if you have problems with the
#	default Configure.
#
# WITH_X11: Disable this to build a headless version of Gtk-Gnutella. The
#       resulting executable won't use or depend on any Gtk version and
#       Gtk-Gnutella can only be controlled through the remote shell.
#       Use with caution!
#
# WITH_GTK2: Enable to configure and build with GTK 2, disable to configure and
#       build with GTK 1.2. Will be ignored if WITH_X11 is disabled!
#
# WITH_TLS: Enable support for scrambling GNet connections. Currently supported
#       only by Gtk-Gnutella.
#
# WITH_NLS: Enable National Language Support for translation of User Interface.
#
# WITH_IPV6: Enable to support IPv6 connections. The real configuration takes
#       place at run-time so keeping it enabled will not force IPv6 usage.
#
# WITH_DBUS: Enable D-Bus IPC support. No further information available.
#
# WITH_SQLITE: Enable to support storage of run-time information to a SQLite
#       database file. Should ideally save some memory.
#
# WITH_DEBUG: Compile with debugging symbols. Useful if you intend to make
#	a bug report.
#
# WITH_PORTABILITY: Configure code to use the PATH variable at run-time
#	at a cost in performance. Useful if you intend to move the executable
#	to multiple machines.
#

PORTNAME=	gtk-gnutella
PORTVERSION=	0.96.9
PORTREVISION=	2
CATEGORIES=	net-p2p ipv6
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK based Gnutella client

USE_PERL5=	yes
USE_BZIP2=	yes
USE_BISON=	build
MAKE_JOBS_UNSAFE=	yes
USE_GNOME=	libxml2 glib20
INSTALL_TARGET=	install install.man
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	Configure
CONFIGURE_ARGS=	-O -Dyacc='bison -y' -Dprefix=${PREFIX} \
		-Dprivlib=${PREFIX}/share/gtk-gnutella \
		-Dsysman=${PREFIX}/man/man1 -Dlocale=${PREFIX}/share/locale \
		-Dcc='${CC}' -Dccflags='${CFLAGS} -I${LOCALBASE}/include' \
		-Doptimize='undef'
ONLY_FOR_ARCHS=	i386 amd64

MAN1=		gtk-gnutella.1

OPTIONS_DEFINE=	X11 GTK2 GNUTLS NLS IPV6 DBUS SQLITE DEBUG PORTABILITY
OPTIONS_DEFAULT=	X11 GTK2 GNUTLS
PORTABILITY_DESC=	Use the PATH variable at run-time

.include <bsd.port.options.mk>

.if !defined(INTERACTIVE_CONFIGURE)
CONFIGURE_ARGS+=	-ders
.endif

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=	-D optimize=-g  -D official=false
.else
CONFIGURE_ARGS+=	-D official=true
.endif

.if ${PORT_OPTIONS:MX11}
USE_XORG=		x11
.if ${PORT_OPTIONS:MGTK2}
CONFIGURE_ARGS+=	-D gtkversion=2
USE_GNOME+=		gtk20
.else
CONFIGURE_ARGS+=	-D gtkversion=1
USE_GNOME+=		gtk12
.endif
.else
CONFIGURE_ARGS+=	-D d_headless
.endif

.if ${PORT_OPTIONS:MPORTABILITY}
CONFIGURE_ARGS+=	-D d_portable
.endif

.if ${PORT_OPTIONS:MGNUTLS}
LIB_DEPENDS+=		gnutls:${PORTSDIR}/security/gnutls
.else
CONFIGURE_ARGS+=	-U d_gnutls
.endif

.if ${PORT_OPTIONS:MNLS}
CONFIGURE_ARGS+=	-D d_nls
USE_GETTEXT=		yes
PLIST_FILES=		share/locale/de/LC_MESSAGES/gtk-gnutella.mo \
			share/locale/el/LC_MESSAGES/gtk-gnutella.mo \
			share/locale/es/LC_MESSAGES/gtk-gnutella.mo \
			share/locale/fr/LC_MESSAGES/gtk-gnutella.mo \
			share/locale/hu/LC_MESSAGES/gtk-gnutella.mo \
			share/locale/it/LC_MESSAGES/gtk-gnutella.mo \
			share/locale/ja/LC_MESSAGES/gtk-gnutella.mo \
			share/locale/nb/LC_MESSAGES/gtk-gnutella.mo \
			share/locale/nl/LC_MESSAGES/gtk-gnutella.mo \
			share/locale/tr/LC_MESSAGES/gtk-gnutella.mo \
			share/locale/uk/LC_MESSAGES/gtk-gnutella.mo \
			share/locale/zh_CN/LC_MESSAGES/gtk-gnutella.mo
.else
CONFIGURE_ARGS+=	-U d_nls
.endif

.if ${PORT_OPTIONS:MIPB6}
CONFIGURE_ARGS+=	-D ipv6=false
.endif

.if ${PORT_OPTIONS:MDBUS}
LIB_DEPENDS+=		dbus:${PORTSDIR}/devel/dbus
.else
CONFIGURE_ARGS+=	-D dbus=false
.endif

.if ${PORT_OPTIONS:MSQLITE}
USE_SQLITE=		yes
.else
CONFIGURE_ARGS+=	-U d_sqlite
.endif

.if ${ARCH} == i386
PLIST_SUB+=	I386=""
.else
PLIST_SUB+=	I386="@comment "
.endif

.if ${ARCH} == amd64
PLIST_SUB+=	AMD64=""
.else
PLIST_SUB+=	AMD64="@comment "
.endif

.include <bsd.port.mk>
