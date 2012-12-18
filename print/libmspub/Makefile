# $FreeBSD$

PORTNAME=	libmspub
PORTVERSION=	0.0.3
CATEGORIES=	print graphics devel
MASTER_SITES=	http://dev-www.libreoffice.org/src/

MAINTAINER=	office@FreeBSD.org
COMMENT=	Library providing ability to interpret and import Microsoft Publisher content

LICENSE=	LGPL21 MPL GPLv2
LICENSE_COMB=	dual

BUILD_DEPENDS=	${LOCALBASE}/include/boost/ptr_container/ptr_map.hpp:${PORTSDIR}/devel/boost-libs
LIB_DEPENDS=	wpd-0.9:${PORTSDIR}/textproc/libwpd \
		wpg-0.2:${PORTSDIR}/graphics/libwpg

CPPFLAGS+=	-I${LOCALBASE}/include
USE_XZ=		yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-werror
USE_GNOME=	gnomehack
USE_LDCONFIG=	yes
USE_PKGCONFIG=	build

.include <bsd.port.mk>
