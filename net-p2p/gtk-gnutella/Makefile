# New ports collection makefile for:	gtk-gnutella
# Date created:				19 May, 2000
# Whom:					rbt@zort.on.ca
#
# $FreeBSD$
#

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
PORTVERSION=	0.96.6
PORTREVISION=	5
CATEGORIES=	net-p2p ipv6
MASTER_SITES=	SF

MAINTAINER=	jonas@schiebtsich.net
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

MAN1=		gtk-gnutella.1

OPTIONS=	X11 "Build with GUI" on \
		GTK2 "Build with GTK2 frontend" on \
		TLS "Enable GNU TLS encryption support" on \
		NLS "Enable national language support" on \
		IPV6 "Enable IPv6 support" on \
		DBUS "Enable D-BUS IPC support" off \
		SQLITE "Enable SQLite support" off \
		DEBUG "Build with debugging symbols" off \
		PORTABILITY "Use the PATH variable at run-time" off

.include <bsd.port.pre.mk>

.if !defined(INTERACTIVE_CONFIGURE)
CONFIGURE_ARGS+=	-ders
.endif

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	-D optimize=-g  -D official=false
.else
CONFIGURE_ARGS+=	-D official=true
.endif

.if !defined(WITHOUT_X11)
USE_XORG=		x11
.if defined(WITH_GTK2)
CONFIGURE_ARGS+=	-D gtkversion=2
USE_GNOME+=		gtk20
.else
CONFIGURE_ARGS+=	-D gtkversion=1
USE_GNOME+=		gtk12
.endif
.else
CONFIGURE_ARGS+=	-D d_headless
.endif

.if defined(WITH_PORTABILITY)
CONFIGURE_ARGS+=	-D d_portable
.endif

.if defined(WITH_TLS)
LIB_DEPENDS+=		gnutls:${PORTSDIR}/security/gnutls
.else
CONFIGURE_ARGS+=	-U d_gnutls
.endif

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	-U d_nls
.else
CONFIGURE_ARGS+=	-D d_nls
LIB_DEPENDS+=		intl:${PORTSDIR}/devel/gettext
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
.endif

.if defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=	-D ipv6=false
.endif

.if defined(WITH_DBUS)
LIB_DEPENDS+=		dbus:${PORTSDIR}/devel/dbus
.else
CONFIGURE_ARGS+=	-D dbus=false
.endif

.if defined(WITH_SQLITE)
USE_SQLITE=		yes
.else
CONFIGURE_ARGS+=	-U d_sqlite
.endif

.include <bsd.port.post.mk>
