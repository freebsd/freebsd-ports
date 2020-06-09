# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xreader
PORTVERSION=	2.6.2
CATEGORIES=	print

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Generic document reader

LICENSE=	GPLv2+

PORTSCOUT=	limit:^[0-9.]+$$	# ignore master.mint* tags

BUILD_DEPENDS=	intltool-merge:textproc/intltool
LIB_DEPENDS=	libxapp.so:x11/xapps

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

OPTIONS_DEFINE=	DJVU EPUB KEYRING PDF PS TIFF XPS
OPTIONS_DEFAULT=	DJVU KEYRING PDF TIFF XPS
EPUB_DESC=	EPUB e-book format support
KEYRING_DESC=	Password-protected document support
XPS_DESC=	XPS document support
OPTIONS_SUB=	yes

DJVU_LIB_DEPENDS=	libdjvulibre.so:graphics/djvulibre
DJVU_MESON_ON=		-Ddjvu=true

EPUB_BUILD_DEPENDS=	${MATHJAX_DIR}/MathJax.js:www/mathjax
EPUB_LIB_DEPENDS=	libwebkit2gtk-4.0.so:www/webkit2-gtk3
EPUB_RUN_DEPENDS=	${EPUB_BUILD_DEPENDS}
EPUB_MESON_ON=		-Dmathjax-directory=${MATHJAX_DIR}
EPUB_MESON_OFF=		-Depub=false

KEYRING_LIB_DEPENDS=	libsecret-1.so:security/libsecret
KEYRING_MESON_OFF=	-Dkeyring=false

PDF_LIB_DEPENDS=	libpoppler-glib.so:graphics/poppler-glib
PDF_MESON_OFF=		-Dpdf=false

PS_LIB_DEPENDS=		libspectre.so:print/libspectre
PS_MESON_OFF=		-Dps=false

TIFF_LIB_DEPENDS=	libtiff.so:graphics/tiff
TIFF_MESON_OFF=		-Dtiff=false

XPS_LIB_DEPENDS=	libgxps.so:graphics/libgxps
XPS_MESON_OFF=		-Dxps=false

post-patch:
	@${REINPLACE_CMD} -e '/gdk\/gdkwayland\.h/d' \
		${WRKSRC}/libdocument/ev-document-misc.h

.include <bsd.port.mk>
