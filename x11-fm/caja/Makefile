# Created by: ade, archie
# $FreeBSD$

PORTNAME=	caja
PORTVERSION=	1.12.4
CATEGORIES=	x11-fm mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT?=	File manager for the MATE desktop

BUILD_DEPENDS=	gtkdoc-check:textproc/gtk-doc
LIB_DEPENDS=	libexif.so:graphics/libexif \
		libunique-1.0.so:x11-toolkits/unique \
		libexempi.so:textproc/exempi
RUN_DEPENDS=	${LOCALBASE}/libexec/gvfsd:devel/gvfs

PORTSCOUT=	limitw:1,even

USES=		desktop-file-utils gettext gmake libtool pathfix pkgconfig \
		shared-mime-info tar:xz
USE_MATE=	desktop icontheme:run
USE_XORG=	ice x11 xrender
USE_GNOME=	glib20 gtk20 intltool introspection:build \
		libxml2 pango
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-packagekit \
		--with-gtk=2.0 \
		--disable-gtk-doc \
		--with-html-dir=${PREFIX}/share/doc
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.mate.caja.gschema.xml \
		org.mate.media-handling.gschema.xml

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/caja/extensions-2.0
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libcaja-extension.so.1.4.0

.include <bsd.port.mk>
