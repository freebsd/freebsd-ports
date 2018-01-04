# Created by: Jim Mock <jim@FreeBSD.org>
# $FreeBSD$

PORTNAME?=	libpurple
PORTVERSION=	2.12.0
PORTREVISION=	3
CATEGORIES?=	net-im
MASTER_SITES=	SF/pidgin/Pidgin/${PORTVERSION}
DISTNAME=	pidgin-${PORTVERSION}

MAINTAINER?=	marcus@FreeBSD.org
COMMENT?=	Backend library for the Pidgin multi-protocol messaging client

USES+=		cpe gettext gmake libtool pathfix pkgconfig tar:bzip2
USE_GNOME?=	gnomeprefix intltool glib20 libxml2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS?=--disable-gtkui \
		--disable-consoleui \
		--with-dynamic-prpls=${PRPL_MODULES:S/,$//} \
		--enable-static \
		--disable-nm
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

.if !defined(PIDGIN_SLAVE)
# Pidgin slave ports that require the following functionality, must explicitly
# set these macros themselves.
USES+=		iconv python:2.7 shebangfix
USE_LDCONFIG=	yes
SHEBANG_FILES=	libpurple/purple-remote \
		libpurple/purple-url-handler

.if defined(PACKAGE_BUILDING)
WITH_GNOME=	yes
.endif

.endif

PRPL_MODULES=

CPE_VENDOR=	pidgin

OPTIONS_DEFINE=	DBUS SASL GSTREAMER VV IDN PERL TCLTK
OPTIONS_GROUP=		PROTOCOLS
OPTIONS_RADIO=	TLS
OPTIONS_RADIO_TLS=	NSS GNUTLS
OPTIONS_GROUP_PROTOCOLS=BONJOUR GG SAMETIME SILC IRC JABBER \
			NOVELL OSCAR QQ SIMPLE ZEPHYR
OPTIONS_DEFAULT=	BONJOUR DBUS NSS GSTREAMER VV IDN GG IRC JABBER \
			NOVELL OSCAR QQ SIMPLE ZEPHYR
BONJOUR_DESC=	mDNS support and Bonjour protocol
GNUTLS_DESC=	Use GNUTLS for encryption support
NSS_DESC=	Use Mozilla NSS for encryption support
SASL_DESC=	Cyrus SASL support (for jabberd)
GSTREAMER_DESC=	Use GStreamer for playing sounds
VV_DESC=	Video and voice support
SAMETIME_DESC=	The Lotus Sametime chat protocol
SILC_DESC=	The Secure Internet Live Conferencing protocol
GG_DESC=	The Gadu-Gadu chat protocol
IRC_DESC=	The Internet Relay Chat protocol
JABBER_DESC=	The Jabber/XMPP/Google Talk protocol
NOVELL_DESC=	The Novell GroupWise chat protocol
OSCAR_DESC=	The ICQ/Oscar protocol
QQ_DESC=	The Tercent QQ chat protocol
SIMPLE_DESC=	The SIMPLE chat protocol
ZEPHYR_DESC=	The Zephyr chat protocol

.if defined(WITH_GTKUI)
OPTIONS_DEFINE+=	GTKSPELL CAP
OPTIONS_DEFAULT+=	GTKSPELL CAP
GTKSPELL_DESC=	Spell checking support
CAP_DESC=	Contact Availability Prediction plugin
PLIST_SUB+=	GTKUI=""
.else
PLIST_SUB+=	GTKUI="@comment not installed: "
.endif

.if defined(WITH_CONSOLEUI)
OPTIONS_DEFINE+=NCURSES
NCURSES_DESC=	Build with ncurses from ports
PLIST_SUB+=	CONSOLEUI=""
.else
PLIST_SUB+=	CONSOLEUI="@comment not installed: "
.endif

CONFIGURE_ARGS+=--disable-doxygen

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTCLTK}
USES+=			tk
CFLAGS+=		-I${TK_INCLUDEDIR} -I${TCL_INCLUDEDIR}
CONFIGURE_ARGS+=	--with-tclconfig=${TCL_LIBDIR} \
			--with-tkconfig=${TK_LIBDIR}
PLIST_SUB+=		TCL:=""
.else
CONFIGURE_ARGS+=	--disable-tcl
PLIST_SUB+=		TCL:="@comment not installed: "
.endif

