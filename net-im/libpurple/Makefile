# Created by: Jim Mock <jim@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/net-im/libpurple/Makefile,v 1.32 2010/05/10 04:21:19 marcus Exp $

PORTNAME?=	libpurple
PORTVERSION=	2.10.7
PORTREVISION?=	2
CATEGORIES?=	net-im
MASTER_SITES=	SF/pidgin/Pidgin/${PORTVERSION}
DISTNAME=	pidgin-${PORTVERSION}

MAINTAINER?=	marcus@FreeBSD.org
COMMENT?=	Backend library for the Pidgin multi-protocol messaging client

USE_BZIP2=	yes
USES=		gmake pkgconfig
USE_GNOME?=	gnomeprefix gnomehack intlhack glib20 libxml2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS?=--disable-gtkui \
		--disable-consoleui \
		--with-dynamic_prpls=${PRPL_MODULES:S/,$//} \
		--enable-static \
		--disable-nm
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}" \
		PTHREAD_LIB="${PTHREAD_LIBS}"
CFLAGS+=	-D_XOPEN_SOURCE_EXTENDED
CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}

.if !defined(PIDGIN_SLAVE)
# Pidgin slave ports that require the following functionality, must explicitly
# set these macros themselves.
USES+=		gettext iconv
USE_LDCONFIG=	yes
WANT_GNOME=	yes
USE_PYTHON=	yes

.if defined(PACKAGE_BUILDING)
.undef WITHOUT_GNOME
WITH_GNOME=	yes
.endif

.endif

PRPL_MODULES=

OPTIONS_DEFINE=	BONJOUR DBUS GNUTLS NSS SASL GSTREAMER VV IDN PERL TCLTK \
		SAMETIME SILC GG IRC JABBER MSN MYSPACE NOVELL OSCAR QQ \
		SIMPLE YAHOO ZEPHYR
OPTIONS_DEFAULT=	BONJOUR DBUS NSS GSTREAMER VV IDN GG IRC JABBER MSN \
			MYSPACE NOVELL OSCAR QQ SIMPLE YAHOO ZEPHYR
BONJOUR_DESC=	mDNS support
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
MSN_DESC=	The MSN Messenger protocol
MYSPACE_DESC=	The MySpaceIM protocol
NOVELL_DESC=	The Novell GroupWise chat protocol
OSCAR_DESC=	The AIM/ICQ/Oscar protocol
QQ_DESC=	The Tercent QQ chat protocol
SIMPLE_DESC=	The SIMPLE chat protocol
YAHOO_DESC=	The Yahoo! Messenger protocol
ZEPHYR_DESC=	The Zephyr chat protocol

.if defined(WITH_GTKUI)
OPTIONS_DEFINE+=	GTKSPELL CAP
OPTIONS_DEFAULT+=	GTKSPELL CAP
GTKSPELL_DESC=	Spell checking support
CAP_DESC=	Contact Availability Prediction plugin
.endif

OPTIONSFILE=	${PORT_DBDIR}/${UNIQUENAME}/options

CONFIGURE_ARGS+=--disable-doxygen

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTCLTK}
USE_TK=			yes
CFLAGS+=		-I${LOCALBASE}/include/tk${TK_VER} -I${LOCALBASE}/include/tcl${TCL_VER}
CONFIGURE_ARGS+=	--with-tclconfig=${LOCALBASE}/lib/tcl${TCL_VER} \
			--with-tkconfig=${LOCALBASE}/lib/tk${TK_VER}
PLIST_SUB+=		TCL:=""
.else
CONFIGURE_ARGS+=	--disable-tcl
PLIST_SUB+=		TCL:="@comment not installed: "
.endif

.include <bsd.port.pre.mk>

.if !defined(PIDGIN_SLAVE)
.if ${HAVE_GNOME:Mgconf2}!="" || exists(${LOCALBASE}/bin/gconftool-2)
USE_GNOME+=	gconf2
GCONF_SCHEMAS=	purple.schemas
.endif
.endif

#.if defined(WITH_GTKUI) && ${HAVE_GNOME:Mevolutiondataserver}!=""
#USE_GNOME+=		evolutiondataserver
#PLIST_SUB+=		EVO=""
#CONFIGURE_ARGS+=	--enable-gevolution
#.else
CONFIGURE_ARGS+=	--disable-gevolution
PLIST_SUB+=		EVO="@comment not installed: "
#.endif

.if ${PORT_OPTIONS:MGSTREAMER}
USE_GSTREAMER+=	core good
.else
CONFIGURE_ARGS+=--disable-gstreamer
.endif

.if ${PORT_OPTIONS:MVV} && ${PORT_OPTIONS:MGSTREAMER}
LIB_DEPENDS+=	gstfarsight-0.10.0:${PORTSDIR}/net-im/farsight2
USE_GSTREAMER+=	v4l2
PLIST_SUB+=	VV=""
.else
CONFIGURE_ARGS+=--disable-vv
PLIST_SUB+=	VV="@comment "
.endif

.if ${PORT_OPTIONS:MIDN}
LIB_DEPENDS+=	idn.17:${PORTSDIR}/dns/libidn
.else
CONFIGURE_ARGS+=--disable-idn
.endif

