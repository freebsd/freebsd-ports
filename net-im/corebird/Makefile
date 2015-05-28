# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	corebird
PORTVERSION=	1.0
CATEGORIES=	net-im

MAINTAINER=	cpm@fbsd.es
COMMENT=	GTK3 Twitter client written in Vala

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	valac:${PORTSDIR}/lang/vala
LIB_DEPENDS=	libsoup-2.4.so:${PORTSDIR}/devel/libsoup \
		libnotify.so:${PORTSDIR}/devel/libnotify \
		libjson-glib-1.0.so:${PORTSDIR}/devel/json-glib \
		librest-0.7.so:${PORTSDIR}/devel/librest \
		libgee-0.8.so:${PORTSDIR}/devel/libgee

GH_ACCOUNT=	baedert

USE_GITHUB=	yes
USES=		autoreconf gettext gmake libtool pkgconfig
GNU_CONFIGURE=	yes
USE_GNOME=	atk cairo gdkpixbuf2 glib20 gtk30 intltool libxml2 pango
USE_SQLITE=	yes
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	GSTREAMER
OPTIONS_DEFAULT=	GSTREAMER
GSTREAMER_DESC=	Gstreamer support

GLIB_SCHEMAS=	org.baedert.corebird.gschema.xml

.include <bsd.port.options.mk>

post-extract:
	cd ${WRKSRC}/data && ${MV} org.baedert.corebird.desktop.in.in \
		corebird.desktop.in.in

.if ${PORT_OPTIONS:MGSTREAMER}
USE_GSTREAMER1=	yes bad good libav x ximagesrc
.else
CONFIGURE_ARGS+=	--disable-video
.endif

pre-configure:
	${MKDIR} ${WRKSRC}/m4

# Replace locales files in right place
post-configure:
	${REINPLACE_CMD} -e 's|[$$][(]DATADIRNAME[)]|share|' \
		${WRKSRC}/po/Makefile

.include <bsd.port.mk>
