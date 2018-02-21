# $FreeBSD$

PORTNAME=	libepubgen
PORTVERSION=	0.1.0
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	greg@unrelenting.technology
COMMENT=	Library for generating documents in ePub format

LICENSE=	MPL20

LIB_DEPENDS=	librevenge-0.0.so:textproc/librevenge
BUILD_DEPENDS=	${LOCALBASE}/include/boost/algorithm/string/classification.hpp:devel/boost-libs \
		${LOCALBASE}/include/boost/algorithm/string/join.hpp:devel/boost-libs \
		${LOCALBASE}/include/boost/algorithm/string/split.hpp:devel/boost-libs \
		${LOCALBASE}/include/boost/algorithm/string/trim.hpp:devel/boost-libs \
		${LOCALBASE}/include/boost/assign/list_of.hpp:devel/boost-libs \
		${LOCALBASE}/include/boost/cstdint.hpp:devel/boost-libs \
		${LOCALBASE}/include/boost/functional/hash.hpp:devel/boost-libs

CONFIGURE_ARGS=	--disable-werror
CPPFLAGS+=	-I${LOCALBASE}/include

GNU_CONFIGURE=	yes
USES=		compiler:features libtool pathfix pkgconfig tar:xz
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DOXYGEN TEST
OPTIONS_DEFAULT=
OPTIONS_SUB=	yes

TEST_TARGET=		check
TEST_LIB_DEPENDS=	libxml2.so:textproc/libxml2 \
			libcppunit.so:devel/cppunit
TEST_CONFIGURE_ENABLE=	tests

PORTDOCS=		*
DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen
DOXYGEN_CONFIGURE_OFF=	--without-docs

.include <bsd.port.mk>
