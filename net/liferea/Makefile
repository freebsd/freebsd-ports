PORTNAME=	liferea
DISTVERSION=	2.0
CATEGORIES=	net gnome
MASTER_SITES=	https://github.com/lwindolf/liferea/releases/download/v${DISTVERSION}/

MAINTAINER=	cmt@FreeBSD.org
COMMENT=	Simple RSS/RDF feed reader
WWW=		https://lzone.de/liferea/

LICENSE=	GPLv2 LGPL3
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING
LICENSE_FILE_LGPL3=	${WRKSRC}/COPYING.LIB

BUILD_DEPENDS=	gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas
LIB_DEPENDS=	libfribidi.so:converters/fribidi \
		libharfbuzz.so:print/harfbuzz \
		libsoup-3.0.so:devel/libsoup3 \
		libwebkitgtk-6.0.so:www/webkit2-gtk@60 \
		libpeas-2.so:devel/libpeas \
		libjson-glib-1.0.so:devel/json-glib
RUN_DEPENDS=	gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas \
		${PYTHON_PKGNAMEPREFIX}libpeas>=0:devel/py-libpeas@${PY_FLAVOR}

USES=		compiler:c++11-lang cpe desktop-file-utils gettext \
		gmake gnome libtool localbase meson \
		pathfix pkgconfig python sqlite tar:xz
USE_GNOME=	cairo dconf:run glib20 gtk40 gdkpixbuf intltool introspection \
		libadwaita libxslt libxml2 pango

GLIB_SCHEMAS=	net.sf.liferea.gschema.xml

# Introspection starts the program, but it may hang or crash-abort
# without an X server because the Webkit compositor tries to initialize
# a graphics backend
MAKE_ENV+=	WEBKIT_DISABLE_COMPOSITING_MODE=1

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
