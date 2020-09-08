# $FreeBSD$

PORTNAME=	mvfst
DISTVERSION=	g20200805
CATEGORIES=	net

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Implementation of the QUIC transport protocol

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libfizz.so:security/fizz \
		libfmt.so:devel/libfmt \
		libfolly.so:devel/folly \
		libglog.so:devel/glog

USES=		cmake compiler:c++17-lang
USE_GITHUB=	yes
GH_ACCOUNT=	facebookincubator
GH_TAGNAME=	a5619effd613fb9f42f87d3f98429d52288d4bfa
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	BUILD_TESTS

CXXFLAGS+=	-fPIC

.include <bsd.port.mk>
