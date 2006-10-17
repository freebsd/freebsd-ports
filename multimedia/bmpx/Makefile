# New ports collection makefile for:	bmpx
# Date created:				2005-11-20
# Whom:					Roman Bogorodskiy <novel@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bmpx
PORTVERSION=	0.32.0
PORTREVISION=	4
CATEGORIES=	multimedia
MASTER_SITES=	http://files.beep-media-player.org/releases/0.30/

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Media player geared towards usability, technical efficiency and looks

LIB_DEPENDS=	tag.5:${PORTSDIR}/audio/taglib \
		cairomm-1.0.1:${PORTSDIR}/graphics/cairomm \
		musicbrainz.4:${PORTSDIR}/audio/libmusicbrainz \
		neon.25:${PORTSDIR}/www/neon \
		glademm-2.4.1:${PORTSDIR}/devel/libglademm24 \
		gtkmm-2.4:${PORTSDIR}/x11-toolkits/gtkmm24 \
		boost_date_time.3:${PORTSDIR}/devel/boost \
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
USE_GSTREAMER=	good mad ogg vorbis
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-pkgconfig-dir=${PREFIX}/libdata/pkgconfig \
			--with-dbus-services-dir="${PREFIX}/share/dbus-1/services" \
			--with-libintl-prefix="${LOCALBASE}"
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

.include <bsd.port.mk>
