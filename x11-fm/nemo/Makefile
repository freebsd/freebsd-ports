# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	nemo
PORTVERSION=	1.8.5
CATEGORIES=	x11-fm gnome
MASTER_SITES=	http://github.com/linuxmint/${PORTNAME}/archive/${PORTVERSION}.tar.gz?dummy=/
DIST_SUBDIR=	gnome3

MAINTAINER=	gustau.perez@gmail.com
COMMENT=	File manager for the Cinnamon desktop

BUILD_DEPENDS=	${LOCALBASE}/share/icons/gnome/index.theme:${PORTSDIR}/misc/gnome-icon-theme \
		gtkdocize:${PORTSDIR}/textproc/gtk-doc \
		gnome-autogen.sh:${PORTSDIR}/devel/gnome-common \
		${LOCALBASE}/libdata/pkgconfig/gsettings-desktop-schemas.pc:${PORTSDIR}/devel/gsettings-desktop-schemas
LIB_DEPENDS=	libexif.so:${PORTSDIR}/graphics/libexif \
		libnotify.so:${PORTSDIR}/devel/libnotify \
		libexempi.so:${PORTSDIR}/textproc/exempi
RUN_DEPENDS=	${LOCALBASE}/share/icons/gnome/index.theme:${PORTSDIR}/misc/gnome-icon-theme \
		${LOCALBASE}/libdata/pkgconfig/gsettings-desktop-schemas.pc:${PORTSDIR}/devel/gsettings-desktop-schemas

FETCH_ARGS=	-Fpr
INSTALLS_ICONS=	yes
USES=		desktop-file-utils gettext gmake pathfix \
		pkgconfig shared-mime-info
USE_GNOME=	gnomeprefix intlhack gnomedesktop3 libxml2 \
		introspection:build
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool autoconf automake
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CONFIGURE_ARGS=	--enable-static --disable-packagekit --disable-tracker
MAKE_ENV=	G_CHARSET_ALIAS="${LOCALBASE}/libdata/charset.alias"

GLIB_SCHEMAS=	org.nemo.gschema.xml

post-patch:
	@${MKDIR} ${WRKSRC}/files${PREFIX}

	@${MV} ${WRKSRC}/files/usr/share ${WRKSRC}/files${PREFIX}

	@${REINPLACE_CMD} -e 's|find|find ${WRKSRC}/files|g' \
		${WRKSRC}/files/Makefile.in

	@${REINPLACE_CMD} -e 's|-DGTK_DISABLE_DEPRECATED||g' \
		${WRKSRC}/configure.in

	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|g' \
		${WRKSRC}/src/nemo-properties-window.c

	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|g ;\
		s|@INTROSPECTION_TYPELIBDIR@|$$(libdir)/girepository-1.0|g ;\
		s|@INTROSPECTION_GIRDIR@|$$(datadir)/gir-1.0|g' \
		${WRKSRC}/libnemo-extension/Makefile.am

	@${REINPLACE_CMD} -e 's|x-gnome-saved-search|x-nemo-saved-search|g' \
		${WRKSRC}/data/nemo.xml.in \
		${WRKSRC}/libnemo-private/nemo-file-utilities.h

	@${FIND} ${WRKSRC} -name \* | ${XARGS} ${EGREP} -l "#!.*\/usr\/bin\/python" | \
		${XARGS} ${REINPLACE_CMD} -I "" -e "s|#!.*python.*|#!/usr/bin/env python|g"

pre-configure:
	cd ${WRKSRC} && NOCONFIGURE=yes ${SH} ./autogen.sh

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libnemo-extension.so.5 

.include <bsd.port.mk>
