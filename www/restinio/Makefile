PORTNAME=	restinio
DISTVERSIONPREFIX=	v.
DISTVERSION=	0.6.17
CATEGORIES=	www devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Asynchronous HTTP/WebSocket server C++14 library
WWW=		https://stiffstream.com/en/products/restinio.html

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/../LICENSE

BUILD_DEPENDS=	asio>0:net/asio \
		libfmt>0:devel/libfmt \
		sobjectizer>0:devel/sobjectizer
LIB_DEPENDS=	libboost_regex.so:devel/boost-libs \
		libhttp_parser.so:www/http-parser \
		libpcre2-8.so:devel/pcre2
RUN_DEPENDS=	asio>0:net/asio \
		libfmt>0:devel/libfmt \
		sobjectizer>0:devel/sobjectizer

USES=		cmake:testing compiler:c++14-lang localbase:ldflags

USE_GITHUB=	yes
GH_ACCOUNT=	Stiffstream
GH_TUPLE=	catchorg:Clara:2bfd8b2:clara

WRKSRC_SUBDIR=	dev

CXXFLAGS+=	-I${WRKSRC_clara}/include

CMAKE_ON=		RESTINIO_FIND_DEPS RESTINIO_USE_EXTERNAL_HTTP_PARSER RESTINIO_USE_EXTERNAL_SOBJECTIZER
CMAKE_OFF=		RESTINIO_BENCH RESTINIO_INSTALL_BENCHES RESTINIO_TEST
CMAKE_TESTING_ON=	RESTINIO_TEST

OPTIONS_DEFINE=		SAMPLES
OPTIONS_SUB=		yes

SAMPLES_DESC=		Build and install samples
SAMPLES_USES=		ssl
SAMPLES_CMAKE_BOOL=	RESTINIO_SAMPLE RESTINIO_INSTALL_SAMPLES
SAMPLES_VARS_OFF=	NO_ARCH=yes
SAMPLES_BUILD_DEPENDS=	json-dto>0:devel/json-dto

.include <bsd.port.mk>
