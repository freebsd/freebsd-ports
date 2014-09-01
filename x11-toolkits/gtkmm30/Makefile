# Created by: Martin Klaffenboeck <martin.klaffenboeck@gmx.at>
# $FreeBSD$
#   $MCom: ports/trunk/x11-toolkits/gtkmm30/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	gtkmm
PORTVERSION=	3.8.1
PORTREVISION?=	3
CATEGORIES=	x11-toolkits
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	30
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	C++ wrapper for Gtk+3

USES+=		tar:xz

.if !defined(REFERENCE_PORT)

BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES+=		gettext gmake libtool:keepla pathfix pkgconfig
USE_GNOME=	gtk30 glibmm cairomm atkmm pangomm
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--disable-documentation \
		--enable-static=yes
INSTALL_TARGET=	install-strip

PLIST_SUB=	VERSION="3.0" API_VERSION="3.0"

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS =/s/tests//' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>

.endif
