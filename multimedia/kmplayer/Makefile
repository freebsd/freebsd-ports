# New ports collection makefile for:	KMplayer
# Date created:				Jan 31, 2003
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	kmplayer
PORTVERSION=	0.10.0c
PORTREVISION=	3
PORTEPOCH=	2
CATEGORIES=	multimedia audio kde
MASTER_SITES=	http://freebsd.ricin.com/ports/distfiles/ \
		http://kmplayer.kde.org/pkgs/
DISTNAME=	${PORTNAME}-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	danny@ricin.com
COMMENT=	KDE frontend to MPlayer, Xine, GStreamer

# It seems neither cairo nor npplayer can be disabled if the deps are present
# So deps must be added here for package consistency/POLA
PLIST_FILES+=	bin/knpplayer
LIB_DEPENDS=	cairo:${PORTSDIR}/graphics/cairo \
		dbus-glib-1:${PORTSDIR}/devel/dbus-glib \
		dbus-qt-1:${PORTSDIR}/devel/dbus-qt3 \
		expat:${PORTSDIR}/textproc/expat2
RUN_DEPENDS=	mplayer:${PORTSDIR}/multimedia/mplayer

USE_BZIP2=	yes
USE_KDEBASE_VER=3
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22
USE_LDCONFIG=	yes
USE_GNOME=	atk glib20 gtk20 libxml2 pango # See above
WANT_GSTREAMER=	yes # Can't be set after bsd.port.pre.mk
USE_XORG=	xv

OPTIONS=	ARTS	  "ARts audio system support" on \
		GSTREAMER "GStreamer playback support" off \
		TUBESTUFF "YouTube and other 'download & play' support" off \
		XINE	  "Xine playback support" off

CONFIGURE_ENV+=	PKG_CONFIG=${LOCALBASE}/bin/pkg-config

post-patch:
# do not try to roll our own mimetypes
	${REINPLACE_CMD} -E -e 's|^(SUBDIRS.*)mimetypes|\1|'\
		${WRKSRC}/Makefile.in

.include <bsd.port.pre.mk>

.if defined(WITHOUT_ARTS)
CONFIGURE_ARGS+=--without-arts
.endif # WITHOUT_ARTS

.if defined(WITH_GSTREAMER)
USE_GSTREAMER+=	yes
PLIST_FILES+=	bin/kgstplayer
.else
CONFIGURE_ARGS+=--without-gstreamer
.endif # WITH_GSTREAMER

.if defined(WITH_XINE)
LIB_DEPENDS+=	xine:${PORTSDIR}/multimedia/libxine
PLIST_FILES+=	bin/kxineplayer
.else
CONFIGURE_ARGS+=--without-xine
.endif # WITH_XINE

.if defined(WITH_TUBESTUFF)
TUBESTUFF_VER=	20080314
DISTFILES+=	tubestuff-${TUBESTUFF_VER}.tbz
BUILD_DEPENDS+=	mencoder:${PORTSDIR}/multimedia/mencoder
USE_PYTHON=	yes

pre-patch:
	${REINPLACE_CMD} -e 's|PREFIX=/usr/local|PREFIX=${PREFIX}|'\
		${WRKDIR}/tubestuff/tubestuff-patch-kmplayerpartbase.cpp.in &&\
		cd ${WRKDIR}/tubestuff && ./make_patch

do-patch:
	cd ${WRKSRC} && ${PATCH} <\
		${WRKDIR}/tubestuff/patch-kmplayerpartbase.cpp-tubestuff

pre-install:
	cd ${WRKDIR}/tubestuff && ./make_video && ./make_readme
	${REINPLACE_CMD} -e 's|PREFIX=/usr/local|PREFIX=${PREFIX}|'\
		${WRKDIR}/tubestuff/make_install

post-install:
	cd ${WRKDIR}/tubestuff && ./make_install

.if defined(NOPORTDOCS)
	${RM} ${PREFIX}/share/apps/kmplayer/tubestuff/README
.else
PLIST_FILES+=	share/apps/kmplayer/tubestuff/README
.endif # NOPORTDOCS

PLIST_FILES+=	share/apps/kmplayer/tubestuff/altertube-dl \
		share/apps/kmplayer/tubestuff/blip-dl \
		share/apps/kmplayer/tubestuff/dailymotion-dl \
		share/apps/kmplayer/tubestuff/downloading.avi \
		share/apps/kmplayer/tubestuff/google-dl \
		share/apps/kmplayer/tubestuff/liveleak-dl \
		share/apps/kmplayer/tubestuff/metacafe-dl \
		share/apps/kmplayer/tubestuff/ourmedia-dl \
		share/apps/kmplayer/tubestuff/playtube \
		share/apps/kmplayer/tubestuff/pornotube-dl \
		share/apps/kmplayer/tubestuff/revver-dl \
		share/apps/kmplayer/tubestuff/youtube-dl \
		"@dirrm share/apps/kmplayer/tubestuff"
.endif # WITH_TUBESTUFF

.include <bsd.port.post.mk>
