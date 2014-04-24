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
# WITH_DEBUG: Compile with debugging symbols. Useful if you intend to make
#	a bug report.
#
# WITH_PORTABILITY: Configure code to use the PATH variable at run-time
#	at a cost in performance. Useful if you intend to move the executable
#	to multiple machines.
#

PORTNAME=	gtk-gnutella
PORTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	net-p2p ipv6
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK based Gnutella client

LICENSE=	GPLv2 # (or later)

OPTIONS_DEFINE=	GUI TLS NLS IPV6 DBUS DEBUG PORTABILITY
OPTIONS_DEFAULT=GUI TLS
OPTIONS_SUB=	yes
PORTABILITY_DESC=	Use the PATH variable at run-time

ONLY_FOR_ARCHS=	i386 amd64

USE_BZIP2=	yes
USES=		iconv perl5 pkgconfig
USE_GNOME=	glib20 libxml2
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	Configure
CONFIGURE_ARGS=	-O -Dyacc='byacc' \
		-Dprefix=${STAGEDIR}${PREFIX} \
		-Dprivlib=${STAGEDIR}${DATADIR} \
		-Dmansrc=${STAGEDIR}${MANPREFIX}/man/man1 \
		-Dlocale=${PREFIX}/share/locale \
		-Dcc='${CC}' -Doptimize='${CFLAGS}' \
		-Dccflags='${CPPFLAGS}' -Dldflags='${LDFLAGS}'
INSTALL_TARGET=	install install.man
MAKE_JOBS_UNSAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_SUB=	ARCH="${ARCH}"

.include <bsd.port.options.mk>

.if !defined(INTERACTIVE_CONFIGURE)
CONFIGURE_ARGS+=	-ders
.endif

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=	-Ud_official
.endif

.if ${PORT_OPTIONS:MGUI}
USE_GNOME+=		gtk20
INSTALLS_ICONS=	yes
.else
CONFIGURE_ARGS+=	-Dd_headless
.endif

.if ${PORT_OPTIONS:MPORTABILITY}
CONFIGURE_ARGS+=	-Dd_portable
.endif

.if ${PORT_OPTIONS:MTLS}
LIB_DEPENDS+=		libgnutls.so:${PORTSDIR}/security/gnutls
.else
CONFIGURE_ARGS+=	-Ud_gnutls
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
.else
CONFIGURE_ARGS+=	-Ud_nls
.endif

.if empty(PORT_OPTIONS:MIPV6)
CONFIGURE_ARGS+=	-Ud_ipv6
.endif

.if ${PORT_OPTIONS:MDBUS}
LIB_DEPENDS+=		libdbus.so:${PORTSDIR}/devel/dbus
.else
CONFIGURE_ARGS+=	-Ud_dbus
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.SH" | ${XARGS} ${REINPLACE_CMD} -e \
		's|@exit 0|@echo done|'

post-install:
.if ${PORT_OPTIONS:MGUI}
.for i in 16 32 128 256 512
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${i}x${i}/apps
	(cd ${WRKSRC}/extra_files && ${INSTALL_DATA} gtk-gnutella.${i}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${i}x${i}/apps/gtk-gnutella.png)
.endfor
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	(cd ${WRKSRC}/extra_files && ${INSTALL_DATA} gtk-gnutella.svg \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps/gtk-gnutella.svg)
.endif
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/gtk-gnutella

.include <bsd.port.mk>
