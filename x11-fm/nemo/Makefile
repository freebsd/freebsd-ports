PORTNAME=	nemo
PORTVERSION=	5.4.2
PORTREVISION=	7
CATEGORIES=	x11-fm gnome
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	File manager for the Cinnamon desktop
WWW=		https://github.com/linuxmint/nemo

LICENSE=	GPLv2 LGPL20
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING
LICENSE_FILE_LGPL20=	${WRKSRC}/COPYING.LIB

BUILD_DEPENDS=	gnome-icon-theme>=0:misc/gnome-icon-theme \
		gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas
LIB_DEPENDS=	libcinnamon-desktop.so:x11/cinnamon-desktop \
		libxapp.so:x11/xapp
RUN_DEPENDS=	gnome-icon-theme>=0:misc/gnome-icon-theme \
		gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas \
		gvfs>0:filesystems/gvfs

USES=		compiler:c11 desktop-file-utils gettext gnome meson pkgconfig \
		python shared-mime-info shebangfix xorg

SHEBANG_FILES=	generate_additional_file makepot search-helpers/nemo-xls-to-txt
SHEBANG_GLOB=	*.py

USE_GITHUB=	yes
GH_ACCOUNT=	linuxmint

USE_GNOME=	cairo gdkpixbuf gtk30 intlhack introspection libgsf \
		libxml2 pango pygobject3

USE_XORG=	x11

MESON_ARGS=	-Dtracker=false

GLIB_SCHEMAS=	org.nemo.gschema.xml

USE_LDCONFIG=	yes

OPTIONS_DEFINE=		DOCS EXEMPI EXIF
OPTIONS_DEFAULT=	DOCS EXEMPI EXIF
OPTIONS_SUB=		yes

EXEMPI_DESC=		XMP support
EXIF_DESC=		Digital camera file meta-data support

DOCS_BUILD_DEPENDS=	gtkdocize:textproc/gtk-doc
DOCS_MESON_TRUE=	gtk_doc

EXEMPI_LIB_DEPENDS=	libexempi.so:textproc/exempi
EXEMPI_MESON_TRUE=	xmp

EXIF_LIB_DEPENDS=	libexif.so:graphics/libexif
EXIF_MESON_TRUE=	exif

.include <bsd.port.mk>
