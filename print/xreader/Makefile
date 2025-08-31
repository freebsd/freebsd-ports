PORTNAME=	xreader
PORTVERSION=	4.2.3
PORTREVISION=	4
CATEGORIES=	print gnome
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Multi-format document reader
WWW=		https://github.com/linuxmint/xreader

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

PORTSCOUT=	limit:^[0-9.]+$$	# ignore non-numeric tags

BUILD_DEPENDS=	intltool-merge:textproc/intltool \
		itstool:textproc/itstool
LIB_DEPENDS=	libxapp.so:x11/xapp

USES=		desktop-file-utils gettext-tools gnome meson pkgconfig xorg
USE_GITHUB=	yes
GH_ACCOUNT=	linuxmint
USE_LDCONFIG=	yes
USE_GNOME=	cairo gdkpixbuf gtk30 libxml2
USE_XORG=	ice sm x11
GLIB_SCHEMAS=	org.x.reader.gschema.xml

MATHJAX_DIR=	${LOCALBASE}/www/MathJax

OPTIONS_DEFINE=	DBUS DOCS HELP INTROSPECTION KEYRING T1LIB
OPTIONS_GROUP=		BACKENDS
OPTIONS_GROUP_BACKENDS=	COMICS DJVU DVI EPUB PDF PIXBUF PS TIFF XPS
OPTIONS_DEFAULT=	DBUS DJVU DOCS HELP KEYRING PDF TIFF XPS
OPTIONS_SUB=	yes

BACKENDS_DESC=	Document formats support
COMICS_DESC=	Comic book (cbr) support
DVI_DESC=	DVI format support
EPUB_DESC=	EPUB e-book format support
HELP_DESC=	Install help files
INTROSPECTION_DESC=	Enable GObject introspection
KEYRING_DESC=	Password-protected document support
PIXBUF_DESC=	Image files support via GdkPixbuf
T1LIB_DESC=	Type1 font support in DVI backend
XPS_DESC=	XPS document format support

COMICS_USES=		libarchive
COMICS_MESON_TRUE=	comics

DBUS_RUN_DEPENDS=	dbus-daemon:devel/dbus
DBUS_MESON_TRUE=	enable_dbus

DJVU_LIB_DEPENDS=	libdjvulibre.so:graphics/djvulibre
DJVU_MESON_TRUE=	djvu

DOCS_BUILD_DEPENDS=	gtkdocize:textproc/gtk-doc
DOCS_MESON_TRUE=	docs

DVI_LIB_DEPENDS=	libspectre.so:print/libspectre
DVI_USES=		tex
DVI_USE=		TEX=kpathsea
DVI_MESON_TRUE=		dvi

EPUB_BUILD_DEPENDS=	${MATHJAX_DIR}/MathJax.js:www/mathjax
EPUB_LIB_DEPENDS=	libwebkit2gtk-4.1.so:www/webkit2-gtk@41
EPUB_RUN_DEPENDS=	${EPUB_BUILD_DEPENDS}
EPUB_MESON_ON=		-Dmathjax-directory=${MATHJAX_DIR}
EPUB_MESON_OFF=		-Depub=false

HELP_RUN_DEPENDS=	yelp:x11/yelp
HELP_MESON_TRUE=	help_files

INTROSPECTION_USE=		GNOME=introspection:build
INTROSPECTION_MESON_TRUE=	introspection

KEYRING_LIB_DEPENDS=	libsecret-1.so:security/libsecret
KEYRING_MESON_TRUE=	keyring

PDF_LIB_DEPENDS=	libpoppler-glib.so:graphics/poppler-glib
PDF_MESON_TRUE=		pdf

PIXBUF_MESON_TRUE=	pixbuf

PS_LIB_DEPENDS=		libspectre.so:print/libspectre
PS_MESON_TRUE=		ps

T1LIB_LIB_DEPENDS=	libt1.so:devel/t1lib
T1LIB_MESON_TRUE=	t1lib
T1LIB_USES=		localbase:ldflags
T1LIB_IMPLIES=		DVI

TIFF_LIB_DEPENDS=	libtiff.so:graphics/tiff
TIFF_MESON_TRUE=	tiff

XPS_LIB_DEPENDS=	libgxps.so:graphics/libgxps
XPS_MESON_TRUE=		xps

.include <bsd.port.mk>
