# New ports collection makefile for:    evidence
# Date created:                31 Juli 2005
# Whom:                    Anders Troback
#
# $FreeBSD$
#

PORTNAME=	evidence
PORTVERSION=	0.9.8
PORTREVISION=	3
CATEGORIES=	x11-fm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	freebsd@troback.com
COMMENT=	Enlightened file-manager

BUILD_DEPENDS=	pngtopnm:${PORTSDIR}/graphics/netpbm
LIB_DEPENDS=	Imlib2.3:${PORTSDIR}/graphics/imlib2 \
		evas.1:${PORTSDIR}/graphics/evas \
		edje.5:${PORTSDIR}/graphics/edje \
		ecore.1:${PORTSDIR}/x11/ecore \
		embryo.9:${PORTSDIR}/lang/embryo \
		eet.9:${PORTSDIR}/devel/eet \
		pcre.0:${PORTSDIR}/devel/pcre

USE_FAM=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gtk20
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-dbus \
		--disable-dcop \
		--enable-ecore-ipc \
		--enable-canvas-evas2 \
		--disable-canvas-gnomecanvas \
		--disable-backend-gnomevfs2 \
		--disable-backend-kio \
		--disable-attrs \
		--disable-acls \
		--enable-magic \
		--disable-sharedmime \
		--disable-thumbnailer-avi \
		--disable-thumbnailer-mpeg3 \
		--enable-plugin-ttf
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

EXTRACT_AFTER_ARGS=	| ${TAR} -xf - --exclude */CVS/*

MAN1=	evidence.1
INFO=	evidence

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=--enable-debug
.else
CONFIGURE_ARGS+=--disable-debug
.endif

# WARNING: Encore main-loop is slow comparing to glib main-loop, it is one
#	   of reason to use glib by default. Even though it's default in
#	   the configure.
.if defined(WITH_ECORE_MAINLOOP)
CONFIGURE_ARGS+=--enable-ecore
.else
CONFIGURE_ARGS+=--disable-ecore
.endif

.if defined(WITHOUT_EXTRACTOR)
CONFIGURE_ARGS+=--disable-plugin-extractor
PLIST_SUB+=	EXTRACTOR:="@comment "
.else
LIB_DEPENDS+=	extractor.2:${PORTSDIR}/textproc/libextractor
CONFIGURE_ARGS+=--enable-plugin-extractor
PLIST_SUB+=	EXTRACTOR:=""
.endif

.if defined(WITHOUT_ID3)
CONFIGURE_ARGS+=--disable-plugin-id3
PLIST_SUB+=	ID3:="@comment "
.else
LIB_DEPENDS+=	id3-3.8.3:${PORTSDIR}/audio/id3lib
CONFIGURE_ARGS+=--enable-plugin-id3
PLIST_SUB+=	ID3:=""
.endif

.if defined(WITHOUT_VORBIS)
CONFIGURE_ARGS+=--disable-plugin-vorbis
PLIST_SUB+=	VORBIS:="@comment "
.else
LIB_DEPENDS+=	vorbis.3:${PORTSDIR}/audio/libvorbis
CONFIGURE_ARGS+=--enable-plugin-vorbis
PLIST_SUB+=	VORBIS:=""
.endif

.if defined(WITHOUT_XINE)
CONFIGURE_ARGS+=--disable-thumbnailer-xine
PLIST_SUB+=	XINE:="@comment "
.else
LIB_DEPENDS+=	xine.15:${PORTSDIR}/multimedia/libxine
CONFIGURE_ARGS+=--enable-thumbnailer-xine
PLIST_SUB+=	XINE:=""
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=	"Broken dependencies."
.endif

pre-everything::
	@${ECHO_MSG} "*****************************************************************************"
.if !defined(WITH_DEBUG) || !defined(WITH_ECORE_MAINLOOP) || !defined(WITHOUT_EXTRACTOR) || !defined(WITHOUT_ID3) || !defined(WITHOUT_VORBIS) || !defined(WITHOUT_XINE)
	@${ECHO_MSG} "You may specify the following on the command line:"
	@${ECHO_MSG} " "
.endif
.if !defined(WITH_DEBUG)
	@${ECHO_MSG} "WITH_DEBUG=yes, enable debugging."
.endif
.if !defined(WITH_ECORE_MAINLOOP)
	@${ECHO_MSG} "WITH_ECORE_MAINLOOP=yes, use eCore as main-loop, GLib is default and faster."
.endif
.if !defined(WITHOUT_EXTRACTOR)
	@${ECHO_MSG} "WITHOUT_EXTRACTOR=yes, disable the file keywords plugin."
.endif
.if !defined(WITHOUT_ID3)
	@${ECHO_MSG} "WITHOUT_ID3=yes, disable the file info plugin for mp3 files."
.endif
.if !defined(WITHOUT_VORBIS)
	@${ECHO_MSG} "WITHOUT_VORBIS=yes, disable the file info plugin for vorbis (ogg) files."
.endif
.if !defined(WITHOUT_XINE)
	@${ECHO_MSG} "WITHOUT_XINE=yes, disable the thumbnailer for video files."
.endif
	@${ECHO_MSG} "*****************************************************************************"

post-patch:
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -e \
		's|LDFLAGS = |LDFLAGS = @LDFLAGS@ |g'
	@${REINPLACE_CMD} -e 's|-lmagic|-lmagic -lz|g ; s|"loop"|"$$loop"|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|@ecore_cflags@|$$(ECORE_CFLAGS)|g ; \
		s|@ecore_libs@|$$(ECORE_LIBS)|g' ${WRKSRC}/src/Makefile.in

.include <bsd.port.post.mk>
