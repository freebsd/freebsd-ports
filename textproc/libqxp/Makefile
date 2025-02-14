PORTNAME=	libqxp
DISTVERSION=	0.0.0
PORTREVISION=	25
CATEGORIES=	textproc
MASTER_SITES=	https://dev-www.libreoffice.org/src/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for parsing QuarkXPress documents
WWW=		https://wiki.documentfoundation.org/DLP/Libraries/libqxp

LICENSE=	MPL20

BUILD_DEPENDS=	${LOCALBASE}/include/boost/cstdint.hpp:devel/boost-libs
LIB_DEPENDS=	librevenge-0.0.so:textproc/librevenge \
		libicui18n.so:devel/icu

USES=		autoreconf compiler:c++11-lang libtool localbase pathfix \
		pkgconfig tar:xz
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

PORTDOCS=	*

CONFIGURE_ARGS=	--disable-werror

OPTIONS_DEFINE=	DOCS DOXYGEN TEST
OPTIONS_SUB=	yes

TEST_LIB_DEPENDS=	libcppunit.so:devel/cppunit
TEST_CONFIGURE_ENABLE=	tests

DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen
DOXYGEN_CONFIGURE_OFF=	--without-docs
DOXYGEN_IMPLIES=	DOCS

.include <bsd.port.mk>
