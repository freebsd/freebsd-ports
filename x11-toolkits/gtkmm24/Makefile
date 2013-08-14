# New ports collection makefile for:   gtkmm2
# Date created:        30 September 2002
# Whom:                Martin Klaffenboeck <martin.klaffenboeck@gmx.at>
#
# $FreeBSD$
#   $MCom: ports/x11-toolkits/gtkmm24/Makefile,v 1.77 2011/07/16 17:31:29 kwm Exp $
#

PORTNAME=	gtkmm
PORTVERSION=	2.24.2
PORTREVISION?=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	C++ wrapper for Gtk+, Pango

USE_XZ=		yes
LATEST_LINK=	gtkmm24

.if !defined(REFERENCE_PORT)

LIB_DEPENDS=	glibmm-2.4.1:${PORTSDIR}/devel/glibmm \
		cairomm-1.0.1:${PORTSDIR}/graphics/cairomm \
		atkmm-1.6.2:${PORTSDIR}/accessibility/atkmm \
		pangomm-1.4.1:${PORTSDIR}/x11-toolkits/pangomm
BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4

USE_GMAKE=	yes
USES=		gettext
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
USE_GNOME=	gnomehack gtk20 ltverhack:1
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--disable-documentation \
		--enable-static=yes

PLIST_SUB=	VERSION="2.4" API_VERSION="2.4"

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS =/s/tests//' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>

.endif
