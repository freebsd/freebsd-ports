# Ports collection Makefile for:	epiphany
# Date created:				24 April 2003
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	epiphany
PORTVERSION=	1.4.6
CATEGORIES=	www gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/1.4
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	An extremely lightweight and simple web browser for GNOME 2

BUILD_DEPENDS=	${X11BASE}/lib/${MOZILLA}/components/libwidget_gtk2.so:${PORTSDIR}/www/${MOZILLA}
RUN_DEPENDS=	${X11BASE}/lib/${MOZILLA}/components/libwidget_gtk2.so:${PORTSDIR}/www/${MOZILLA}

MOZILLA=	mozilla
HEADERS_SUFX=

.if !defined(WITH_MOZILLA)
MOZILLA=	mozilla
HEADERS_SUFX=
.else
.if ${WITH_MOZILLA}=="mozilla-devel" || ${WITH_MOZILLA}=="mozilla-devel-gtk2"
MOZILLA=	mozilla-devel
HEADERS_SUFX=	-devel
.else
MOZILLA=	mozilla
HEADERS_SUFX=
.endif
.endif

USE_BZIP2=	yes
USE_X_PREFIX=	yes
INSTALLS_OMF=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack libgnomeui desktopfileutils
USE_LIBTOOL_VER=15
USE_GMAKE=	yes
USE_REINPLACE=	yes
CONFIGURE_ARGS=	--with-mozilla-includes="${X11BASE}/include/mozilla${HEADERS_SUFX}" \
		--with-mozilla-libs="${X11BASE}/lib/${MOZILLA}"
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include ${PTHREAD_CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

GCONF_SCHEMAS=	epiphany-lockdown.schemas epiphany.schemas

FLASHPLAYER=	${LOCALBASE}/lib/libflashplayer.so.1
PLIST_SUB+=	EPHY_VERSION="${PORTVERSION:C/\.[0-9]+$//}"

MAN1=		epiphany.1

.include <bsd.port.pre.mk>

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
	@${ECHO_MSG} " By default epiphany uses www/mozilla for html rendering, but you can"
	@${ECHO_MSG} " change this by defining WITH_MOZILLA to one of the following values:"
	@${ECHO_MSG}
	@${ECHO_MSG} "  mozilla-devel "
	@${ECHO_MSG} ""

post-patch:
	@${REINPLACE_CMD} -e 's|mozilla-gtkmozembed|mozilla-gtkmozembed${HEADERS_SUFX}|g ; \
		s|mozilla-xpcom|mozilla-xpcom${HEADERS_SUFX}|g ; \
		s|$$MOZILLA-gtkmozembed|$$MOZILLA-gtkmozembed${HEADERS_SUFX}|g ; \
		s|$$MOZILLA-xpcom|$$MOZILLA-xpcom${HEADERS_SUFX}|g' \
		${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name "Makefile.in*" | ${XARGS} ${REINPLACE_CMD} -e \
		 's|-lpthread|${PTHREAD_LIBS}|g'
	@${FIND} ${WRKSRC} -name "*.cpp" | ${XARGS} ${REINPLACE_CMD} -e \
		's|malloc\.h|stdlib.h|g'

post-configure:
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|g ; \
		s|%%LOCALBASE%%|${LOCALBASE}|g ; \
		s|%%X11BASE%%|${X11BASE}|g ; \
		s|%%MOZILLA%%|${MOZILLA}|g ; \
		s|%%FLASHPLAYER%%|${FLASHPLAYER}|g' <${FILESDIR}/epiphany \
		> ${WRKDIR}/epiphany

pre-install:
	@-${X11BASE}/bin/gconftool-2 --shutdown

post-install:
		@${MV} -f ${PREFIX}/bin/epiphany ${PREFIX}/bin/epiphany-bin
		${INSTALL_SCRIPT} ${WRKDIR}/epiphany ${PREFIX}/bin

.include <bsd.port.post.mk>
