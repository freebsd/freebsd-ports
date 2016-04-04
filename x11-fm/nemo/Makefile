# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	nemo
PORTVERSION=	2.4.5
CATEGORIES=	x11-fm gnome
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	File manager for the Cinnamon desktop

BUILD_DEPENDS=	gnome-icon-theme>=0:misc/gnome-icon-theme \
		gtkdocize:textproc/gtk-doc \
		py*-polib>=0:devel/py-polib \
		gnome-autogen.sh:devel/gnome-common \
		gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas
LIB_DEPENDS=	libexif.so:graphics/libexif \
		libcinnamon-desktop.so:x11/cinnamon-desktop \
		libnotify.so:devel/libnotify \
		libexempi.so:textproc/exempi
RUN_DEPENDS=	gnome-icon-theme>=0:misc/gnome-icon-theme \
		gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas

USES=		autoreconf:build desktop-file-utils gettext gmake libtool pathfix \
		pkgconfig python:2 shared-mime-info
USE_GNOME=	gnomedesktop3 gnomeprefix intlhack introspection:build \
		libxml2 pygobject3
USE_GITHUB=	yes
GH_ACCOUNT=	linuxmint
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lpthread
INSTALL_TARGET=	install-strip
CONFIGURE_ARGS=	--enable-static --disable-packagekit

GLIB_SCHEMAS=	org.nemo.gschema.xml

OPTIONS_SUB=			yes
OPTIONS_DEFINE=			TRACKER
OPTIONS_DEFAULT=		TRACKER
TRACKER_CONFIGURE_ENABLE=	tracker
TRACKER_LIB_DEPENDS=		libtracker-sparql-1.0.so:sysutils/tracker
TRACKER_DESC=			Integration with tracker

post-patch:
	@${MKDIR} ${WRKSRC}/files${PREFIX}

	@${MV} ${WRKSRC}/files/usr/share ${WRKSRC}/files${PREFIX}

	@${REINPLACE_CMD} -e 's|0.16|1.0|g' \
		${WRKSRC}/configure.in

	@${REINPLACE_CMD} -e 's|find|find ${WRKSRC}/files|g' \
		${WRKSRC}/files/Makefile.in

	@${REINPLACE_CMD} -e 's|-DGTK_DISABLE_DEPRECATED||g' \
		${WRKSRC}/configure.in

	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|g' \
		${WRKSRC}/src/nemo-properties-window.c

	@${REINPLACE_CMD} -e 's|"-DG_DISABLE_DEPRECATED -DGTK_DISABLE_DEPRECATED -DGDK_DISABLE_DEPRECATED -DGDK_PIXBUF_DISABLE_DEPRECATED"|""|g' \
		${WRKSRC}/configure.in

	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|g ;\
		s|@INTROSPECTION_TYPELIBDIR@|$$(libdir)/girepository-1.0|g ;\
		s|@INTROSPECTION_GIRDIR@|$$(datadir)/gir-1.0|g' \
		${WRKSRC}/libnemo-extension/Makefile.am

	@${REINPLACE_CMD} -e 's|x-gnome-saved-search|x-nemo-saved-search|g' \
		${WRKSRC}/data/nemo.xml.in \
		${WRKSRC}/libnemo-private/nemo-file-utilities.h

	@${FIND} ${WRKSRC} -name \* | ${XARGS} ${EGREP} -l "#!.*\/usr\/bin\/python" | \
		${XARGS} ${REINPLACE_CMD} -I "" -e "s|#!.*python.*|#!${PYTHON_CMD}|g"

	@${REINPLACE_CMD} 's|\"/usr|\"${PREFIX}|g' \
		${WRKSRC}/data/merge_action_strings

	@${REINPLACE_CMD} 's|"files", "usr"|"files", "${PREFIX}".strip("/")|g' \
		${WRKSRC}/data/merge_action_strings

pre-configure:
	cd ${WRKSRC} && ${SETENV} NOCONFIGURE=yes ${SH} ./autogen.sh

.include <bsd.port.mk>
