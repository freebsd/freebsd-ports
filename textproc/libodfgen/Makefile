# $FreeBSD$

PORTNAME=	libodfgen
PORTVERSION=	0.0.4
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	SF/libwpd/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Library for reading and writing Corel WordPerfect(tm) documents

LICENSE=	LGPL21 MPL
LICENSE_COMB=	dual

BUILD_DEPENDS=	${LOCALBASE}/include/boost/shared_ptr.hpp:${PORTSDIR}/devel/boost-libs
LIB_DEPENDS=	libetonyek-0.0.so:${PORTSDIR}/graphics/libetonyek \
		libwpg-0.2.so:${PORTSDIR}/graphics/libwpg \
		libwpd-0.9.so:${PORTSDIR}/textproc/libwpd

OPTIONS_DEFINE=	DOCS

CONFIGURE_ARGS=	--disable-werror
CPPFLAGS+=	-I${LOCALBASE}/include

GNU_CONFIGURE=	yes
USES=		libtool:keepla pathfix pkgconfig
USE_LDCONFIG=	yes
USE_XZ=		yes

PORTDOCS=	*
DOCS_BUILD_DEPENDS=	doxygen:${PORTSDIR}/devel/doxygen
DOCS_CONFIGURE_OFF=	--without-docs

.include <bsd.port.mk>
