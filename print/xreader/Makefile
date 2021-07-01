# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>

PORTNAME=	xreader
PORTVERSION=	3.0.2
CATEGORIES=	print gnome
DIST_SUBDIR=	gnome

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Multi-format document reader

LICENSE=	GPLv2+

PORTSCOUT=	limit:^[0-9.]+$$	# ignore master.mint* tags

BUILD_DEPENDS=	intltool-merge:textproc/intltool \
		itstool:textproc/itstool
LIB_DEPENDS=	libxapp.so:x11/xapp

USES=		desktop-file-utils gettext-tools gnome meson pkgconfig xorg
USE_GITHUB=	yes
GH_ACCOUNT=	linuxmint
USE_LDCONFIG=	yes
USE_GNOME=	cairo gdkpixbuf2 gtk30 libxml2
USE_XORG=	ice sm x11
GLIB_SCHEMAS=	org.x.reader.gschema.xml
INSTALLS_ICONS=	yes

MATHJAX_DIR=	${LOCALBASE}/www/MathJax
MESON_ARGS=	-Dtests=false

OPTIONS_DEFINE=	DBUS DJVU DVI EPUB HELP KEYRING PDF PS T1LIB TIFF XPS
OPTIONS_DEFAULT=	DBUS DJVU HELP KEYRING PDF TIFF XPS
OPTIONS_SUB=	yes

DVI_DESC=	DVI format support
EPUB_DESC=	EPUB e-book format support
HELP_DESC=	Install help files
KEYRING_DESC=	Password-protected document support
T1LIB_DESC=	Type1 font support in DVI backend
XPS_DESC=	XPS document support

DBUS_LIB_DEPENDS=	libdbus-1.so:devel/dbus
DBUS_MESON_OFF=		-Denable_dbus=false

DJVU_LIB_DEPENDS=	libdjvulibre.so:graphics/djvulibre
DJVU_MESON_ON=		-Ddjvu=true

DVI_LIB_DEPENDS=	libspectre.so:print/libspectre
DVI_USE=		tex=kpathsea
DVI_MESON_ON=		-Ddvi=true

EPUB_BUILD_DEPENDS=	${MATHJAX_DIR}/MathJax.js:www/mathjax
EPUB_LIB_DEPENDS=	libwebkit2gtk-4.0.so:www/webkit2-gtk3
EPUB_RUN_DEPENDS=	${EPUB_BUILD_DEPENDS}
EPUB_MESON_ON=		-Dmathjax-directory=${MATHJAX_DIR}
EPUB_MESON_OFF=		-Depub=false

HELP_RUN_DEPENDS=	yelp:x11/yelp
HELP_MESON_ON=		-Dhelp_files=true

KEYRING_LIB_DEPENDS=	libsecret-1.so:security/libsecret
KEYRING_MESON_OFF=	-Dkeyring=false

PDF_LIB_DEPENDS=	libpoppler-glib.so:graphics/poppler-glib
PDF_MESON_OFF=		-Dpdf=false

PS_LIB_DEPENDS=		libspectre.so:print/libspectre
PS_MESON_OFF=		-Dps=false

T1LIB_LIB_DEPENDS=	libt1.so:devel/t1lib
T1LIB_MESON_ON=		-Dt1lib=true
T1LIB_IMPLIES=		DVI

TIFF_LIB_DEPENDS=	libtiff.so:graphics/tiff
TIFF_MESON_OFF=		-Dtiff=false

XPS_LIB_DEPENDS=	libgxps.so:graphics/libgxps
XPS_MESON_OFF=		-Dxps=false

post-patch:
	@${REINPLACE_CMD} -e '/gdk\/gdkwayland\.h/d' \
		${WRKSRC}/libdocument/ev-document-misc.h

.include <bsd.port.mk>
