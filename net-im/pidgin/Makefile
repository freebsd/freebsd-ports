# New ports collection makefile for:	gaim
# Date created:			26 Mar 1999
# Whom:				Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/net-im/gaim-devel/Makefile,v 1.5 2006/10/13 05:45:01 mezz Exp $
#

PORTNAME=	gaim
PORTVERSION=	2.0.0.b3.1
PORTREVISION=	3
CATEGORIES?=	net-im
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMESUFFIX=	-devel
DISTNAME=	gaim-2.0.0beta3.1

MAINTAINER=	marcus@FreeBSD.org
COMMENT=	Multi-protocol instant messaging client

LIB_DEPENDS=	startup-notification-1.0:${PORTSDIR}/x11/startup-notification

CONFLICTS?=	ja-gaim-[0-9]* gaim-1*

USE_XLIB=	yes
USE_PYTHON=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack gtk20
WANT_GNOME=	yes
USE_BZIP2=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include ${PTHREAD_CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib -L${X11BASE}/lib ${PTHREAD_LIBS}" \
		PTHREAD_LIB="${PTHREAD_LIBS}"

MAN1=		gaim.1

OPTIONS=	SILC "Secure Internet Live Conferencing support" off \
		GTKSPELL "Spell checking support" on \
		AUDIO "Audio support" on \
		GNUTLS "GNUTLS encryption support" off \
		NSS "Mozilla NSS encryption support" on \
		SASL "Cyrus SASL support (for jabberd)" off \
		DBUS "Enable DBUS bindings" on \
		PERL "Perl scripting" off \
		TCLTK "Tcl/Tk scripting" off \

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mevolutiondataserver}!=""
USE_GNOME+=		evolutiondataserver
PLIST_SUB+=		EVO=""
.else
CONFIGURE_ARGS+=	--disable-gevolution
PLIST_SUB+=		EVO="@comment not installed: "
.endif

.if defined(WITH_GNUTLS)
LIB_DEPENDS+=		gnutls:${PORTSDIR}/security/gnutls
CONFIGURE_ARGS+=	--enable-gnutls=yes
.else
CONFIGURE_ARGS+=	--enable-gnutls=no
.endif

.if defined(WITH_SILC)
LIB_DEPENDS+=		silcclient-1.0.3:${PORTSDIR}/devel/silc-toolkit
CONFIGURE_ARGS+=	--with-silc-includes=${LOCALBASE}/include/silc
PLIST_SUB+=		SILC=""
.else
PLIST_SUB+=		SILC="@comment not installed: "
.endif

.if !defined(WITHOUT_NSS)
LIB_DEPENDS+=		nss3:${PORTSDIR}/security/nss
CONFIGURE_ARGS+=	--enable-nss=yes \
			--with-nspr-includes=${LOCALBASE}/include/nspr \
			--with-nspr-libs=${LOCALBASE}/lib \
			--with-nss-includes=${LOCALBASE}/include/nss/nss \
			--with-nss-libs=${LOCALBASE}/lib
.else
CONFIGURE_ARGS+=	--enable-nss=no
.endif

.if defined(WITH_SASL)
LIB_DEPENDS+=		sasl2:${PORTSDIR}/security/cyrus-sasl2
CONFIGURE_ARGS+=	--enable-cyrus-sasl
.endif

.if defined(WITH_DBUS)
LIB_DEPENDS+=		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib
RUN_DEPENDS+=		${PYTHON_SITELIBDIR}/dbus/__init__.py:${PORTSDIR}/devel/py-dbus
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
MAN3PREFIX=		${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3+=			Gaim.3
.else
CONFIGURE_ARGS+=	--disable-perl
PLIST_SUB+=		PERL:="@comment not installed: "
.endif

.if !defined(WITHOUT_GTKSPELL)
LIB_DEPENDS+=		gtkspell.0:${PORTSDIR}/textproc/gtkspell
.else
CONFIGURE_ARGS+=	--disable-gtkspell
.endif

.if defined(WITH_TCLTK)
TCLTK_VER?=		8.4	# user can override it
TCLTK_VER_NODOT=	${TCLTK_VER:S/.//}
.if ${TCLTK_VER} != 8.3 && ${TCLTK_VER} != 8.4
.error Currently GAIM can only use Tcl/Tk 8.3 or 8.4
.endif
LIB_DEPENDS+=		tk${TCLTK_VER_NODOT}:${PORTSDIR}/x11-toolkits/tk${TCLTK_VER_NODOT}
CONFIGURE_ARGS+=	--with-tclconfig=${LOCALBASE}/lib/tcl${TCLTK_VER} \
			--with-tkconfig=${LOCALBASE}/lib/tk${TCLTK_VER}
CFLAGS+=		-I${LOCALBASE}/include/tk${TCLTK_VER} -I${LOCALBASE}/include/tcl${TCLTK_VER}
PLIST_SUB+=		TCL:=""
.else
PLIST_SUB+=		TCL:="@comment not installed: "
.endif

.if !defined(WITHOUT_AUDIO)
LIB_DEPENDS+=		ao.3:${PORTSDIR}/audio/libao \
			audiofile.0:${PORTSDIR}/audio/libaudiofile
.else
CONFIGURE_ARGS+=	--disable-audio
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
		-e 's|-lpthread|${PTHREAD_LIBS:S/"//g}|g' \
		-e 's|-lsilc -lsilcclient ${PTHREAD_LIBS} -ldl|-lsilc -lsilcclient ${PTHREAD_LIBS} -liconv|' \
		-e 's|TCL_VERSION found but 8.3 required|TCL_VERSION found but ${TCLTK_VER} required|g' \
		-e 's|TCL_MINOR_VERSION" -ne 3|TCL_MINOR_VERSION" -ne ${TCLTK_VER:E}|' \
			${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|{exec_prefix}|${PREFIX}|' \
			${WRKSRC}/gaim.service.in
	@${REINPLACE_CMD} -e 's|/usr/bin/python|${PYTHON_CMD}|' \
			${WRKSRC}/src/gaim-remote.py
	@${REINPLACE_CMD} -e 's|/bin/bash|${SH}|' \
			${WRKSRC}/src/gaim-send ${WRKSRC}/src/gaim-send-async

.include <bsd.port.post.mk>