.if ${PORT_OPTIONS:MCAP}
LIB_DEPENDS+=	sqlite3.8:${PORTSDIR}/databases/sqlite3
CONFIGURE_ARGS+=--enable-cap
PLIST_SUB+=	CAP=""
.else
CONFIGURE_ARGS+=--disable-cap
PLIST_SUB+=	CAP="@comment not installed: "
.endif

.if ${PORT_OPTIONS:MGNUTLS}
LIB_DEPENDS+=		gnutls:${PORTSDIR}/security/gnutls
CONFIGURE_ARGS+=	--enable-gnutls=yes
PLIST_SUB+=		GNUTLS=""
.else
CONFIGURE_ARGS+=	--enable-gnutls=no
PLIST_SUB+=		GNUTLS="@comment "
.endif

.if ${PORT_OPTIONS:MNSS}
LIB_DEPENDS+=		nss3:${PORTSDIR}/security/nss
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
LIB_DEPENDS+=		sasl2:${PORTSDIR}/security/cyrus-sasl2
CONFIGURE_ARGS+=	--enable-cyrus-sasl
.endif

.if ${PORT_OPTIONS:MBONJOUR}
LIB_DEPENDS+=	avahi-client.3:${PORTSDIR}/net/avahi-app
PLIST_SUB+=	BONJOUR=""
PRPL_MODULES:=	bonjour,${PRPL_MODULES}
.else
CONFIGURE_ARGS+=--disable-avahi
PLIST_SUB+=	BONJOUR="@comment not installed: "
.endif

.if ${PORT_OPTIONS:MGTKSPELL}
LIB_DEPENDS+=		gtkspell.0:${PORTSDIR}/textproc/gtkspell
.else
CONFIGURE_ARGS+=	--disable-gtkspell
.endif

.if ${PORT_OPTIONS:MDBUS}
LIB_DEPENDS+=		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib
.if !defined(PIDGIN_SLAVE)
RUN_DEPENDS+=		${PYTHON_SITELIBDIR}/dbus/__init__.py:${PORTSDIR}/devel/py-dbus
.endif
CONFIGURE_ARGS+=	--enable-dbus
PLIST_SUB+=		DBUS=""
.else
CONFIGURE_ARGS+=	--disable-dbus
PLIST_SUB+=		DBUS="@comment not installed: "
.endif

.if ${PORT_OPTIONS:MPERL}
USES+=			perl5
CONFIGURE_ARGS+=	--with-perl-lib=site
PLIST_SUB+=		PERL:=""
.if !defined(PIDGIN_SLAVE)
MAN3+=			Purple.3
.endif
.else
CONFIGURE_ARGS+=	--disable-perl
PLIST_SUB+=		PERL:="@comment not installed: "
.endif

.if ${PORT_OPTIONS:MSAMETIME}
LIB_DEPENDS+=	meanwhile.1:${PORTSDIR}/net-im/meanwhile
PLIST_SUB+=	SAMETIME=""
PRPL_MODULES:=	sametime,${PRPL_MODULES}
.else
PLIST_SUB+=	SAMETIME="@comment not installed: "
CONFIGURE_ARGS+=--disable-meanwhile
.endif

.if ${PORT_OPTIONS:MSILC}
LIB_DEPENDS+=		silcclient-1.1:${PORTSDIR}/devel/silc-toolkit
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

.if ${PORT_OPTIONS:MMSN}
PLIST_SUB+=		MSN=""
PRPL_MODULES:=		msn,${PRPL_MODULES}
.else
PLIST_SUB+=		MSN="@comment not installed: "
.endif

.if ${PORT_OPTIONS:MMYSPACE}
PLIST_SUB+=		MYSPACE=""
PRPL_MODULES:=		myspace,${PRPL_MODULES}
.else
PLIST_SUB+=		MYSPACE="@comment not installed: "
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

.if ${PORT_OPTIONS:MYAHOO}
PLIST_SUB+=		YAHOO=""
PRPL_MODULES:=		yahoo,${PRPL_MODULES}
.else
PLIST_SUB+=		YAHOO="@comment not installed: "
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
	@${REINPLACE_CMD} -e 's|-lpthreads|${PTHREAD_LIBS:S/"//g}|g' \
		-e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		-e 's|-lpanel |-lpanel -lncurses|g' \
		-e 's|-lpthread|${PTHREAD_LIBS:S/"//g}|g' \
		-e 's|-lsilc -lsilcclient ${PTHREAD_LIBS} $$LIBDL|-lsilc -lsilcclient ${PTHREAD_LIBS} ${ICONV_LIB}|' \
		-e 's|TCL_VERSION found but 8.3 required|TCL_VERSION found but ${TCLTK_VER} required|g' \
		-e 's|TCL_MINOR_VERSION" -ne 3|TCL_MINOR_VERSION" -ne ${TCLTK_VER:E}|' \
			${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/bin/bash|${SH}|' \
			${WRKSRC}/libpurple/purple-send \
			${WRKSRC}/libpurple/purple-send-async
	@${REINPLACE_CMD} -e 's|/python|/env python|' \
	    		${WRKSRC}/libpurple/purple-remote \
			${WRKSRC}/libpurple/purple-url-handler
.if defined(PIDGIN_SLAVE)
	@${FIND} ${BUILD_WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -e \
		's|[$$][(]top_builddir[)]/libpurple/libpurple.la|${LOCALBASE}/lib/libpurple.la|g'
.endif
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${TOUCH}

.include <bsd.port.post.mk>
