# $FreeBSD$

PORTNAME=	librevenge
PORTVERSION=	0.0.4
PORTREVISION=	5
CATEGORIES=	textproc
MASTER_SITES=	SF/libwpd/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Base library for writing document import filters

LICENSE=	LGPL21 MPL
LICENSE_COMB=	dual

USES=		gmake libtool pathfix tar:xz
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

BUILD_DEPENDS=	${LOCALBASE}/include/boost/algorithm/string.hpp:devel/boost-libs

OPTIONS_DEFINE=	DOXYGEN

CPPFLAGS=	-I${LOCALBASE}/include
CONFIGURE_ARGS=	-disable-werror --disable-tests

PORTDOCS=	*
DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen
DOXYGEN_CONFIGURE_OFF=	--without-docs

.include <bsd.port.mk>
