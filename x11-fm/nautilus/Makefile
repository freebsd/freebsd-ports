# Created by: ade, archie
# $FreeBSD$
#   $MCom: ports/trunk/x11-fm/nautilus3/Makefile 18474 2013-05-17 19:07:22Z kwm $

PORTNAME=	nautilus
PORTVERSION=	3.6.3
CATEGORIES=	x11-fm gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	File manager for the GNOME desktop

BUILD_DEPENDS=	${LOCALBASE}/share/icons/gnome/index.theme:${PORTSDIR}/misc/gnome-icon-theme \
		${LOCALBASE}/libdata/pkgconfig/gsettings-desktop-schemas.pc:${PORTSDIR}/devel/gsettings-desktop-schemas
LIB_DEPENDS=	libexif.so:${PORTSDIR}/graphics/libexif \
		libnotify.so:${PORTSDIR}/devel/libnotify \
		libexempi.so:${PORTSDIR}/textproc/exempi
RUN_DEPENDS=	${LOCALBASE}/share/icons/gnome/index.theme:${PORTSDIR}/misc/gnome-icon-theme \
		${LOCALBASE}/libdata/pkgconfig/gsettings-desktop-schemas.pc:${PORTSDIR}/devel/gsettings-desktop-schemas

USE_XZ=		yes
USES=		desktop-file-utils gettext gmake pathfix pkgconfig \
		shared-mime-info
USE_GNOME=	gnomeprefix intlhack gnomedesktop3 libxml2 \
		ltverhack gvfs ltasneededhack introspection:build
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	LIBS="-pthread"
CONFIGURE_ARGS=	--disable-packagekit --disable-tracker

GLIB_SCHEMAS=	org.gnome.nautilus.gschema.xml

post-patch:
	@${REINPLACE_CMD} -e 's|-DGTK_DISABLE_DEPRECATED||g' \
		${WRKSRC}/configure

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libnautilus-extension.so.1
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/nautilus/extensions-3.0/libnautilus-sendto.so

.include <bsd.port.mk>
