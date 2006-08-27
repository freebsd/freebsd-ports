# New ports collection makefile for:	bmpx-devel
# Date created:				2006-08-12
# Whom:					Roman Bogorodskiy <novel@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bmpx
PORTVERSION=	0.21.0
CATEGORIES=	multimedia
MASTER_SITES=	http://files.beep-media-player.org/releases/${PORTVERSION:C/\.[0-9]*$//}/
PKGNAMESUFFIX=	-devel

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Media player geared towards usability, technical efficiency and looks

LIB_DEPENDS=	tag.5:${PORTSDIR}/audio/taglib \
		cairo.2:${PORTSDIR}/graphics/cairo \
		musicbrainz.4:${PORTSDIR}/audio/libmusicbrainz \
		neon.25:${PORTSDIR}/www/neon \
		glademm-2.4.1:${PORTSDIR}/devel/libglademm24 \
		gtkmm-2.4:${PORTSDIR}/x11-toolkits/gtkmm24 \
		cairomm-1.0.0:${PORTSDIR}/graphics/cairomm \
		boost_date_time.3:${PORTSDIR}/devel/boost \
		dbus-1.2:${PORTSDIR}/devel/dbus

CONFLICTS=	bmpx-[0-9]*

USE_BISON=	yes
USE_BZIP2=	yes
USE_FAM=	yes
USE_GCC=	3.4+
USE_GMAKE=	yes
USE_GNOME=	gtk20 libglade2 desktopfileutils
INSTALLS_ICONS=	yes
LIBTOOLFILES=	configure libhrel/configure \
		libchroma/configure libskinned/configure
USE_GSTREAMER=	good mad ogg
USE_X_PREFIX=	yes
USE_LDCONFIG=	yes
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

.if defined(WITH_SOULSEEK)
CONFIGURE_ARGS+=	--enable-moodriver
LIB_DEPENDS+=	moodriver.0:${PORTSDIR}/net-p2p/moodriver
RUN_DEPENDS+=	mooseekd:${PORTSDIR}/net-p2p/mooseekd
.endif

pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "Note: it is a development version of bmpx. It is fully"
	@${ECHO_MSG} "workable, though it may be not as stable as a version"
	@${ECHO_MSG} "provided by multimedia/bmpx port. And it requires you to"
	@${ECHO_MSG} "to delete the existing library. So if you want stability"
	@${ECHO_MSG} "please use multimedia/bmpx port instead."
	@${ECHO_MSG}

.include <bsd.port.mk>