.if ${PORT_OPTIONS:MNCURSES}
USES+=		ncurses:port
CONFIGURE_ARGS+=--with-ncurses-headers=${LOCALBASE}/include/ncurses/
.else
USES+=		ncurses
.endif

.if ${PORT_OPTIONS:MPERL}
USES+=			perl5
CONFIGURE_ARGS+=	--with-perl-lib=site
PLIST_SUB+=		PERL:=""
.if !defined(PIDGIN_SLAVE) || defined(WITH_GTKUI)
PLIST_SUB+=		PERLMAN:=""
.else
PLIST_SUB+=		PERLMAN:="@comment not installed: "
.endif
.else
CONFIGURE_ARGS+=	--disable-perl
PLIST_SUB+=		PERL:="@comment not installed: " \
			PERLMAN:="@comment not installed: "
.endif

.if defined(WITH_GTKUI) && !defined(PIDGIN_SLAVE)
USE_GNOME+=	gconf2
GCONF_SCHEMAS=	purple.schemas
.endif

#.if defined(WITH_GTKUI)
#USE_GNOME+=		evolutiondataserver
#PLIST_SUB+=		EVO=""
#CONFIGURE_ARGS+=	--enable-gevolution
#.else
CONFIGURE_ARGS+=	--disable-gevolution
PLIST_SUB+=		EVO="@comment not installed: "
#.endif

.if ${PORT_OPTIONS:MGSTREAMER}
USE_GSTREAMER1+=core good
.else
CONFIGURE_ARGS+=--disable-gstreamer
.endif

.if ${PORT_OPTIONS:MVV} && ${PORT_OPTIONS:MGSTREAMER}
LIB_DEPENDS+=	libfarstream-0.2.so:net-im/farstream
USE_GSTREAMER1+=v4l2
PLIST_SUB+=	VV=""
.else
CONFIGURE_ARGS+=--disable-vv
PLIST_SUB+=	VV="@comment "
.endif

.if ${PORT_OPTIONS:MIDN}
LIB_DEPENDS+=	libidn.so:dns/libidn
.else
CONFIGURE_ARGS+=--disable-idn
.endif

.if ${PORT_OPTIONS:MCAP}
LIB_DEPENDS+=	libsqlite3.so:databases/sqlite3
CONFIGURE_ARGS+=--enable-cap
PLIST_SUB+=	CAP=""
.else
CONFIGURE_ARGS+=--disable-cap
PLIST_SUB+=	CAP="@comment not installed: "
.endif

.if ${PORT_OPTIONS:MGNUTLS}
LIB_DEPENDS+=		libgnutls.so:security/gnutls
CONFIGURE_ARGS+=	--enable-gnutls=yes
PLIST_SUB+=		GNUTLS=""
.else
CONFIGURE_ARGS+=	--enable-gnutls=no
PLIST_SUB+=		GNUTLS="@comment "
.endif

.if ${PORT_OPTIONS:MNSS}
LIB_DEPENDS+=		libnss3.so:security/nss
CONFIGURE_ARGS+=	--enable-nss=yes \
			--with-nspr-includes=${LOCALBASE}/include/nspr \
			--with-nspr-libs=${LOCALBASE}/lib \
			--with-nss-includes=${LOCALBASE}/include/nss/nss \
			--with-nss-libs=${LOCALBASE}/lib/nss
PLIST_SUB+=		NSS=""
.else
CONFIGURE_ARGS+=	--enable-nss=no
PLIST_SUB+=		NSS="@comment "
.endif

.if ${PORT_OPTIONS:MSASL}
LIB_DEPENDS+=		libsasl2.so:security/cyrus-sasl2
CONFIGURE_ARGS+=	--enable-cyrus-sasl
.endif

.if ${PORT_OPTIONS:MBONJOUR}
LIB_DEPENDS+=	libavahi-client.so:net/avahi-app
PLIST_SUB+=	BONJOUR=""
PRPL_MODULES:=	bonjour,${PRPL_MODULES}
.else
CONFIGURE_ARGS+=--disable-avahi
PLIST_SUB+=	BONJOUR="@comment not installed: "
.endif

.if ${PORT_OPTIONS:MGTKSPELL}
LIB_DEPENDS+=		libgtkspell.so:textproc/gtkspell
.else
CONFIGURE_ARGS+=	--disable-gtkspell
.endif

