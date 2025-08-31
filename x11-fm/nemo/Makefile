PORTNAME=	nemo
DISTVERSION=	6.4.5
PORTREVISION=	1
CATEGORIES=	x11-fm gnome
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	File manager for the Cinnamon desktop
WWW=		https://github.com/linuxmint/nemo

LICENSE=	GPLv2 LGPL20
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING
LICENSE_FILE_LGPL20=	${WRKSRC}/COPYING.LIB

LIB_DEPENDS=	libcinnamon-desktop.so:x11/cinnamon-desktop \
		libxapp.so:x11/xapp \
		libjson-glib-1.0.so:devel/json-glib \
		libxmlb.so:textproc/libxmlb
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cairo>=0:graphics/py-cairo@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pdfminer.six>=0:textproc/py-pdfminer.six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xlrd>=0:textproc/py-xlrd@${PY_FLAVOR} \
		catdoc:textproc/catdoc \
		exif:graphics/exif \
		gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas \
		gvfs>0:filesystems/gvfs \
		html2text:textproc/html2text \
		id3:audio/id3mtag \
		pdftotext:graphics/poppler-utils \
		ps2ascii:print/ghostscript10

USES=		compiler:c11 desktop-file-utils gettext-runtime gnome meson pkgconfig \
		python localbase shebangfix xorg

SHEBANG_FILES=	generate_additional_file search-helpers/nemo-xls-to-txt \
		search-helpers/nemo-odf-to-txt
SHEBANG_GLOB=	*.py

USE_GITHUB=	yes
GH_ACCOUNT=	linuxmint

USE_GNOME=	cairo gdkpixbuf gtk30 intltool pygobject3 libgsf \
		introspection:build

USE_XORG=	x11 xext xorgproto xrender

MESON_ARGS=	-Dtracker=false

GLIB_SCHEMAS=	org.nemo.gschema.xml

USE_LDCONFIG=	yes

OPTIONS_DEFINE=		DOCS EXEMPI EXIF
OPTIONS_DEFAULT=	DOCS EXEMPI EXIF

EXEMPI_DESC=		XMP support
EXIF_DESC=		Digital camera file meta-data support

DOCS_BUILD_DEPENDS=	gtkdocize:textproc/gtk-doc
DOCS_MESON_TRUE=	gtk_doc

EXEMPI_LIB_DEPENDS=	libexempi.so:textproc/exempi
EXEMPI_MESON_TRUE=	xmp

EXIF_LIB_DEPENDS=	libexif.so:graphics/libexif
EXIF_MESON_TRUE=	exif

.include <bsd.port.mk>
