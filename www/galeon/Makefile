# Ports collection Makefile for:	galeon
# Date created:				1 August 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	galeon
PORTVERSION=	1.3.20
CATEGORIES=	www gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://osdn.dl.sourceforge.net/sourceforge/galeon/
MASTER_SITE_SUBDIR=	${PORTNAME:S/2$//}

MAINTAINER=	gnome@freebsd.org
COMMENT=	A GNOME 2 Web browser based on gecko (the Mozilla rendering engine)

BUILD_DEPENDS=	${X11BASE}/lib/${MOZILLA}/components/libwidget_gtk2.so:${PORTSDIR}/www/${MOZILLA}
RUN_DEPENDS=	${X11BASE}/lib/${MOZILLA}/components/libwidget_gtk2.so:${PORTSDIR}/www/${MOZILLA}

MOZILLA=	mozilla
HEADERS_SUFX=
MOZ_BUILD=	mozilla

.if !defined(WITH_MOZILLA)
MOZILLA=	mozilla
HEADERS_SUFX=
.else
.if ${WITH_MOZILLA}=="firefox"
MOZILLA=	firefox
MOZ_BUILD=	firefox
.else
.if ${WITH_MOZILLA}=="mozilla-devel" || ${WITH_MOZILLA}=="mozilla-devel-gtk2"
MOZILLA=	mozilla-devel
HEADERS_SUFX=	-devel
.else
MOZILLA=	mozilla
HEADERS_SUFX=
.endif
.endif
.endif

WRKSRC=		${WRKDIR}/${PORTNAME:S/2$//}-${PORTVERSION:S/a$//}
USE_BZIP2=	yes
USE_X_PREFIX=	yes
INSTALLS_OMF=	yes
USE_GNOME=	gnomeprefix intlhack gnomehack libgnomeui desktopfileutils
USE_LIBTOOL_VER=15
USE_GMAKE=	yes
USE_REINPLACE=	yes
CONFIGURE_ARGS=	--enable-nautilus-view=no \
		--with-mozilla=${MOZ_BUILD}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include ${PTHREAD_CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

MAN1=		galeon.1
GCONF_SCHEMAS=	galeon.schemas

FLASHPLAYER=	${LOCALBASE}/lib/libflashplayer.so.1

CONFLICTS=	galeon-[0-9]*

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

.if ${OSVERSION} < 500000
.if ${MOZILLA}=="mozilla-devel"
USE_GCC=	3.4
.endif
.endif

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} " By default the port uses www/mozilla for html rendering, but you can"
	@${ECHO_MSG} " change this by defining WITH_MOZILLA to one of the following values:"
	@${ECHO_MSG}
	@${ECHO_MSG} "  firefox       "
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
	@${REINPLACE_CMD} -e 's|@prefix@/@DATADIRNAME@|@datadir@|g' \
		${WRKSRC}/ui/galeon-bookmarks-editor-ui.xml.in

post-configure:
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|g ; \
		s|%%LOCALBASE%%|${LOCALBASE}|g ; \
		s|%%X11BASE%%|${X11BASE}|g ; \
		s|%%MOZILLA%%|${MOZILLA}|g ; \
		s|%%FLASHPLAYER%%|${FLASHPLAYER}|g' < ${FILESDIR}/galeon \
		> ${WRKDIR}/galeon

post-install:
	@${MV} -f ${PREFIX}/bin/galeon ${PREFIX}/bin/galeon-bin
	${INSTALL_SCRIPT} ${WRKDIR}/galeon ${PREFIX}/bin

.include <bsd.port.post.mk>
