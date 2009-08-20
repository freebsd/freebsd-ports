# New ports collection makefile for:	gaim
# Date created:			26 Mar 1999
# Whom:				Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/net-im/libpurple/Makefile,v 1.27 2007/10/11 16:32:55 marcus Exp $
#

PORTNAME?=	libpurple
PORTVERSION=	2.6.1
PORTREVISION?=	1
CATEGORIES?=	net-im
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_PROJECT}
MASTER_SITE_SUBDIR=	pidgin/Pidgin/${PORTVERSION}
DISTNAME=	pidgin-${PORTVERSION}

MAINTAINER?=	marcus@FreeBSD.org
COMMENT?=	Backend library for the Pidgin multi-protocol messaging client

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME?=	gnomeprefix gnomehack intlhack glib20 libxml2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS?=--disable-gtkui \
		--disable-consoleui \
		--with-dynamic_prpls=${PRPL_MODULES:S/,$//} \
		--disable-nm
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}" \
		PTHREAD_LIB="${PTHREAD_LIBS}"

.if !defined(PIDGIN_SLAVE)
# Pidgin slave ports that require the following functionality, must explicitly
# set these macros themselves.
USE_GETTEXT=	yes
USE_ICONV=	yes
USE_LDCONFIG=	yes
WANT_GNOME=	yes
USE_PYTHON=	yes

.if defined(PACKAGE_BUILDING)
.undef WITHOUT_GNOME
WITH_GNOME=	yes
.endif

.endif

PRPL_MODULES=

OPTIONS=	BONJOUR "Enable mDNS support" on \
		DBUS "Enable DBUS bindings" on \
		GNUTLS "GNUTLS encryption support" off \
		NSS "Mozilla NSS encryption support" on \
		SASL "Cyrus SASL support (for jabberd)" off \
		GSTREAMER "Use GStreamer for playing sounds" on \
		VV "Enable video and voice support" on \
		IDN "Enable support for international domains" on
		PERL "Perl scripting" off \
		TCLTK "Tcl/Tk scripting" off \
		SAMETIME "The Lotus Sametime chat protocol" off \
		SILC "The Secure Internet Live Conferencing protocol" off \
		GG "The Gadu-Gadu chat protocol" on \
		IRC "The Internet Relay Chat protocol" on \
		JABBER "The Jabber/XMPP/Google Talk protocol" on \
		MSN "The MSN Messenger protocol" on \
		MYSPACE "The MySpaceIM protocol" on \
		NOVELL "The Novell GroupWise chat protocol" on \
		OSCAR "The AIM/ICQ/Oscar protocol" on \
		QQ "The Tercent QQ chat protocol" on \
		SIMPLE "The SIMPLE chat protocol" on \
		YAHOO "The Yahoo! Messenger protocol" on \
		ZEPHYR "The Zephyr chat protocol" on

.if defined(WITH_GTKUI)
OPTIONS+=	GTKSPELL "Spell checking support" on \
		CAP "Enable Contact Availability Prediction plugin" on
.endif

CONFIGURE_ARGS+=--disable-doxygen

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 700032 || (${OSVERSION} < 700000 && ${OSVERSION} > 602106)
CFLAGS+=	-D_XOPEN_SOURCE_EXTENDED
.endif

.if !defined(PIDGIN_SLAVE)
.if ${HAVE_GNOME:Mgconf2}!="" || exists(${LOCALBASE}/bin/gconftool-2)
USE_GNOME+=	gconf2
GCONF_SCHEMAS=	purple.schemas
.endif
.endif

.if defined(WITH_GTKUI) && ${HAVE_GNOME:Mevolutiondataserver}!=""
USE_GNOME+=		evolutiondataserver
PLIST_SUB+=		EVO=""
CONFIGURE_ARGS+=	--enable-gevolution
.else
CONFIGURE_ARGS+=	--disable-gevolution
PLIST_SUB+=		EVO="@comment not installed: "
.endif

.if !defined(WITHOUT_GSTREAMER)
USE_GSTREAMER+=	core good
.else
CONFIGURE_ARGS+=--disable-gstreamer
.endif

