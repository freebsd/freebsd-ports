# New ports collection makefile for:	tracker
# Date created:		2006-12-09
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/sysutils/tracker-client/Makefile,v 1.14 2010/05/10 04:21:19 marcus Exp $
#

PORTNAME=	tracker
PORTVERSION=	0.6.95
PORTREVISION=	8
CATEGORIES=	sysutils gnome
MASTER_SITES=	GNOME
PKGNAMESUFFIX?=	-client

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Object database, tag/metadata database, search tool and indexer

LIB_DEPENDS=	sqlite3.8:${PORTSDIR}/databases/sqlite3 \
		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
		poppler-glib.4:${PORTSDIR}/graphics/poppler-gtk \
		exif.12:${PORTSDIR}/graphics/libexif \
		wv-1.2.4:${PORTSDIR}/textproc/wv \
		gmime-2.0.4:${PORTSDIR}/mail/gmime2 \
		qdbm.14:${PORTSDIR}/databases/qdbm \
		exempi.3:${PORTSDIR}/textproc/exempi \
		hal.1:${PORTSDIR}/sysutils/hal \
		totem-plparser.17:${PORTSDIR}/multimedia/totem-pl-parser \
		raptor.3:${PORTSDIR}/textproc/raptor \
		ogg.7:${PORTSDIR}/audio/libogg \
		iptcdata.3:${PORTSDIR}/graphics/libiptcdata
RUN_DEPENDS=	xdg-desktop-icon:${PORTSDIR}/devel/xdg-utils \
		o3totxt:${PORTSDIR}/converters/o3read \
		pdftotext:${PORTSDIR}/graphics/poppler-utils \
		w3m:${PORTSDIR}/www/w3m

USE_BZIP2=	yes
USE_FAM=	yes
WANT_FAM_SYSTEM=gamin
INSTALLS_ICONS=	yes
USE_GNOME=	gnomehack gnomeprefix ltasneededhack intltool ltverhack
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
USE_GSTREAMER=	core
INSTALLS_ICONS=	yes
USE_AUTOTOOLS=	libtool:22
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${LOCALBASE}/lib/tracker ${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--enable-video-extractor=gstreamer \
		--enable-file-monitoring=fam \
		--with-session-bus-services-dir=${LOCALBASE}/share/dbus-1/services \
		--enable-external-qdbm --enable-libexif --enable-libvorbis \
		--enable-libiptcdata

.include <bsd.port.pre.mk>

.if defined(TRACKER_SLAVE)
LIB_DEPENDS+=	trackerclient:${PORTSDIR}/sysutils/tracker-client
. if ${TRACKER_SLAVE}=="gnome"
PKGNAMESUFFIX=	-gnome
LIB_DEPENDS+=	tracker-gtk:${PORTSDIR}/sysutils/tracker-libtrackergtk
BUILD_WRKSRC=	${WRKSRC}/src/tracker-applet
INSTALL_WRKSRC=	${WRKSRC}/src/tracker-applet
EXTRA_WRKSRC=	src/tracker-preferences src/tracker-search-tool
BUILD_DEPENDS+=	${LOCALBASE}/libexec/deskbar-applet/deskbar-applet:${PORTSDIR}/deskutils/deskbar-applet
RUN_DEPENDS+=	${LOCALBASE}/libexec/deskbar-applet/deskbar-applet:${PORTSDIR}/deskutils/deskbar-applet
USE_GNOME+=	gnomedesktop libgsf
MAN1+=		tracker-applet.1 tracker-search-tool.1 tracker-preferences.1
CONFIGURE_ARGS+=--enable-deskbar-applet \
		--with-deskbar-applet-handler-dir=${LOCALBASE}/libexec/deskbar-applet/handlers
. endif
. if defined(TRACKER_SLAVE) && ${TRACKER_SLAVE}=="libtrackergtk"
PKGNAMESUFFIX=	-libtrackergtk
USE_GNOME+=	libgsf
BUILD_WRKSRC=	${WRKSRC}/src/libtracker-gtk
INSTALL_WRKSRC=	${BUILD_WRKSRC}
. endif
.else
MAN1+=	tracker-extract.1 tracker-files.1 \
	tracker-info.1 \
	tracker-meta-folder.1 tracker-query.1 \
	tracker-search.1 tracker-services.1 tracker-stats.1 \
	tracker-status.1 tracker-tag.1 tracker-thumbnailer.1 tracker-unique.1 trackerd.1

MAN5+=	tracker.cfg.5
CONFIGURE_ARGS+=	--disable-libtrackergtk --disable-gui \
			--disable-trackerapplet --disable-gsf \
			--disable-preferences   --disable-deskbar-applet \
			--disable-tracker-applet --disable-tracker-preferences \
			--disable-libgsf
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|libpng|libpng14|' ${WRKSRC}/configure

post-build:
.if defined(TRACKER_SLAVE) && ${TRACKER_SLAVE}=="libtrackergtk"
	@(cd ${WRKSRC}/src/tracker-extract && ${MAKE} libextract-msoffice.la)
.elif defined(TRACKER_SLAVE) && ${TRACKER_SLAVE}=="gnome"
. for dir in ${EXTRA_WRKSRC}
	@(cd ${WRKSRC}/${dir}; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})
. endfor
.endif

post-install:
.if defined(TRACKER_SLAVE) && ${TRACKER_SLAVE}=="libtrackergtk"
	${MKDIR} ${PREFIX}/lib/tracker/extract-modules
	@(cd ${WRKSRC}/src/tracker-extract && for f in .a .la .so ; \
	do ${INSTALL_DATA} .libs/libextract-msoffice$${f} \
		${PREFIX}/lib/tracker/extract-modules ; done)
.elif defined(TRACKER_SLAVE) && ${TRACKER_SLAVE}=="gnome"
. for dir in ${EXTRA_WRKSRC}
	@(cd ${WRKSRC}/${dir} && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})
. endfor
. for man in ${MAN1}
	@(cd ${WRKSRC} && ${INSTALL_DATA} docs/manpages/${man} ${PREFIX}/man/man1/${man})
. endfor
.endif

.include <bsd.port.post.mk>
