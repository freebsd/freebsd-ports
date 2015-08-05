# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	sushi
PORTVERSION=	3.16.0
PORTREVISION=	1
CATEGORIES=	x11-fm gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Tool similar to Gloobus Preview that provides quick file previews

LIB_DEPENDS=	libgcr-3.so:${PORTSDIR}/security/gcr \
		libgjs.so:${PORTSDIR}/lang/gjs \
		libclutter-gtk-1.0.so:${PORTSDIR}/graphics/clutter-gtk3 \
		libclutter-gst-2.0.so:${PORTSDIR}/multimedia/clutter-gst \
		libwebkit2gtk-4.0.so:${PORTSDIR}/www/webkit2-gtk3 \
		libmusicbrainz5.so:${PORTSDIR}/audio/libmusicbrainz5 \
		libevdocument3.so:${PORTSDIR}/graphics/evince
RUN_DEPENDS=	nautilus:${PORTSDIR}/x11-fm/nautilus

USES=		gettext gmake libtool pathfix pkgconfig tar:xz
INSTALLS_ICONS=	yes
USE_GNOME=	gnomeprefix gtksourceview3 intlhack introspection:build
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.gnome.sushi.gschema.xml

.include <bsd.port.mk>
