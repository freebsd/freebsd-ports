# $FreeBSD$

PORTNAME=	wangle
DISTVERSIONPREFIX=	v
DISTVERSION=	2021.03.08.00
CATEGORIES=	net

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Framework for building services in a consistent/modular/composable way

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/../LICENSE

LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libdouble-conversion.so:devel/double-conversion \
		libevent.so:devel/libevent \
		libfizz.so:security/fizz \
		libfolly.so:devel/folly \
		libgflags.so:devel/gflags \
		libfmt.so:devel/libfmt \
		libglog.so:devel/glog \
		libsodium.so:security/libsodium

USES=		cmake compiler:c++17-lang ssl
USE_GITHUB=	yes
GH_ACCOUNT=	facebook
USE_LDCONFIG=	yes

WRKSRC_SUBDIR=	${PORTNAME}

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	BUILD_TESTS

post-install: # https://github.com/facebook/wangle/issues/179
	cd ${STAGEDIR}${PREFIX} && \
		${RMDIR} \
			include/wangle/service/test \
			include/wangle/ssl/test/certs \
			include/wangle/util/test

.include <bsd.port.mk>
