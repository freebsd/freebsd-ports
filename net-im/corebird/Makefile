# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	corebird
PORTVERSION=	1.2.2
CATEGORIES=	net-im

MAINTAINER=	cpm@FreeBSD.org
COMMENT=	GTK3 Twitter client written in Vala

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	valac:lang/vala
LIB_DEPENDS=	libsoup-2.4.so:devel/libsoup \
		libnotify.so:devel/libnotify \
		libjson-glib-1.0.so:devel/json-glib \
		librest-0.7.so:devel/librest \
		libgee-0.8.so:devel/libgee

USE_GITHUB=	yes
GH_ACCOUNT=	baedert

USES=		autoreconf gettext gmake libtool pkgconfig sqlite
GNU_CONFIGURE=	yes
USE_GNOME=	atk cairo gdkpixbuf2 glib20 gtk30 intltool libxml2 pango
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=		GSTREAMER
OPTIONS_DEFAULT=	GSTREAMER
GSTREAMER_USE=	gstreamer1=yes,bad,good,gtksink,libav,x,ximagesrc
GSTREAMER_CONFIGURE_OFF=	--disable-video

GLIB_SCHEMAS=	org.baedert.corebird.gschema.xml

post-extract:
	cd ${WRKSRC}/data && ${MV} org.baedert.corebird.desktop.in.in \
		corebird.desktop.in.in

pre-configure:
	${MKDIR} ${WRKSRC}/m4

# Replace locales files in right place
post-configure:
	${REINPLACE_CMD} -e 's|[$$][(]DATADIRNAME[)]|share|' \
		${WRKSRC}/po/Makefile

.include <bsd.port.mk>
