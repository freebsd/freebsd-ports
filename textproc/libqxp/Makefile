# $FreeBSD$

PORTNAME=	libqxp
PORTVERSION=	0.0.0
CATEGORIES=	textproc
MASTER_SITES=	https://dev-www.libreoffice.org/src/${PORTNAME}/

MAINTAINER=	greg@unrelenting.technology
COMMENT=	Library for parsing QuarkXPress documents

LICENSE=	MPL20

LIB_DEPENDS=	librevenge-0.0.so:textproc/librevenge \
		libicui18n.so:devel/icu
		#libicui18n.so:devel/icu \
		#libicuuc.so:devel/icu \
		#libicudata.so:devel/icu
BUILD_DEPENDS=	${LOCALBASE}/include/boost/math/constants/constants.hpp:devel/boost-libs \
		${LOCALBASE}/include/boost/optional.hpp:devel/boost-libs \
		${LOCALBASE}/include/boost/variant.hpp:devel/boost-libs \
		${LOCALBASE}/include/boost/range/adaptor/reversed.hpp:devel/boost-libs \
		${LOCALBASE}/include/boost/cstdint.hpp:devel/boost-libs

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
TEST_LIB_DEPENDS=	libcppunit.so:devel/cppunit
TEST_CONFIGURE_ENABLE=	tests

PORTDOCS=		*
DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen
DOXYGEN_CONFIGURE_OFF=	--without-docs

.include <bsd.port.mk>
