# New ports collection makefile for:	bmpx
# Date created:				2005-11-20
# Whom:					Roman Bogorodskiy <novel@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bmpx
PORTVERSION=	0.36.1
PORTREVISION=	5
CATEGORIES=	multimedia
MASTER_SITES=	http://files.beep-media-player.org/releases/0.36/

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Media player geared towards usability, technical efficiency and looks

LIB_DEPENDS=	tag.5:${PORTSDIR}/audio/taglib \
		cairomm-1.0.1:${PORTSDIR}/graphics/cairomm \
		musicbrainz.4:${PORTSDIR}/audio/libmusicbrainz \
		cdda_paranoia.0:${PORTSDIR}/audio/cdparanoia \
		neon.26:${PORTSDIR}/www/neon \
		glademm-2.4.1:${PORTSDIR}/devel/libglademm24 \
		gtkmm-2.4:${PORTSDIR}/x11-toolkits/gtkmm24 \
		rsvg-2:${PORTSDIR}/graphics/librsvg2 \
		boost_date_time.4:${PORTSDIR}/devel/boost \
		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib

CONFLICTS=	bmpx-devel-[0-9]*

USE_AUTOTOOLS=	autoconf:259
USE_BISON=	yes
USE_BZIP2=	yes
USE_FAM=	yes
USE_GCC=	3.4+
USE_GMAKE=	yes
USE_GNOME=	gtk20 libglade2 desktopfileutils
INSTALLS_ICONS=	yes
USE_GSTREAMER=	good mp3 ogg vorbis cdparanoia
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--disable-hal \
			--with-pkgconfig-dir=${PREFIX}/libdata/pkgconfig \
			--with-dbus-services-dir="${PREFIX}/share/dbus-1/services" \
			--with-libintl-prefix="${LOCALBASE}"
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib ${PTHREAD_LIBS}"
CONFIGURE_ARGS+=	--x-includes=${X11BASE}/include \
			--x-libraries=${X11BASE}/lib

MAN1=		beep-media-player-2.1

.if defined(WITHOUT_STARTUP_NOTIFICATION)
CONFIGURE_ARGS+=	--disable-sn
.else
LIB_DEPENDS+=	startup-notification-1.0:${PORTSDIR}/x11/startup-notification
.endif

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=		NLS="@comment "
.else
USE_GETTEXT=		yes
PLIST_SUB+=		NLS=""
.endif

.if defined(WITH_OFA)
CONFIGURE_ARGS+=	--enable-ofa
LIB_DEPENDS+=		ofa.0:${PORTSDIR}/audio/libofa
.endif

.if defined(WITH_SIDPLAY)
CONFIGURE_ARGS+=	--enable-sid
USE_GSTREAMER+=		sidplay
LIB_DEPENDS+=		sidplay.1:${PORTSDIR}/audio/libsidplay
PLIST_SUB+=		SID=""
.else
CONFIGURE_ARGS+=	--disable-sid
PLIST_SUB+=		SID="@comment "
.endif

.if defined(WITH_FAAD) || defined(WITH_MPEG4IP)
CONFIGURE_ARGS+=	--enable-mp4v2
LIB_DEPENDS+=		mp4v2.0:${PORTSDIR}/multimedia/mpeg4ip-libmp4v2
USE_GSTREAMER+=		faad
PLIST_SUB+=		MPEG4IP=""
.else
PLIST_SUB+=		MPEG4IP="@comment "
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 600000
BROKEN=		Does not compile on 5.x
.endif

.include <bsd.port.post.mk>
