# Ports collection Makefile for:	galeon2
# Date created:				16 November 2002
# Whom:					Maxime Romano <verbophobe@jewcrew.org>
#
# $FreeBSD$
#

PORTNAME=	galeon2
PORTVERSION=	1.3.12
PORTREVISION=	1
CATEGORIES=	www gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://osdn.dl.sourceforge.net/sourceforge/galeon/
MASTER_SITE_SUBDIR=	${PORTNAME:S/2$//}
DISTNAME=	${PORTNAME:S/2$//}-${PORTVERSION}

MAINTAINER=	gnome@freebsd.org
COMMENT=	A GNOME 2 Web browser based on gecko (the Mozilla rendering engine)

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
USE_GNOME=	gnomeprefix gnomehack libgnomeui
USE_LIBTOOL=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
CONFIGURE_ARGS=	--with-mozilla-includes="${X11BASE}/include/mozilla${HEADERS_SUFX}" \
		--with-mozilla-libs="${X11BASE}/lib/${MOZILLA}" \
		--enable-nautilus-view=no \
		${MOZ_CONFIGURE_ARGS}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include ${PTHREAD_CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

MAN1=		galeon.1

FLASHPLAYER=	${LOCALBASE}/lib/libflashplayer.so.1

CONFLICTS=	galeon-*

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
	@${ECHO_MSG} " By default the port uses www/mozilla-gtk2 for html rendering, but you can"
	@${ECHO_MSG} " change this by defining WITH_MOZILLA to one of the following values:"
	@${ECHO_MSG}
	@${ECHO_MSG} "  mozilla-devel-gtk2 "
	@${ECHO_MSG} ""

post-patch:
	@${REINPLACE_CMD} -e 's|mozilla-gtkmozembed|mozilla-gtkmozembed${HEADERS_SUFX}-gtk2|g' \
		${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name "Makefile.in*" | ${XARGS} ${REINPLACE_CMD} -e \
		 's|-lpthread|${PTHREAD_LIBS}|g'
	@${FIND} ${WRKSRC} -name "*.cpp" | ${XARGS} ${REINPLACE_CMD} -e \
		's|malloc\.h|stdlib.h|g'
	@${REINPLACE_CMD} -e 's|@prefix@/@DATADIRNAME@|@datadir@|g' \
		${WRKSRC}/ui/galeon-bookmarks-editor-ui.xml.in
	@${FIND} ${WRKSRC} -name "intltool-merge.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|mkdir $$lang or|mkdir $$lang, 0777 or| ; \
		 s|^push @INC, "/.*|push @INC, "${LOCALBASE}/share/intltool";|'

post-configure:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g ; \
		s|%%LOCALBASE%%|${LOCALBASE}|g ; \
		s|%%X11BASE%%|${X11BASE}|g ; \
		s|%%MOZILLA%%|${MOZILLA}|g ; \
		s|%%FLASHPLAYER%%|${FLASHPLAYER}|g' ${WRKSRC}/src/galeon

pre-install:
	@-${X11BASE}/bin/gconftool-2 --shutdown

.include <bsd.port.post.mk>
