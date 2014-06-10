# $FreeBSD$

PORTNAME=	libe-book
PORTVERSION=	0.1.1
CATEGORIES=	textproc
MASTER_SITES=	SF/libebook/${PORTNAME}-${PORTVERSION}/

MAINTAINER=	office@FreeBSD.org
COMMENT=	Library for import of reflowable e-book formats

LICENSE=	LGPL21 MPL
LICENSE_COMB=	dual

OPTIONS_DEFINE=	DOCS

BUILD_DEPENDS=	${LOCALBASE}/include/boost/algorithm/string.hpp:${PORTSDIR}/devel/boost-libs
LIB_DEPENDS=	libicui18n.so:${PORTSDIR}/devel/icu \
		librevenge-0.0.so:${PORTSDIR}/textproc/librevenge

USE_GNOME=	libxml2

USES=		gmake libtool pathfix pkgconfig tar:xz
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ZLIB_CFLAGS="-DWEHAVEZLIBINBASE" ZLIB_LIBS="-DWEDOHAVEIT"
INSTALL_TARGET=	install-strip
CONFIGURE_ARGS=	--disable-werror
CPPFLAGS+=	-I${LOCALBASE}/include

PORTDOCS=	*
DOCS_BUILD_DEPENDS=	doxygen:${PORTSDIR}/devel/doxygen
DOCS_CONFIGURE_OFF=	--without-docs

.include <bsd.port.mk>
