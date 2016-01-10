# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	corebird
PORTVERSION=	1.1
CATEGORIES=	net-im

MAINTAINER=	cpm@fbsd.es
COMMENT=	GTK3 Twitter client written in Vala

LICENSE=	GPLv3

BUILD_DEPENDS=	valac:${PORTSDIR}/lang/vala
LIB_DEPENDS=	libsoup-2.4.so:${PORTSDIR}/devel/libsoup \
		libnotify.so:${PORTSDIR}/devel/libnotify \
		libjson-glib-1.0.so:${PORTSDIR}/devel/json-glib \
		librest-0.7.so:${PORTSDIR}/devel/librest \
		libgee-0.8.so:${PORTSDIR}/devel/libgee

USE_GITHUB=	yes
GH_ACCOUNT=	baedert

USES=		autoreconf gettext gmake libtool pkgconfig sqlite
GNU_CONFIGURE=	yes
USE_GNOME=	atk cairo gdkpixbuf2 glib20 gtk30 intltool libxml2 pango
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=		GSTREAMER
OPTIONS_DEFAULT=	GSTREAMER
GSTREAMER_USE=	gstreamer1=yes,bad,good,libav,x,ximagesrc
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
