# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	midori
PORTVERSION=	0.5.11
CATEGORIES=	www xfce
MASTER_SITES=	https://launchpadlibrarian.net/215909491/ \
		https://launchpad.net/${PORTNAME}/trunk/${PORTVERSION}/+download/
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Lightweight web browser using WebKit browser engine

LICENSE=	LGPL21 MIT
LICENSE_COMB=	multi

BUILD_DEPENDS=	rsvg-convert:graphics/librsvg2 \
		valac:lang/vala
LIB_DEPENDS=	libnotify.so:devel/libnotify \
		libsoup-gnome-2.4.so:devel/libsoup-gnome \
		libgcr-3.so:security/gcr
RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss

CFLAGS+=	-Wno-return-type
CMAKE_ARGS=	-DUSE_APIDOCS:BOOL=OFF \
		-DUSE_GRANITE:BOOL=OFF

USES=		cmake desktop-file-utils gettext localbase:ldflags pkgconfig \
		sqlite tar:bzip2
USE_GNOME=	glib20 intltool libxml2
USE_XORG=	xscrnsaver
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes

PLIST_SUB=	VERSION="${PORTVERSION:R}"

OPTIONS_DEFINE=	GIR GTK3 ZEITGEIST
OPTIONS_SUB=	yes
GIR_PREVENTS=	GTK3
GIR_USE=	gnome=introspection:build
GIR_CMAKE_ON=	-DUSE_GIR:BOOL=ON
GTK3_LIB_DEPENDS=	libwebkitgtk-3.0.so:www/webkit-gtk3
GTK3_USE=	gnome=gtk30
GTK3_CMAKE_ON=	-DUSE_GTK3:BOOL=ON \
	-DHALF_BRO_INCOM_WEBKIT2:BOOL=OFF
GTK3_LIB_DEPENDS_OFF=	libwebkitgtk-1.0.so:www/webkit-gtk2
GTK3_USE_OFF=	gnome=gtk20
GTK3_CMAKE_OFF=	-DUSE_GTK3:BOOL=OFF
ZEITGEIST_LIB_DEPENDS=	libzeitgeist-2.0.so:sysutils/zeitgeist
ZEITGEIST_CMAKE_OFF=	-DUSE_ZEITGEIST:BOOL=OFF
GIR_DESC=	Install GObject Introspection Reference manual
ZEITGEIST_DESC=	User logs activities

post-patch:
# Avoid errors with CMake
.for dir in config extensions
	@${RM} ${WRKSRC}/${dir}/*.orig
.endfor

.include <bsd.port.mk>
