# Created by: Martin Klaffenboeck <martin.klaffenboeck@gmx.at>
# $FreeBSD$
#   $MCom: ports/x11-toolkits/gtkmm24/Makefile,v 1.77 2011/07/16 17:31:29 kwm Exp $

PORTNAME=	gtkmm
PORTVERSION=	2.24.4
PORTREVISION?=	3
CATEGORIES=	x11-toolkits
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	24
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	C++ wrapper for Gtk+

USES+=		tar:xz

PORTSCOUT=	ignore:1

.if !defined(REFERENCE_PORT)

BUILD_DEPENDS=	gm4:devel/m4

GNU_CONFIGURE=	yes
USES+=		gettext gmake libtool:keepla pathfix pkgconfig
USE_LDCONFIG=	yes
USE_GNOME=	atkmm gtk20 pangomm
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--disable-documentation

PLIST_SUB=	VERSION="2.4" API_VERSION="2.4"

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS =/s/tests//' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>

.endif
