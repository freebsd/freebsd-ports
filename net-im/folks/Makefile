# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	folks
PORTVERSION=	0.11.1
PORTREVISION=	1
CATEGORIES=	net-im
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	library to aggregates people from multiple sources

BUILD_DEPENDS=	vapigen:lang/vala \
		${LOCALBASE}/bin/egrep:textproc/gnugrep
LIB_DEPENDS=	libgee-0.8.so:devel/libgee \
		libgcr-3.so:security/gcr \
		libzeitgeist-2.0.so:sysutils/zeitgeist \
		libtelepathy-glib.so:net-im/telepathy-glib

CONFLICTS=	folks-0.4.[0-9]*

USE_LDCONFIG=	yes
USES=		gettext gmake libtool localbase pathfix pkgconfig tar:xz
USE_GNOME=	evolutiondataserver3 intlhack introspection:build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-bluez-backend
CONFIGURE_ENV+=	ac_cv_path_EGREP=${LOCALBASE}/bin/egrep
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.freedesktop.folks.gschema.xml

PLIST_SUB=	LIBVER=25 VERSION=43 LIBVERLONG=25.18.1

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	SOCIALWEB TRACKER
OPTIONS_DEFAULT=SOCIALWEB TRACKER
SOCIALWEB_DESC=	Social web backend
TRACKER_DESC=	Tracker backend
SOCIALWEB_CONFIGURE_ENABLE=	libsocialweb-backend
SOCIALWEB_LIB_DEPENDS=	libsocialweb.so:www/libsocialweb
TRACKER_CONFIGURE_ENABLE=	tracker-backend
TRACKER_LIB_DEPENDS=	libtracker-control-1.0.so:sysutils/tracker

post-patch:
	@${REINPLACE_CMD} -e 's|--fatal-warnings||g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
