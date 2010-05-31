# New ports collection makefile for:	bmpx
# Date created:				2005-11-20
# Whom:					Roman Bogorodskiy <novel@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bmpx
PORTVERSION=	0.40.14
PORTREVISION=	8
CATEGORIES=	multimedia
MASTER_SITES=	http://files.backtrace.info/releases/0.40/

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Media player geared towards usability, technical efficiency and looks

LIB_DEPENDS=	tag.1:${PORTSDIR}/audio/taglib \
		cairomm-1.0.1:${PORTSDIR}/graphics/cairomm \
		musicbrainz.4:${PORTSDIR}/audio/libmusicbrainz \
		cdio.12:${PORTSDIR}/sysutils/libcdio \
		glademm-2.4.1:${PORTSDIR}/devel/libglademm24 \
		gtkmm-2.4:${PORTSDIR}/x11-toolkits/gtkmm24 \
		rsvg-2:${PORTSDIR}/graphics/librsvg2 \
		boost_date_time.4:${PORTSDIR}/devel/boost-libs \
		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
		sexymm.2:${PORTSDIR}/x11-toolkits/libsexymm \
		ofa.0:${PORTSDIR}/audio/libofa \
		soup-2.2.8:${PORTSDIR}/devel/libsoup22

CONFLICTS=	bmpx-devel-[0-9]*

USE_BISON=	build
USE_XORG=	ice sm
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20 libglade2 desktopfileutils
INSTALLS_ICONS=	yes
USE_GSTREAMER=	good mp3 ogg vorbis cdparanoia
USE_LDCONFIG=	yes
USE_SQLITE=	3
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-pkgconfig-dir=${PREFIX}/libdata/pkgconfig \
			--with-dbus-services-dir="${PREFIX}/share/dbus-1/services" \
			--with-libintl-prefix="${LOCALBASE}" \
			--disable-doc
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib ${PTHREAD_LIBS}"

MAN1=		beep-media-player-2.1

.if !defined(WITHOUT_HAL)
LIB_DEPENDS+=	hal.1:${PORTSDIR}/sysutils/hal
.else
CONFIGURE_ARGS+=	--disable-hal
.endif

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
USE_GSTREAMER+=		faad
PLIST_SUB+=		MPEG4IP=""
.else
PLIST_SUB+=		MPEG4IP="@comment "
.endif

.include <bsd.port.mk>
