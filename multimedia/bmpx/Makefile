# New ports collection makefile for:	bmpx
# Date created:				2005-11-20
# Whom:					Roman Bogorodskiy <novel@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bmpx
PORTVERSION=	0.20.3
CATEGORIES=	multimedia
MASTER_SITES=	http://files.beep-media-player.org/releases/${PORTVERSION:C/\.[0-9]*$//}/

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Media player geared towards usability, technical efficiency and looks

LIB_DEPENDS=	tag.5:${PORTSDIR}/audio/taglib \
		cairo.2:${PORTSDIR}/graphics/cairo \
		musicbrainz.4:${PORTSDIR}/audio/libmusicbrainz \
		neon.25:${PORTSDIR}/www/neon \
		glademm-2.4.1:${PORTSDIR}/devel/libglademm24 \
		gtkmm-2.4:${PORTSDIR}/x11-toolkits/gtkmm24 \
		boost_date_time.3:${PORTSDIR}/devel/boost \
		dbus-1.2:${PORTSDIR}/devel/dbus

USE_BISON=	yes
USE_BZIP2=	yes
USE_FAM=	yes
USE_GCC=	3.4+
USE_GMAKE=	yes
USE_GNOME=	gtk20 libglade2 desktopfileutils
LIBTOOLFILES=	configure libhrel/configure \
		libchroma/configure libskinned/configure
USE_GSTREAMER=	good mad ogg
USE_X_PREFIX=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-pkgconfig-dir=${PREFIX}/libdata/pkgconfig \
			--with-dbus-services-dir="${PREFIX}/share/dbus-1/services"
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib ${PTHREAD_LIBS}"

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

.if !defined(WITHOUT_LIBNOTIFY)
CONFIGURE_ARGS+=	--enable-libnotify
LIB_DEPENDS+=	notify.2:${PORTSDIR}/devel/libnotify
RUN_DEPENDS+=	${X11BASE}/libexec/notification-daemon:${PORTSDIR}/deskutils/notification-daemon
.else
CONFIGURE_ARGS+=	--disable-libnotify
.endif

.include <bsd.port.mk>
