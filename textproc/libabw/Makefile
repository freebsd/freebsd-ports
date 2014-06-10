# $FreeBSD$

PORTNAME=	libabw
PORTVERSION=	0.1.0
CATEGORIES=	textproc
MASTER_SITES=	http://dev-www.libreoffice.org/src/

MAINTAINER=	office@FreeBSD.org
COMMENT=	Library providing ability to interpret Abiword documents

LICENSE=	LGPL21 MPL
LICENSE_COMB=	dual

OPTIONS_DEFINE=	DOCS

BUILD_DEPENDS=	${LOCALBASE}/include/boost/algorithm/string.hpp:${PORTSDIR}/devel/boost-libs
LIB_DEPENDS=	librevenge-0.0.so:${PORTSDIR}/textproc/librevenge

USES=		libtool pathfix pkgconfig tar:xz
USE_GNOME=	libxml2
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

CPPFLAGS=	-I${LOCALBASE}/include
CONFIGURE_ARGS=	-disable-werror

PORTDOCS=	*
DOCS_BUILD_DEPENDS=	doxygen:${PORTSDIR}/devel/doxygen
DOCS_CONFIGURE_OFF=	--without-docs

.include <bsd.port.mk>