.if !defined(WITHOUT_VV)
LIB_DEPENDS+=	gstfarsight-0.10.0:${PORTSDIR}/net-im/farsight2
.else
CONFIGURE_ARGS+=--disable-vv
.endif

.if !defined(WITHOUT_IDN)
LIB_DEPENDS+=	idn.16:${PORTSDIR}/dns/libidn
.else
CONFIGURE_ARGS+=--disable-idn
.endif

.if defined(WITH_GTKUI) && !defined(WITHOUT_CAP)
LIB_DEPENDS+=	sqlite3.8:${PORTSDIR}/databases/sqlite3
CONFIGURE_ARGS+=--enable-cap
PLIST_SUB+=	CAP=""
.else
CONFIGURE_ARGS+=--disable-cap
PLIST_SUB+=	CAP="@comment not installed: "
.endif

.if defined(WITH_GNUTLS)
LIB_DEPENDS+=		gnutls:${PORTSDIR}/security/gnutls
CONFIGURE_ARGS+=	--enable-gnutls=yes
PLIST_SUB+=		GNUTLS=""
.else
CONFIGURE_ARGS+=	--enable-gnutls=no
PLIST_SUB+=		GNUTLS="@comment "
.endif

.if !defined(WITHOUT_NSS)
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

.if defined(WITH_SASL)
LIB_DEPENDS+=		sasl2:${PORTSDIR}/security/cyrus-sasl2
CONFIGURE_ARGS+=	--enable-cyrus-sasl
.endif

.if !defined(WITHOUT_BONJOUR)
LIB_DEPENDS+=	avahi-client.3:${PORTSDIR}/net/avahi-app
PLIST_SUB+=	BONJOUR=""
PRPL_MODULES:=	bonjour,${PRPL_MODULES}
.else
CONFIGURE_ARGS+=--disable-avahi
PLIST_SUB+=	BONJOUR="@comment not installed: "
.endif

