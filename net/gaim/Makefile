# New ports collection makefile for:	gaim
# Date created:			26 Mar 1999
# Whom:				Jim Mock <jim@FreeBSD.org>
# $FreeBSD$
#

PORTNAME=	gaim
PORTVERSION=	0.66
PORTREVISION=	1
CATEGORIES?=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER?=	marcus@FreeBSD.org
COMMENT=	Gtk+-2.0 open-source 'clone' of AOL's Instant Messenger client

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_GNOME=	gnomeprefix gnomehack gtk20
USE_PERL5=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-static=yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

MAN1=		gaim.1 gaim-remote.1

.ifndef(WITHOUT_GTKSPELL)
LIB_DEPENDS+=	gtkspell.0:${PORTSDIR}/textproc/gtkspell2
.else
CONFIGURE_ARGS+=	--disable-gtkspell
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
	@${ECHO_MSG} "		WITHOUT_GTKSPELL	Turns off spell checking"
	@${ECHO_MSG} "		WITHOUT_AUDIO		Disable audio support"
	@${ECHO_MSG} ""

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthreads|${PTHREAD_LIBS:S/"//g}|g; \
		s|-lpthread|${PTHREAD_LIBS:S/"//g}|g' ${WRKSRC}/configure

.include <bsd.port.mk>
