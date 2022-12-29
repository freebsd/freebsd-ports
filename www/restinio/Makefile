PORTNAME=	restinio
DISTVERSION=	0.6.17
PORTREVISION=	2
CATEGORIES=	www devel
MASTER_SITES=	https://github.com/Stiffstream/${PORTNAME}/releases/download/v.${DISTVERSION}/
DISTNAME=	${PORTNAME}-${DISTVERSION}-full

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Asynchronous HTTP/WebSocket server C++14 library
WWW=		https://stiffstream.com/en/products/restinio.html

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/../LICENSE

BUILD_DEPENDS=	libfmt>0:devel/libfmt \
		sobjectizer>0:devel/sobjectizer
LIB_DEPENDS=	libboost_regex.so:devel/boost-libs \
		libhttp_parser.so:www/http-parser \
		libpcre2-8.so:devel/pcre2
RUN_DEPENDS=	libfmt>0:devel/libfmt \
		sobjectizer>0:devel/sobjectizer

USES=		cmake:testing compiler:c++14-lang localbase:ldflags tar:bz2

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}
WRKSRC_SUBDIR=	dev

CMAKE_ARGS=		-DRESTINIO_USE_BOOST_ASIO=shared
CMAKE_ON=		RESTINIO_FIND_DEPS RESTINIO_USE_EXTERNAL_HTTP_PARSER RESTINIO_USE_EXTERNAL_SOBJECTIZER
CMAKE_OFF=		RESTINIO_BENCH RESTINIO_INSTALL_BENCHES RESTINIO_TEST
CMAKE_TESTING_ON=	RESTINIO_TEST

OPTIONS_DEFINE=		SAMPLES
OPTIONS_SUB=		yes

SAMPLES_DESC=		Build and install samples
SAMPLES_USES=		ssl
SAMPLES_CXXFLAGS+=	-I${WRKSRC}/clara
SAMPLES_CMAKE_BOOL=	RESTINIO_SAMPLE RESTINIO_INSTALL_SAMPLES
SAMPLES_VARS_OFF=	NO_ARCH=yes
SAMPLES_BUILD_DEPENDS=	json-dto>0:devel/json-dto

post-extract:
	${RM} -rf ${WRKSRC}/asio
	${RM} -rf ${WRKSRC}/asio_mxxru
	${RM} -rf ${WRKSRC}/catch2
	${RM} -rf ${WRKSRC}/fmt
	${RM} -rf ${WRKSRC}/fmt_mxxru
	${RM} -rf ${WRKSRC}/nodejs/http_parser/http-parser.*
	${RM} -rf ${WRKSRC}/nodejs/http_parser_mxxru
	${RM} -rf ${WRKSRC}/rapidjson
	${RM} -rf ${WRKSRC}/rapidjson_mxxru
	${RM} -rf ${WRKSRC}/so_5
	${RM} -rf ${WRKSRC}/timertt

.include <bsd.port.mk>
