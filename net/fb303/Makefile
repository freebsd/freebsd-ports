PORTNAME=	fb303
DISTVERSIONPREFIX=	v
DISTVERSION=	2025.07.07.00
CATEGORIES=	net

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Base Thrift service and a common set of functionality
WWW=		https://github.com/facebook/fb303

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libboost_regex.so:devel/boost-libs \
		libbzip2.so:misc/vxl \
		libdouble-conversion.so:devel/double-conversion \
		libevent.so:devel/libevent \
		libfizz.so:security/fizz \
		libfmt.so:devel/libfmt \
		libfolly.so:devel/folly \
		libgflags.so:devel/gflags \
		libglog.so:devel/glog \
		libicuuc.so:devel/icu \
		liblz4.so:archivers/liblz4 \
		libmvfst_server.so:net/mvfst \
		libsnappy.so:archivers/snappy \
		libsodium.so:security/libsodium \
		libthriftcpp2.so:devel/fbthrift \
		libunwind.so:devel/libunwind \
		libwangle.so:net/wangle \
		libzstd.so:archivers/zstd

USES=		cmake compiler:c++17-lang ssl
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	facebook

CXXFLAGS+=	-fPIC
CXXFLAGS+=	-DGLOG_USE_GLOG_EXPORT

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	PYTHON_EXTENSIONS

post-install:
	@${RMDIR} \
		${STAGEDIR}${PREFIX}/include/fb303/test

.include <bsd.port.mk>
