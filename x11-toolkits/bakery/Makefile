# Created by: Ade Lovett <ade@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/x11-toolkits/bakery/Makefile,v 1.16 2009/01/09 22:07:11 kwm Exp $

PORTNAME=	bakery
PORTVERSION=	2.6.3
PORTREVISION=	9
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	C++ Application Framework for use with Gtkmm

LIB_DEPENDS=	libgconfmm-2.6.so:devel/gconfmm26 \
		libglademm-2.4.so:devel/libglademm24 \
		libgnomevfsmm-2.6.so:devel/gnome-vfsmm \
		libxml++-2.6.so:textproc/libxml++26

USES=		gettext gmake libtool:keepla pathfix pkgconfig tar:bzip2
USE_GNOME=	gnomeprefix intlhack
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

PLIST_SUB=	VERSION="2.6" API_VERSION="2.6"

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS =/s/examples//' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