.if defined(WITH_TCLTK)
TCLTK_VER?=		8.4	# user can override it
TCLTK_VER_NODOT=	${TCLTK_VER:S/.//}
.if ${TCLTK_VER} != 8.3 && ${TCLTK_VER} != 8.4
.error Currently Pidgin can only use Tcl/Tk 8.3 or 8.4
.endif
LIB_DEPENDS+=		tk${TCLTK_VER_NODOT}:${PORTSDIR}/x11-toolkits/tk${TCLTK_VER_NODOT}
CONFIGURE_ARGS+=	--with-tclconfig=${LOCALBASE}/lib/tcl${TCLTK_VER} \
			--with-tkconfig=${LOCALBASE}/lib/tk${TCLTK_VER}
CFLAGS+=		-I${LOCALBASE}/include/tk${TCLTK_VER} -I${LOCALBASE}/include/tcl${TCLTK_VER}
PLIST_SUB+=		TCL:=""
.else
CONFIGURE_ARGS+=	--disable-tcl
PLIST_SUB+=		TCL:="@comment not installed: "
.endif

.if defined(WITH_GTKUI) && !defined(WITHOUT_GTKSPELL)
LIB_DEPENDS+=		gtkspell.0:${PORTSDIR}/textproc/gtkspell
.else
CONFIGURE_ARGS+=	--disable-gtkspell
.endif

.if !defined(WITHOUT_DBUS)
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

.if defined(WITH_PERL)
USE_PERL5=		yes
CONFIGURE_ARGS+=	--with-perl-lib=site
PLIST_SUB+=		PERL:=""
.if !defined(PIDGIN_SLAVE)
MAN3PREFIX=		${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3+=			Purple.3
.endif
.else
CONFIGURE_ARGS+=	--disable-perl
PLIST_SUB+=		PERL:="@comment not installed: "
.endif

.if defined(WITH_SAMETIME)
LIB_DEPENDS+=	meanwhile.1:${PORTSDIR}/net-im/meanwhile
PLIST_SUB+=	SAMETIME=""
PRPL_MODULES:=	sametime,${PRPL_MODULES}
.else
PLIST_SUB+=	SAMETIME="@comment not installed: "
CONFIGURE_ARGS+=--disable-meanwhile
.endif

.if defined(WITH_SILC)
LIB_DEPENDS+=		silcclient-1.1:${PORTSDIR}/devel/silc-toolkit
CONFIGURE_ARGS+=	--with-silc-includes=${LOCALBASE}/include/silc \
			--with-silc-libs=${LOCALBASE}/lib
PLIST_SUB+=		SILC=""
PRPL_MODULES:=		silc,${PRPL_MODULES}
.else
PLIST_SUB+=		SILC="@comment not installed: "
.endif

.if !defined(WITHOUT_GG)
PLIST_SUB+=		GG=""
PRPL_MODULES:=		gg,${PRPL_MODULES}
.else
PLIST_SUB+=		GG="@comment not installed: "
.endif

.if !defined(WITHOUT_IRC)
PLIST_SUB+=		IRC=""
PRPL_MODULES:=		irc,${PRPL_MODULES}
.else
PLIST_SUB+=		IRC="@comment not installed: "
.endif

.if !defined(WITHOUT_JABBER)
PLIST_SUB+=		JABBER=""
PRPL_MODULES:=		jabber,${PRPL_MODULES}
.else
PLIST_SUB+=		JABBER="@comment not installed: "
.endif

.if !defined(WITHOUT_MSN)
PLIST_SUB+=		MSN=""
PRPL_MODULES:=		msn,${PRPL_MODULES}
.else
PLIST_SUB+=		MSN="@comment not installed: "
.endif

.if !defined(WITHOUT_MYSPACE)
PLIST_SUB+=		MYSPACE=""
PRPL_MODULES:=		myspace,${PRPL_MODULES}
.else
PLIST_SUB+=		MYSPACE="@comment not installed: "
.endif

.if !defined(WITHOUT_NOVELL)
PLIST_SUB+=		NOVELL=""
PRPL_MODULES:=		novell,${PRPL_MODULES}
.else
PLIST_SUB+=		NOVELL="@comment not installed: "
.endif

.if !defined(WITHOUT_OSCAR)
PLIST_SUB+=		OSCAR=""
PRPL_MODULES:=		oscar,${PRPL_MODULES}
.else
PLIST_SUB+=		OSCAR="@comment not installed: "
.endif

.if !defined(WITHOUT_QQ)
PLIST_SUB+=		QQ=""
PRPL_MODULES:=		qq,${PRPL_MODULES}
.else
PLIST_SUB+=		QQ="@comment not installed: "
.endif

.if !defined(WITHOUT_SIMPLE)
PLIST_SUB+=		SIMPLE=""
PRPL_MODULES:=		simple,${PRPL_MODULES}
.else
PLIST_SUB+=		SIMPLE="@comment not installed: "
.endif

.if !defined(WITHOUT_YAHOO)
PLIST_SUB+=		YAHOO=""
PRPL_MODULES:=		yahoo,${PRPL_MODULES}
.else
PLIST_SUB+=		YAHOO="@comment not installed: "
.endif

.if !defined(WITHOUT_ZEPHYR)
PLIST_SUB+=		ZEPHYR=""
PRPL_MODULES:=		zephyr,${PRPL_MODULES}
.else
PLIST_SUB+=		ZEPHYR="@comment not installed: "
.endif

pre-everything::
.if defined(WITHOUT_GNUTLS) && defined(WITHOUT_NSS)
	@${ECHO_MSG} "WARNING: In order to use MSN, you must enable the GNUTLS and/or NSS options."
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthreads|${PTHREAD_LIBS:S/"//g}|g' \
		-e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		-e 's|-lpanel |-lpanel -lncurses|g' \
		-e 's|-lpthread|${PTHREAD_LIBS:S/"//g}|g' \
		-e 's|-lsilc -lsilcclient ${PTHREAD_LIBS} $$LIBDL|-lsilc -lsilcclient ${PTHREAD_LIBS} -liconv|' \
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
