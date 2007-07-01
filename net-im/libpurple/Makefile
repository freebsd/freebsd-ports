# New ports collection makefile for:	gaim
# Date created:			26 Mar 1999
# Whom:				Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/net-im/libgaim/Makefile,v 1.10 2007/03/11 06:36:56 marcus Exp $
#

PORTNAME?=	libpurple
PORTVERSION=	2.0.2
PORTREVISION?=	1
CATEGORIES?=	net-im
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pidgin
DISTNAME=	pidgin-${PORTVERSION}

MAINTAINER?=	marcus@FreeBSD.org
COMMENT?=	Backend library for the Pidgin multi-protocol messaging client

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME?=	gnomeprefix gnomehack intlhack glib20
GNU_CONFIGURE=	yes
CONFIGURE_ARGS?=--disable-gtkui \
		--disable-consoleui \
		--with-dynamic_prpls=${PRPL_MODULES}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include ${PTHREAD_CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib -L${X11BASE}/lib ${PTHREAD_LIBS}" \
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

MAN1=		pidgin.1 finch.1

.endif

PRPL_MODULES=	gg,irc,jabber,msn,novell,oscar,qq,simple,yahoo,zephyr

OPTIONS=	SILC "Secure Internet Live Conferencing support" off \
		GNUTLS "GNUTLS encryption support" on \
		NSS "Mozilla NSS encryption support" off \
		SASL "Cyrus SASL support (for jabberd)" off \
		DBUS "Enable DBUS bindings" on \
		PERL "Perl scripting" off \
		BONJOUR "Enable mDNS support" on \
		SAMETIME "Enable Sametime client support" off \
		TCLTK "Tcl/Tk scripting" off

.if defined(WITH_GTKUI)
OPTIONS+=	GTKSPELL "Spell checking support" on \
		GSTREAMER "Use GStreamer for playing sounds" on \
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
.else
CONFIGURE_ARGS+=	--disable-gevolution
PLIST_SUB+=		EVO="@comment not installed: "
.endif

.if defined(WITH_GTKUI) && !defined(WITHOUT_GSTREAMER)
USE_GSTREAMER+=	core good
.else
CONFIGURE_ARGS+=--disable-gstreamer
.endif

.if defined(WITH_GTKUI) && !defined(WITHOUT_CAP)
LIB_DEPENDS+=	sqlite3.8:${PORTSDIR}/databases/sqlite3
PLIST_SUB+=	CAP=""
.else
CONFIGURE_ARGS+=--disable-cap
PLIST_SUB+=	CAP="@comment not installed: "
.endif

.if !defined(WITHOUT_GNUTLS)
LIB_DEPENDS+=		gnutls:${PORTSDIR}/security/gnutls
CONFIGURE_ARGS+=	--enable-gnutls=yes
.else
CONFIGURE_ARGS+=	--enable-gnutls=no
.endif

.if defined(WITH_NSS)
LIB_DEPENDS+=		nss3:${PORTSDIR}/security/nss
CONFIGURE_ARGS+=	--enable-nss=yes \
			--with-nspr-includes=${LOCALBASE}/include/nspr \
			--with-nspr-libs=${LOCALBASE}/lib \
			--with-nss-includes=${LOCALBASE}/include/nss/nss \
			--with-nss-libs=${LOCALBASE}/lib/nss
.else
CONFIGURE_ARGS+=	--enable-nss=no
.endif

.if defined(WITH_SASL)
LIB_DEPENDS+=		sasl2:${PORTSDIR}/security/cyrus-sasl2
CONFIGURE_ARGS+=	--enable-cyrus-sasl
.endif

.if defined(WITH_SILC)
LIB_DEPENDS+=		silcclient-1.0.4:${PORTSDIR}/devel/silc-toolkit
CONFIGURE_ARGS+=	--with-silc-includes=${LOCALBASE}/include/silc \
			--with-silc-libs=${LOCALBASE}/lib
PLIST_SUB+=		SILC=""
PRPL_MODULES:=		${PRPL_MODULES},silc
.else
PLIST_SUB+=		SILC="@comment not installed: "
.endif

.if !defined(WITHOUT_BONJOUR)
LIB_DEPENDS+=	avahi-core.5:${PORTSDIR}/net/avahi
PLIST_SUB+=	BONJOUR=""
PRPL_MODULES:=	${PRPL_MODULES},bonjour
.else
PLIST_SUB+=	BONJOUR="@comment not installed: "
.endif

.if defined(WITH_SAMETIME)
LIB_DEPENDS+=	meanwhile.1:${PORTSDIR}/net-im/meanwhile
PLIST_SUB+=	SAMETIME=""
PRPL_MODULES:=	${PRPL_MODULES},sametime
.else
PLIST_SUB+=	SAMETIME="@comment not installed: "
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
PLIST_SUB+=		TCL:="@comment not installed: "
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

.if defined(WITH_PERL) && ${PERL_LEVEL} >= 500800
USE_PERL5=		yes
CONFIGURE_ARGS+=	--with-perl-lib=site
PLIST_SUB+=		PERL:=""
.if !defined(PIDGIN_SLAVE)
MAN3PREFIX=		${TARGETDIR}/lib/perl5/${PERL_VERSION}
MAN3+=			Purple.3
.endif
.else
CONFIGURE_ARGS+=	--disable-perl
PLIST_SUB+=		PERL:="@comment not installed: "
.endif

.if defined(WITH_GTKUI) && !defined(WITHOUT_GTKSPELL)
LIB_DEPENDS+=		gtkspell.0:${PORTSDIR}/textproc/gtkspell
.else
CONFIGURE_ARGS+=	--disable-gtkspell
.endif

pre-everything::
.if defined(WITH_PERL) && ${PERL_LEVEL} < 500800
	@${ECHO_MSG} "WARNING: Perl scripting disabled (Perl 5.8 requirement not met)."
.endif
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

.include <bsd.port.post.mk>
