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
# WITH_GUI: Disable this to build a headless version of Gtk-Gnutella.
#       Therefore, monitoring of operations for Gtk-Gnutella will have to be
#       done without relying on any GUI, and the configuration is done via
#       files only.
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
PORTVERSION=	0.98.4
CATEGORIES=	net-p2p ipv6
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK based Gnutella client

LICENSE=	GPLv2 # (or later)

OPTIONS_DEFINE=	GUI TLS NLS IPV6 DBUS SQLITE DEBUG PORTABILITY
OPTIONS_DEFAULT=GUI TLS
PORTABILITY_DESC=	Use the PATH variable at run-time

ONLY_FOR_ARCHS=	i386 amd64

USE_BZIP2=	yes
USE_GNOME=	glib20 libxml2
USE_PERL5=	yes
USE_BISON=	build
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	Configure
CONFIGURE_ARGS=	-O -Dyacc='bison -y' -Dprefix=${PREFIX} \
		-Dprivlib=${DATADIR} -Dsysman=${MANPREFIX}/man/man1 \
		-Dlocale=${PREFIX}/share/locale -Dcc='${CC}' \
		-Dccflags='${CFLAGS} -I${LOCALBASE}/include' \
		-Doptimize='undef'
INSTALL_TARGET=	install install.man
MAKE_JOBS_UNSAFE=	yes

PLIST_SUB=	ARCH="${ARCH}"

MAN1=		gtk-gnutella.1

.include <bsd.port.options.mk>

.if !defined(INTERACTIVE_CONFIGURE)
CONFIGURE_ARGS+=	-ders
.endif

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=	-D optimize=-g  -D official=false
.else
CONFIGURE_ARGS+=	-D official=true
.endif

.if ${PORT_OPTIONS:MGUI}
USE_GNOME+=		gtk20
CONFIGURE_ARGS+=	-D gtkversion=2
.else
CONFIGURE_ARGS+=	-D d_headless
.endif

.if ${PORT_OPTIONS:MPORTABILITY}
CONFIGURE_ARGS+=	-D d_portable
.endif

.if ${PORT_OPTIONS:MTLS}
LIB_DEPENDS+=		gnutls:${PORTSDIR}/security/gnutls
.else
CONFIGURE_ARGS+=	-U d_gnutls
.endif

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=		yes
CONFIGURE_ARGS+=	-D d_nls
PLIST_SUB+=		NLS=""
.else
CONFIGURE_ARGS+=	-U d_nls
PLIST_SUB+=		NLS="@comment "
.endif

.if empty(PORT_OPTIONS:MIPV6)
CONFIGURE_ARGS+=	-D ipv6=false
.endif

.if ${PORT_OPTIONS:MDBUS}
LIB_DEPENDS+=		dbus:${PORTSDIR}/devel/dbus
.else
CONFIGURE_ARGS+=	-U d_dbus
.endif

.if ${PORT_OPTIONS:MSQLITE}
USE_SQLITE=		yes
.else
CONFIGURE_ARGS+=	-U d_sqlite
.endif

.include <bsd.port.mk>
