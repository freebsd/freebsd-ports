# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libwps
PORTVERSION=	0.2.9
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	office@FreeBSD.org
COMMENT=	A Microsoft file word processor format import filter library

LICENSE=	LGPL21 MPL
LICENSE_COMB=	dual

BUILD_DEPENDS=	${LOCALBASE}/include/boost/shared_ptr.hpp:${PORTSDIR}/devel/boost-libs
LIB_DEPENDS=	libwpd-0.9.so:${PORTSDIR}/textproc/libwpd

OPTIONS_DEFINE=	DOCS

CONFIGURE_ARGS=	--disable-werror
CPPFLAGS+=	-I${LOCALBASE}/include
USE_AUTOTOOLS=	libtool
USES=		pkgconfig pathfix
USE_GNOME=	gnomeprefix ltverhack
USE_LDCONFIG=	yes
PORTDOCS=	*
DOCS_BUILD_DEPENDS=	doxygen:${PORTSDIR}/devel/doxygen
DOCS_CONFIGURE_OFF=	--without-docs

.include <bsd.port.mk>
