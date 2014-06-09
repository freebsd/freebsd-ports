# $FreeBSD$

PORTNAME=	librevenge
PORTVERSION=	0.0.1
CATEGORIES=	textproc
MASTER_SITES=	SF/libwpd/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Base library for writing document import filters

LICENSE=	LGPL21 MPL
LICENSE_COMB=	dual

USES=		gmake libtool pathfix tar:xz
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

BUILD_DEPENDS=	${LOCALBASE}/include/boost/algorithm/string.hpp:${PORTSDIR}/devel/boost-libs

OPTIONS_DEFINE=	DOCS

CPPFLAGS=	-I${LOCALBASE}/include
CONFIGURE_ARGS=	-disable-werror

PORTDOCS=	*
DOCS_BUILD_DEPENDS=	doxygen:${PORTSDIR}/devel/doxygen
DOCS_CONFIGURE_OFF=	--without-docs

.include <bsd.port.mk>
