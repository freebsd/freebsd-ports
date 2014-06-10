# $FreeBSD$

PORTNAME=	libabw
PORTVERSION=	0.0.2
CATEGORIES=	textproc
MASTER_SITES=	http://dev-www.libreoffice.org/src/
PKGNAMESUFFIX=	00

MAINTAINER=	office@FreeBSD.org
COMMENT=	Library providing ability to interpret Abiword documents

LICENSE=	LGPL21 MPL
LICENSE_COMB=	dual

BUILD_DEPENDS=	${LOCALBASE}/include/boost/algorithm/string.hpp:${PORTSDIR}/devel/boost-libs
LIB_DEPENDS=	libwpd-0.9.so:${PORTSDIR}/textproc/libwpd

USES=		libtool pathfix pkgconfig tar:xz
USE_LDCONFIG=	yes
USE_GNOME=	libxml2
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

CPPFLAGS=	-I${LOCALBASE}/include
CONFIGURE_ARGS=	-disable-werror --without-docs --disable-tools

.include <bsd.port.mk>
