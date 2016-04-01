# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	sushi
PORTVERSION=	3.18.0
CATEGORIES=	x11-fm gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Tool similar to Gloobus Preview that provides quick file previews

LIB_DEPENDS=	libgcr-3.so:security/gcr \
		libgjs.so:lang/gjs \
		libclutter-gtk-1.0.so:graphics/clutter-gtk3 \
		libclutter-gst-2.0.so:multimedia/clutter-gst \
		libwebkit2gtk-4.0.so:www/webkit2-gtk3 \
		libmusicbrainz5.so:audio/libmusicbrainz5 \
		libevdocument3.so:graphics/evince
RUN_DEPENDS=	nautilus:x11-fm/nautilus

PORTSCOUT=	limitw:1,even

USES=		gettext gmake gnome libtool pathfix pkgconfig tar:xz
INSTALLS_ICONS=	yes
USE_GNOME=	gnomeprefix gtksourceview3 intlhack introspection:build
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
