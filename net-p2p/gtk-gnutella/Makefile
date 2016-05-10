# Created by: rbt@zort.on.ca
# $FreeBSD$

#
# A quick note on configurable make symbols:
#
# INTERACTIVE_CONFIGURE: Launches Configure in its default mode, which is
#	*very* interactive. Disabled here by default to conform to FreeBSD
#	guidelines, this mode is useful if you have problems with the
#	default Configure.
#
# GUI: Disable this to build a headless version of Gtk-Gnutella. Therefore,
#	monitoring of operations for Gtk-Gnutella will have to be
#	done without relying on any GUI, and the configuration is done via
#	files only.
#
# TLS: Enable support for scrambling GNet connections. Currently supported
#	only by Gtk-Gnutella.
#
# NLS: Enable National Language Support for translation of User Interface.
#
# IPV6: Enable to support IPv6 connections. The real configuration takes
#	place at run-time so keeping it enabled will not force IPv6 usage.
#
# DBUS: Enable D-Bus IPC support. Gtk-Gnutella will send out messages onto
#	the D-Bus message bus. That way external applications can easily
#	act on certain events that happen, such as a completed download.
#
# DEBUG: Compile with debugging symbols. Useful if you intend to make a
#	bug report.
#
# PORTABILITY: Configure code to use the PATH variable at run-time at a
#	cost in performance. Useful if you intend to move the executable
#	to multiple machines.
#

PORTNAME=	gtk-gnutella
PORTVERSION=	1.1.9
PORTREVISION=	1
CATEGORIES=	net-p2p ipv6
MASTER_SITES=	SF

MAINTAINER=	woodsb02@FreeBSD.org
COMMENT=	GTK based Gnutella client

LICENSE=	GPLv2+

USES=		iconv localbase pkgconfig tar:bzip2
USE_GNOME=	glib20 libxml2
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	Configure
CONFIGURE_ARGS=	-O -Dyacc='byacc' \
		-Dprefix='${PREFIX}' \
		-Dprivlib='${DATADIR}' \
		-Dmansrc='${MANPREFIX}/man/man1' \
		-Dlocale='${PREFIX}/share/locale' \
		-Dcc='${CC}' -Doptimize='${CFLAGS}' \
		-Dccflags='${CPPFLAGS}' -Dldflags='${LDFLAGS}' \
		-Dusemymalloc='n'
MAKE_ARGS=	INSTALL_PREFIX="${STAGEDIR}"
INSTALL_TARGET=	install install.man

PLIST_SUB=	ARCH="${ARCH}" OPSYS="${OPSYS:tl}"

ONLY_FOR_ARCHS=	i386 amd64

MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=		DBUS DEBUG GUI IPV6 NLS PORTABILITY TLS
OPTIONS_DEFAULT=	GUI TLS
OPTIONS_SUB=		yes

DBUS_LIB_DEPENDS=	libdbus-1.so:devel/dbus
DBUS_CONFIGURE_OFF=	-Ud_dbus
DEBUG_CONFIGURE_ON=	-Ud_official
GUI_USE=		gnome=gtk20
GUI_VARS=		INSTALLS_ICONS=yes
GUI_CONFIGURE_OFF=	-Dd_headless
IPV6_CONFIGURE_OFF=	-Ud_ipv6
NLS_USES=		gettext
NLS_CONFIGURE_OFF=	-Ud_nls
PORTABILITY_DESC=	Use the PATH variable at run-time
PORTABILITY_CONFIGURE_ON=	-Dd_portable
TLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
TLS_CONFIGURE_OFF=	-Ud_gnutls

.if !defined(INTERACTIVE_CONFIGURE)
CONFIGURE_ARGS+=	-ders
.endif

post-extract:
	@${CHMOD} -R a+rX ${WRKSRC}

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.SH" | ${XARGS} ${REINPLACE_CMD} -e \
		's|@exit 0|@echo done|'

post-patch-DEBUG-off:
	@${REINPLACE_CMD} 's/(INSTALL) -c -m 555/(INSTALL) -c -s -m 555/g' \
		${WRKSRC}/src/Makefile.SH

post-install-GUI-on:
.for i in 16 32 128 256 512
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${i}x${i}/apps
	(cd ${WRKSRC}/extra_files && ${INSTALL_DATA} gtk-gnutella.${i}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${i}x${i}/apps/gtk-gnutella.png)
.endfor
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	(cd ${WRKSRC}/extra_files && ${INSTALL_DATA} gtk-gnutella.svg \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps/gtk-gnutella.svg)

.include <bsd.port.mk>
