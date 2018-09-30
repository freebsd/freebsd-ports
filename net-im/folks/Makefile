# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	folks
PORTVERSION=	0.11.4
PORTREVISION=	1
CATEGORIES=	net-im
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	library to aggregates people from multiple sources

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	vapigen:lang/vala \
		${LOCALBASE}/bin/egrep:textproc/gnugrep
LIB_DEPENDS=	libgee-0.8.so:devel/libgee \
		libgcr-3.so:security/gcr \
		libzeitgeist-2.0.so:sysutils/zeitgeist \
		libtelepathy-glib.so:net-im/telepathy-glib \
		libnspr4.so:devel/nspr \
		libssl3.so:security/nss \
		libsecret-1.so:security/libsecret \
		libsoup-2.4.so:devel/libsoup \
		libdbus-glib-1.so:devel/dbus-glib \
		libdbus-1.so:devel/dbus

USE_LDCONFIG=	yes
USES=		gettext gmake libtool localbase pathfix pkgconfig \
		readline sqlite tar:xz
USE_GNOME=	evolutiondataserver3 intlhack introspection:build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-bluez-backend
CONFIGURE_ENV+=	ac_cv_path_EGREP=${LOCALBASE}/bin/egrep
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.freedesktop.folks.gschema.xml

PLIST_SUB=	LIBVER=25 VERSION=43 LIBVERLONG=25.18.4

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	SOCIALWEB TRACKER
OPTIONS_DEFAULT=SOCIALWEB TRACKER
SOCIALWEB_DESC=	Social web backend
TRACKER_DESC=	Tracker backend

SOCIALWEB_CONFIGURE_ENABLE=	libsocialweb-backend
SOCIALWEB_LIB_DEPENDS=	libsocialweb.so:www/libsocialweb

TRACKER_CONFIGURE_ENABLE=	tracker-backend
TRACKER_LIB_DEPENDS=	libtracker-control-2.0.so:sysutils/tracker

post-patch:
	@${REINPLACE_CMD} -e 's|--fatal-warnings||g' \
		${WRKSRC}/configure
	# Until after when the bundled gir is updated >= 0.11.4
	@${RM} ${WRKSRC}/backends/tracker/lib/FolksTracker-0.6.gir

.include <bsd.port.mk>