.if ${PORT_OPTIONS:MDBUS}
LIB_DEPENDS+=		libdbus-glib-1.so:devel/dbus-glib
.if !defined(PIDGIN_SLAVE)
RUN_DEPENDS+=		${PYTHON_PKGNAMEPREFIX}dbus>=0:devel/py-dbus@${PY_FLAVOR}
.endif
CONFIGURE_ARGS+=	--enable-dbus
PLIST_SUB+=		DBUS=""
.else
CONFIGURE_ARGS+=	--disable-dbus
PLIST_SUB+=		DBUS="@comment not installed: "
.endif

.if ${PORT_OPTIONS:MSAMETIME}
LIB_DEPENDS+=	libmeanwhile.so:net-im/meanwhile
PLIST_SUB+=	SAMETIME=""
PRPL_MODULES:=	sametime,${PRPL_MODULES}
.else
PLIST_SUB+=	SAMETIME="@comment not installed: "
CONFIGURE_ARGS+=--disable-meanwhile
.endif

.if ${PORT_OPTIONS:MSILC}
LIB_DEPENDS+=		libsilcclient.so:devel/silc-toolkit
CONFIGURE_ARGS+=	--with-silc-includes=${LOCALBASE}/include/silc \
			--with-silc-libs=${LOCALBASE}/lib
PLIST_SUB+=		SILC=""
PRPL_MODULES:=		silc,${PRPL_MODULES}
.else
PLIST_SUB+=		SILC="@comment not installed: "
.endif

.if ${PORT_OPTIONS:MGG}
PLIST_SUB+=		GG=""
PRPL_MODULES:=		gg,${PRPL_MODULES}
.else
PLIST_SUB+=		GG="@comment not installed: "
.endif

.if ${PORT_OPTIONS:MIRC}
PLIST_SUB+=		IRC=""
PRPL_MODULES:=		irc,${PRPL_MODULES}
.else
PLIST_SUB+=		IRC="@comment not installed: "
.endif

.if ${PORT_OPTIONS:MJABBER}
PLIST_SUB+=		JABBER=""
PRPL_MODULES:=		jabber,${PRPL_MODULES}
.else
PLIST_SUB+=		JABBER="@comment not installed: "
.endif

.if ${PORT_OPTIONS:MNOVELL}
PLIST_SUB+=		NOVELL=""
PRPL_MODULES:=		novell,${PRPL_MODULES}
.else
PLIST_SUB+=		NOVELL="@comment not installed: "
.endif

.if ${PORT_OPTIONS:MOSCAR}
PLIST_SUB+=		OSCAR=""
PRPL_MODULES:=		oscar,${PRPL_MODULES}
.else
PLIST_SUB+=		OSCAR="@comment not installed: "
.endif

#.if ${PORT_OPTIONS:MQQ}
#PLIST_SUB+=		QQ=""
#PRPL_MODULES:=		qq,${PRPL_MODULES}
#.else
#PLIST_SUB+=		QQ="@comment not installed: "
#.endif

.if ${PORT_OPTIONS:MSIMPLE}
PLIST_SUB+=		SIMPLE=""
PRPL_MODULES:=		simple,${PRPL_MODULES}
.else
PLIST_SUB+=		SIMPLE="@comment not installed: "
.endif

.if ${PORT_OPTIONS:MZEPHYR}
PLIST_SUB+=		ZEPHYR=""
PRPL_MODULES:=		zephyr,${PRPL_MODULES}
.else
PLIST_SUB+=		ZEPHYR="@comment not installed: "
.endif

pre-everything::
.if ! ${PORT_OPTIONS:MGNUTLS} && ! ${PORT_OPTIONS:MNSS}
	@${ECHO_MSG} "WARNING: In order to use MSN, you must enable the GNUTLS and/or NSS options."
.endif

post-patch:
	@${REINPLACE_CMD} \
		-e 's|-lpthread $$LIBDL|-lpthread ${ICONV_LIB}|' \
		${WRKSRC}/configure
.if defined(PIDGIN_SLAVE)
	@${FIND} ${BUILD_WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -e \
		's|$$(top_builddir)/libpurple/libpurple.la|-lpurple|'
	@${REINPLACE_CMD} -e 's|gconftool-2|gconftool-disabled|g' \
		${WRKSRC}/configure
.endif

.if !defined(PIDGIN_SLAVE) && ${PORT_OPTIONS:MPERL}
post-install:
	@${SED} -i '' -e 's|^${STAGEDIR}||g' \
		${STAGEDIR}${PREFIX}/lib/purple-2/perl/auto/Purple/.packlist
.endif

.include <bsd.port.mk>
