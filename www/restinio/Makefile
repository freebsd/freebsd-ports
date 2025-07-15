PORTNAME=	restinio
DISTVERSION=	0.7.3
PORTREVISION=	4
CATEGORIES=	www devel
MASTER_SITES=	https://github.com/Stiffstream/${PORTNAME}/releases/download/v.${DISTVERSION}/
DISTNAME=	${PORTNAME}-${DISTVERSION}-full

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Asynchronous HTTP/WebSocket server C++17 library
WWW=		https://stiffstream.com/en/products/restinio.html \
		https://github.com/Stiffstream/restinio

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/../LICENSE

BUILD_DEPENDS=	asio>0:net/asio \
		libfmt>0:devel/libfmt \
		sobjectizer>0:devel/sobjectizer
LIB_DEPENDS=	libboost_regex.so:devel/boost-libs \
		libhttp_parser.so:www/http-parser \
		libllhttp.so:www/llhttp \
		libpcre2-8.so:devel/pcre2
RUN_DEPENDS=	libfmt>0:devel/libfmt \
		sobjectizer>0:devel/sobjectizer
TEST_DEPENDS=	catch2>0:devel/catch2

USES=		cmake:testing compiler:c++17-lang localbase:ldflags tar:bz2

EXTRACT_AFTER_ARGS=	--exclude ${PORTNAME}-${DISTVERSION}/dev/asio \
			--exclude ${PORTNAME}-${DISTVERSION}/dev/asio_mxxru \
			--exclude ${PORTNAME}-${DISTVERSION}/dev/catch2 \
			--exclude ${PORTNAME}-${DISTVERSION}/dev/fmt \
			--exclude ${PORTNAME}-${DISTVERSION}/dev/fmt_mxxru \
			--exclude ${PORTNAME}-${DISTVERSION}/dev/nodejs/http_parser/http_parser.* \
			--exclude ${PORTNAME}-${DISTVERSION}/dev/nodejs/http_parser_mxxru \
			--exclude ${PORTNAME}-${DISTVERSION}/dev/rapidjson \
			--exclude ${PORTNAME}-${DISTVERSION}/dev/rapidjson_mxxru \
			--exclude ${PORTNAME}-${DISTVERSION}/dev/so_5 \
			--exclude ${PORTNAME}-${DISTVERSION}/dev/timertt \
			--no-same-owner --no-same-permissions

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}
WRKSRC_SUBDIR=	dev

CMAKE_ARGS=		-DRESTINIO_USE_BOOST_ASIO=shared \
			-DRESTINIO_DEP_FMT=system \
			-DRESTINIO_DEP_SOBJECTIZER=find \
			-DRESTINIO_DEP_CATCH2=find \
			-DRESTINIO_DEP_LLHTTP=find
CMAKE_ON=		RESTINIO_FIND_DEPS
CMAKE_OFF=		RESTINIO_BENCH \
			RESTINIO_INSTALL_BENCHES \
			RESTINIO_TEST
CMAKE_TESTING_ON=	RESTINIO_TEST

OPTIONS_DEFINE=		SAMPLES
OPTIONS_SUB=		yes

SAMPLES_DESC=		Build and install samples
SAMPLES_USES=		ssl
SAMPLES_CXXFLAGS+=	-I${WRKSRC}/clara
SAMPLES_CMAKE_BOOL=	RESTINIO_SAMPLE RESTINIO_INSTALL_SAMPLES
SAMPLES_VARS_OFF=	NO_ARCH=yes
SAMPLES_BUILD_DEPENDS=	json-dto>0:devel/json-dto

# many tests fail due to port being in use, see https://github.com/Stiffstream/restinio/issues/223
# 0.7.3: Tests fail to run, see https://github.com/Stiffstream/restinio/issues/230

.include <bsd.port.mk>
