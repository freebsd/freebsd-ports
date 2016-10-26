# $FreeBSD$

PORTNAME=	libgepub
PORTVERSION=	0.4
CATEGORIES=	textproc gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GObject based library for handling and rendering epub documents

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libwebkit2gtk-4.0.so:www/webkit2-gtk3 \
		libsoup-2.4.so:devel/libsoup

GNU_CONFIGURE=	yes
USES=		gettext-runtime gnome gmake libarchive libtool pathfix \
		pkgconfig tar:xz
USE_GNOME=	atk cairo glib20 gdkpixbuf2 gtk30 libxml2 pango
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
