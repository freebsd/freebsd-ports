# New ports collection makefile for:	gaim
# Date created:			26 Mar 1999
# Whom:				Jim Mock <jim@FreeBSD.org>
# $FreeBSD$
#

PORTNAME=	gaim
PORTVERSION=	0.76
PORTREVISION=	1
CATEGORIES?=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER?=	marcus@FreeBSD.org
COMMENT=	Gtk+-2.0 open-source 'clone' of AOL's Instant Messenger client

LIB_DEPENDS=	startup-notification-1.0:${PORTSDIR}/x11/startup-notification

CONFLICTS?=	ja-gaim-*

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_GNOME=	gnomeprefix gnomehack gtk20
USE_PERL5=	yes
USE_BZIP2=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-static=yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include ${PTHREAD_CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib -L${X11BASE}/lib ${PTHREAD_LIBS}" \
		PTHREAD_LIB="${PTHREAD_LIBS}"

MAN1=		gaim.1 gaim-remote.1

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libgnutls.so) && !defined(WITHOUT_GNUTLS)
WITH_GNUTLS=	yes
.endif

.if defined(WITH_GNUTLS)
LIB_DEPENDS+=		gnutls:${PORTSDIR}/security/gnutls
.else
CONFIGURE_ARGS+=	--disable-gnutls
.endif

.if !defined(WITHOUT_NSS)
LIB_DEPENDS+=		nss3:${PORTSDIR}/security/nss
CONFIGURE_ARGS+=	--with-nspr-includes=${LOCALBASE}/include/nspr \
			--with-nspr-libs=${LOCALBASE}/lib \
			--with-nss-includes=${LOCALBASE}/include/nss/nss \
			--with-nss-libs=${LOCALBASE}/lib
.else
CONFIGURE_ARGS+=	--enable-nss=no
.endif

.if ${PERL_LEVEL} < 500800
CONFIGURE_ARGS+=	--disable-perl
PLIST_SUB+=		PERL:="@comment "
.else
CONFIGURE_ARGS+=	--with-perl-lib=site
PLIST_SUB+=		PERL:=""
.endif

.ifndef(WITHOUT_GTKSPELL)
LIB_DEPENDS+=	gtkspell.0:${PORTSDIR}/textproc/gtkspell2
.else
CONFIGURE_ARGS+=	--disable-gtkspell
.endif

.if defined(TCL_VER)
_TCL_DVER=	${TCL_VER:S/.//}
_TCL_VER=	${_TCL_DVER:C/(.)/\1./}
.if ${_TCL_VER} != 8.3 && ${_TCL_VER} != 8.4
.	error Currently GAIM can only use Tcl/Tk 8.3 or 8.4
.endif
LIB_DEPENDS+=	tk${_TCL_DVER}:${PORTSDIR}/x11-toolkits/tk${_TCL_DVER}
CONFIGURE_ARGS+=--with-tclconfig=${LOCALBASE}/lib/tcl${_TCL_VER} \
		--with-tkconfig=${LOCALBASE}/lib/tk${_TCL_VER}
CFLAGS+=	-I${LOCALBASE}/include/tk${_TCL_VER} -I${LOCALBASE}/include/tcl${_TCL_VER}
PLIST_SUB+=	TCL:=""
.else
PLIST_SUB+=	TCL:="@comment "
.endif

.ifndef(WITHOUT_AUDIO)
LIB_DEPENDS+=	ao.3:${PORTSDIR}/audio/libao \
		audiofile.0:${PORTSDIR}/audio/libaudiofile
.else
CONFIGURE_ARGS+=	--disable-audio
.endif

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Gaim has the following tunable option(s):"
	@${ECHO_MSG} "	WITHOUT_GTKSPELL	Turns off spell checking"
	@${ECHO_MSG} "	WITHOUT_AUDIO		Disable audio support"
	@${ECHO_MSG} "	WITH_GNUTLS		Enable GNUTLS encryption support"
	@${ECHO_MSG} "	WITHOUT_GNUTLS		Disable GNUTLS encryption support"
	@${ECHO_MSG} "	WITHOUT_NSS		Disable Mozilla NSS encryption support"
	@${ECHO_MSG} "	TCL_VER			Use Tcl/Tk (version)"
	@${ECHO_MSG} ""
.if !defined(WITH_GNUTLS) && defined(WITHOUT_NSS)
	@${ECHO_MSG} "WARNING: In order to use MSN, you must define WITH_GNUTLS and/or WITH_NSS."
	@${ECHO_MSG} ""
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthreads|${PTHREAD_LIBS:S/"//g}|g' \
		-e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		-e 's|-lpthread|${PTHREAD_LIBS:S/"//g}|g' \
		-e 's|TCL_VERSION found but 8.3 required|TCL_VERSION found but ${_TCL_VER} required|g' \
		-e 's|TCL_MINOR_VERSION" -ne 3|TCL_MINOR_VERSION" -ne ${_TCL_VER:E}|' \
			${WRKSRC}/configure

.include <bsd.port.post.mk>
