# Created by: Martin Klaffenboeck <martin.klaffenboeck@gmx.at>
# $FreeBSD$

PORTNAME=	gtkmm
PORTVERSION=	3.16.0
PORTREVISION?=	0
CATEGORIES=	x11-toolkits
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	30
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	C++ wrapper for Gtk+3

USES+=		tar:xz

PORTSCOUT=	limitw:1,even

.if !defined(REFERENCE_PORT)

BUILD_DEPENDS=	gm4:devel/m4

USES+=		gettext gmake libtool pathfix pkgconfig
USE_GNOME=	gtk30 glibmm cairomm atkmm pangomm
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--disable-documentation
INSTALL_TARGET=	install-strip

PLIST_SUB=	API_VERSION="3.0"

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS =/s/tests//' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>

.endif
