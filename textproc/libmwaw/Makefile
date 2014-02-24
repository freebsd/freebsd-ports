# $FreeBSD$

PORTNAME=	libmwaw
PORTVERSION=	0.1.11
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Import library for some old mac text documents

LICENSE=	LGPL21 MPL
LICENSE_COMB=	dual

BUILD_DEPENDS=	${LOCALBASE}/include/boost/shared_ptr.hpp:${PORTSDIR}/devel/boost-libs
LIB_DEPENDS=	libwpd-0.9.so:${PORTSDIR}/textproc/libwpd

OPTIONS_DEFINE=	DOCS

CONFIGURE_ARGS=	--disable-werror
CPPFLAGS+=	-I${LOCALBASE}/include

USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
USE_XZ=		yes
USES=		pkgconfig pathfix

PORTDOCS=	*
DOCS_BUILD_DEPENDS=	doxygen:${PORTSDIR}/devel/doxygen
DOCS_CONFIGURE_OFF=	--without-docs

.include <bsd.port.mk>
