# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/sysutils/tracker-client/Makefile,v 1.14 2010/05/10 04:21:19 marcus Exp $

PORTNAME=	tracker
PORTVERSION=	0.6.95
PORTREVISION=	23
CATEGORIES=	sysutils gnome
MASTER_SITES=	GNOME
PKGNAMESUFFIX?=	-client

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Object database, tag/metadata database, search tool and indexer

LIB_DEPENDS=	libsqlite3.so:${PORTSDIR}/databases/sqlite3 \
		libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libpoppler-glib.so:${PORTSDIR}/graphics/poppler-glib \
		libexif.so:${PORTSDIR}/graphics/libexif \
		libwv.so:${PORTSDIR}/textproc/wv \
		libgmime-2.0.so:${PORTSDIR}/mail/gmime2 \
		libqdbm.so:${PORTSDIR}/databases/qdbm \
		libexempi.so:${PORTSDIR}/textproc/exempi \
		libhal.so:${PORTSDIR}/sysutils/hal \
		libtotem-plparser.so:${PORTSDIR}/multimedia/totem-pl-parser \
		libraptor.so:${PORTSDIR}/textproc/raptor \
		libogg.so:${PORTSDIR}/audio/libogg \
		libiptcdata.so:${PORTSDIR}/graphics/libiptcdata
RUN_DEPENDS=	xdg-desktop-icon:${PORTSDIR}/devel/xdg-utils \
		o3totxt:${PORTSDIR}/converters/o3read \
		pdftotext:${PORTSDIR}/graphics/poppler-utils \
		w3m:${PORTSDIR}/www/w3m

INSTALLS_ICONS=	yes
USE_GNOME=	gnomeprefix intltool
USES=		fam:gamin gettext gmake libtool pathfix pkgconfig tar:bzip2
USE_LDCONFIG=	yes
USE_GSTREAMER=	core
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -L${LOCALBASE}/lib/tracker
INSTALL_TARGET=	install-strip
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_header_sys_inotify_h=no
CONFIGURE_ARGS=	--enable-video-extractor=gstreamer \
		--enable-file-monitoring=fam \
		--with-session-bus-services-dir=${LOCALBASE}/share/dbus-1/services \
		--enable-external-qdbm --enable-libexif --enable-libvorbis \
		--enable-libiptcdata

.include <bsd.port.pre.mk>

.if defined(TRACKER_SLAVE)
LIB_DEPENDS+=	libtrackerclient.so:${PORTSDIR}/sysutils/tracker-client
. if ${TRACKER_SLAVE}=="gnome"
PKGNAMESUFFIX=	-gnome
LIB_DEPENDS+=	libtracker-gtk.so:${PORTSDIR}/sysutils/tracker-libtrackergtk
BUILD_WRKSRC=	${WRKSRC}/src/tracker-applet
INSTALL_WRKSRC=	${WRKSRC}/src/tracker-applet
EXTRA_WRKSRC=	src/tracker-preferences src/tracker-search-tool
BUILD_DEPENDS+=	${LOCALBASE}/libexec/deskbar-applet/deskbar-applet:${PORTSDIR}/deskutils/deskbar-applet
RUN_DEPENDS+=	${LOCALBASE}/libexec/deskbar-applet/deskbar-applet:${PORTSDIR}/deskutils/deskbar-applet
USE_GNOME+=	gnomedesktop libgsf
MAN=		tracker-applet.1 tracker-search-tool.1 tracker-preferences.1
CONFIGURE_ARGS+=--enable-deskbar-applet \
		--with-deskbar-applet-handler-dir=${LOCALBASE}/libexec/deskbar-applet/handlers
LDFLAGS+=	-Wl,-rpath=${LOCALBASE}/lib/tracker
. endif
. if defined(TRACKER_SLAVE) && ${TRACKER_SLAVE}=="libtrackergtk"
PKGNAMESUFFIX=	-libtrackergtk
USE_GNOME+=	libgsf
BUILD_WRKSRC=	${WRKSRC}/src/libtracker-gtk
INSTALL_WRKSRC=	${BUILD_WRKSRC}
. endif
.else
CONFIGURE_ARGS+=	--disable-libtrackergtk --disable-gui \
			--disable-trackerapplet --disable-gsf \
			--disable-preferences   --disable-deskbar-applet \
			--disable-tracker-applet --disable-tracker-preferences \
			--disable-libgsf
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|libpng|libpng15|' ${WRKSRC}/configure

post-build:
.if defined(TRACKER_SLAVE) && ${TRACKER_SLAVE}=="libtrackergtk"
	@(cd ${WRKSRC}/src/tracker-extract && ${MAKE} libextract-msoffice.la)
.elif defined(TRACKER_SLAVE) && ${TRACKER_SLAVE}=="gnome"
. for dir in ${EXTRA_WRKSRC}
	@(cd ${WRKSRC}/${dir}; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})
. endfor
.endif

post-install:
.if defined(TRACKER_SLAVE) && ${TRACKER_SLAVE}=="libtrackergtk"
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/tracker/extract-modules
	${INSTALL_LIB} ${WRKSRC}/src/tracker-extract/.libs/libextract-msoffice.so \
		${STAGEDIR}${PREFIX}/lib/tracker/extract-modules
.elif defined(TRACKER_SLAVE) && ${TRACKER_SLAVE}=="gnome"
. for dir in ${EXTRA_WRKSRC}
	@(cd ${WRKSRC}/${dir} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})
. endfor
. for man in ${MAN}
	@(cd ${WRKSRC} && ${INSTALL_DATA} docs/manpages/${man} ${STAGEDIR}${MAN1PREFIX}/man/man1/${man})
. endfor
.endif

.include <bsd.port.post.mk>
