# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libunique
PORTVERSION=	3.0.2
CATEGORIES=	x11-toolkits
MASTER_SITES=	GNOME

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Library for single instance applications

BUILD_DEPENDS=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection
LIB_DEPENDS=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib

LATEST_LINK=	libunique3
USE_XORG=	ice x11
USE_XZ=		yes
USES=		gettext gmake pkgconfig
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
USE_GNOME=	gtk30 gnomeprefix ltverhack:0
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-maintainer-flags --enable-gtk-doc-html=no
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|libdir)/pkgconfig|prefix)/libdata/pkgconfig|g' \
		-e 's|unique tests doc|unique tests|g' \
		${WRKSRC}/configure ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
