PORTNAME=	libepubgen
PORTVERSION=	0.1.1
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	greg@unrelenting.technology
COMMENT=	Library for generating documents in ePub format

LICENSE=	MPL20

BUILD_DEPENDS=	${LOCALBASE}/include/boost/algorithm/string/classification.hpp:devel/boost-libs \
		${LOCALBASE}/include/boost/algorithm/string/join.hpp:devel/boost-libs \
		${LOCALBASE}/include/boost/algorithm/string/split.hpp:devel/boost-libs \
		${LOCALBASE}/include/boost/algorithm/string/trim.hpp:devel/boost-libs \
		${LOCALBASE}/include/boost/assign/list_of.hpp:devel/boost-libs \
		${LOCALBASE}/include/boost/cstdint.hpp:devel/boost-libs \
		${LOCALBASE}/include/boost/functional/hash.hpp:devel/boost-libs
LIB_DEPENDS=	librevenge-0.0.so:textproc/librevenge

USES=		compiler:c++11-lang libtool pathfix pkgconfig tar:xz
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-werror

INSTALL_TARGET=	install-strip

CPPFLAGS+=	-I${LOCALBASE}/include

SO_VER=		1.0.1
PLIST_SUB+=	SO_VER="${SO_VER}"

PORTDOCS=		*

OPTIONS_DEFINE=	DOCS DOXYGEN TEST
OPTIONS_DEFAULT=
OPTIONS_SUB=	yes

DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen
DOXYGEN_CONFIGURE_OFF=	--without-docs
DOXYGEN_IMPLIES=	DOCS

TEST_TARGET=		check
TEST_LIB_DEPENDS=	libxml2.so:textproc/libxml2 \
			libcppunit.so:devel/cppunit
TEST_CONFIGURE_ENABLE=	tests

.include <bsd.port.mk>
