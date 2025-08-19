PORTNAME=	wangle
DISTVERSIONPREFIX=	v
DISTVERSION=	2025.08.18.00
CATEGORIES=	net

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Framework for building services in a consistent/modular/composable way
WWW=		https://github.com/facebook/wangle

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/../LICENSE

LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libdouble-conversion.so:devel/double-conversion \
		libevent.so:devel/libevent \
		libfizz.so:security/fizz \
		libfmt.so:devel/libfmt \
		libfolly.so:devel/folly \
		libgflags.so:devel/gflags \
		libglog.so:devel/glog \
		libicui18n.so:devel/icu \
		liblz4.so:archivers/liblz4 \
		libunwind.so:devel/libunwind \
		libsnappy.so:archivers/snappy \
		libsodium.so:security/libsodium \
		libzstd.so:archivers/zstd

USES=		cmake compiler:c++17-lang cpe ssl
USE_GITHUB=	yes
GH_ACCOUNT=	facebook
USE_LDCONFIG=	yes
CPE_VENDOR=	facebook

WRKSRC_SUBDIR=	${PORTNAME}

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	BUILD_TESTS
CXXFLAGS+=	-DGLOG_USE_GLOG_EXPORT

post-install: # https://github.com/facebook/wangle/issues/179
	cd ${STAGEDIR}${PREFIX} && \
		${RMDIR} \
			include/wangle/service/test \
			include/wangle/ssl/test/certs \
			include/wangle/util/test

.include <bsd.port.mk>
