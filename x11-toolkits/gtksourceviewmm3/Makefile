PORTNAME=	gtksourceviewmm
PORTVERSION=	3.18.0
PORTREVISION=	2
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	C++ binding of GtkSourceView3

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

PORTSCOUT=	limitw:1,even

USES=		compiler:c++11-lang gmake gnome libtool:keepla pathfix \
		pkgconfig tar:xz
USE_CXXSTD=	c++11
USE_LDCONFIG=	yes
USE_GNOME=	gtksourceview3 gnomeprefix gtkmm30
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBAS}/lib
CONFIGURE_ARGS=	--disable-documentation
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
