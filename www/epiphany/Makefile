# Ports collection Makefile for:	epiphany
# Date created:				24 April 2003
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	epiphany
PORTVERSION=	1.0.7
PORTREVISION=	2
CATEGORIES=	www gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/1.0
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	An extremely lightweight and simple web browser for GNOME 2

BUILD_DEPENDS=	${X11BASE}/lib/${MOZILLA}/components/libwidget_gtk2.so:${PORTSDIR}/www/${MOZILLA}
RUN_DEPENDS=	${X11BASE}/lib/${MOZILLA}/components/libwidget_gtk2.so:${PORTSDIR}/www/${MOZILLA}

MOZ_CONFIGURE_ARGS=	--with-mozilla-snapshot="1.6"

MOZILLA=	mozilla-gtk2
HEADERS_SUFX=

.if !defined(WITH_MOZILLA)
MOZILLA=	mozilla-gtk2
HEADERS_SUFX=
.else
.if ${WITH_MOZILLA}=="mozilla-devel-gtk2"
MOZILLA=	${WITH_MOZILLA}
HEADERS_SUFX=	-devel
MOZ_CONFIGURE_ARGS=	--with-mozilla-snapshot="1.6b"
.else
MOZILLA=	mozilla-gtk2
HEADERS_SUFX=
.endif
.endif

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack libgnomeui
WANT_GNOME=	yes
USE_LIBTOOL=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
CONFIGURE_ARGS=	--with-mozilla-includes="${X11BASE}/include/mozilla${HEADERS_SUFX}" \
		--with-mozilla-libs="${X11BASE}/lib/${MOZILLA}" \
		${MOZ_CONFIGURE_ARGS}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include ${PTHREAD_CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

FLASHPLAYER=	${LOCALBASE}/lib/libflashplayer.so.1
XXX_FILES=	EphyAutomation-common.c EphyAutomation-stubs.c \
	   	EphyAutomation-skels.c EphyAutomation.h

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mnautilus2}!=""
USE_GNOME+=		nautilus2
CONFIGURE_ARGS+=	--enable-nautilus-view
.else
CONFIGURE_ARGS+=	--enable-nautilus-view=no
.endif

.if ${OSVERSION} > 500000
# Galeon does not build correctly in -CURRENT if -Werror is passed
# to the compiler.
NO_WERROR=	yes
.endif
# allow build with more warnings enabled
.if defined(NO_WERROR)
CONFIGURE_ARGS+=	--disable-werror
.endif

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} " By default epiphany uses www/mozilla-gtk2 for html rendering, but you can"
	@${ECHO_MSG} " change this by defining WITH_MOZILLA to one of the following values:"
	@${ECHO_MSG}
	@${ECHO_MSG} "  mozilla-devel-gtk2 "
	@${ECHO_MSG} ""

post-extract:
.for i in ${XXX_FILES}
	@${RM} -f ${WRKSRC}/src/${i}
.endfor

post-patch:
	@${REINPLACE_CMD} -e 's|mozilla-gtkmozembed|mozilla-gtkmozembed${HEADERS_SUFX}-gtk2|g' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name "Makefile.in*" | ${XARGS} ${REINPLACE_CMD} -e \
		 's|-lpthread|${PTHREAD_LIBS}|g'
	@${FIND} ${WRKSRC} -name "*.cpp" | ${XARGS} ${REINPLACE_CMD} -e \
		's|malloc\.h|stdlib.h|g'

post-configure:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g ; \
		s|%%LOCALBASE%%|${LOCALBASE}|g ; \
		s|%%X11BASE%%|${X11BASE}|g ; \
		s|%%MOZILLA%%|${MOZILLA}|g ; \
		s|%%FLASHPLAYER%%|${FLASHPLAYER}|g' ${WRKSRC}/src/epiphany

pre-install:
	@-${X11BASE}/bin/gconftool-2 --shutdown

.include <bsd.port.post.mk>
