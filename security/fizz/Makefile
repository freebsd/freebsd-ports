# $FreeBSD$

PORTNAME=	fizz
DISTVERSIONPREFIX=	v
DISTVERSION=	2020.06.08.00
CATEGORIES=	security

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++14 implementation of the TLS-1.3 standard

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/../LICENSE

LIB_DEPENDS=	libdouble-conversion.so:devel/double-conversion \
		libfmt.so:devel/libfmt \
		libfolly.so:devel/folly \
		libgflags.so:devel/gflags \
		libglog.so:devel/glog \
		libsodium.so:security/libsodium

USES=		cmake compiler:c++14-lang ssl
USE_GITHUB=	yes
GH_ACCOUNT=	facebookincubator
USE_LDCONFIG=	yes

WRKSRC_SUBDIR=	${PORTNAME}

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	BUILD_TESTS BUILD_EXAMPLES

.include <bsd.port.mk>
