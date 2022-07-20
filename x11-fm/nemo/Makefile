PORTNAME=	nemo
PORTVERSION=	4.8.3
PORTREVISION=	3
CATEGORIES=	x11-fm gnome
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	File manager for the Cinnamon desktop

LICENSE=	GPLv2 LGPL20
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING
LICENSE_FILE_LGPL20=	${WRKSRC}/COPYING.LIB

BUILD_DEPENDS=	gnome-icon-theme>=0:misc/gnome-icon-theme \
		gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas
LIB_DEPENDS=	libcinnamon-desktop.so:x11/cinnamon-desktop \
		libnotify.so:devel/libnotify \
		libxapp.so:x11/xapp
RUN_DEPENDS=	gnome-icon-theme>=0:misc/gnome-icon-theme \
		gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas \
		gvfs>0:devel/gvfs

USES=		compiler:c11 desktop-file-utils gettext gnome meson pkgconfig \
		python:3.5+ shared-mime-info shebangfix xorg

SHEBANG_FILES=	generate_additional_file makepot
SHEBANG_GLOB=	*.py

USE_GITHUB=	yes
GH_ACCOUNT=	linuxmint

USE_GNOME=	cairo gdkpixbuf2 gtk30 intlhack introspection libxml2 pango pygobject3

USE_XORG=	x11

GLIB_SCHEMAS=	org.nemo.gschema.xml

USE_LDCONFIG=	yes

OPTIONS_DEFINE=		DOCS EXEMPI EXIF TRACKER
OPTIONS_DEFAULT=	DOCS EXEMPI EXIF
OPTIONS_SUB=		yes

EXEMPI_DESC=		XMP support
EXIF_DESC=		Digital camera file meta-data support
TRACKER_DESC=		Integration with tracker

DOCS_BUILD_DEPENDS=	gtkdocize:textproc/gtk-doc
DOCS_MESON_TRUE=	gtk_doc

EXEMPI_LIB_DEPENDS=	libexempi.so:textproc/exempi
EXEMPI_MESON_TRUE=	xmp

EXIF_LIB_DEPENDS=	libexif.so:graphics/libexif
EXIF_MESON_TRUE=	exif

TRACKER_LIB_DEPENDS=	libtracker-sparql-2.0.so:sysutils/tracker
TRACKER_MESON_TRUE=	tracker

post-patch:
	# malloc.h is deprecated
	@${REINPLACE_CMD} -e "/malloc.h/d" ${WRKSRC}/meson.build

.include <bsd.port.mk>
