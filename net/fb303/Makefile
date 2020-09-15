# $FreeBSD$

PORTNAME=	fb303
DISTVERSION=	g20200915
CATEGORIES=	net

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Base Thrift service and a common set of functionality

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libboost_regex.so:devel/boost-libs \
		libfizz.so:security/fizz \
		libfmt.so:devel/libfmt \
		libfolly.so:devel/folly \
		libgflags.so:devel/gflags \
		libglog.so:devel/glog \
		libthriftcpp2.so:devel/fbthrift \
		libwangle.so:net/wangle

USES=		cmake compiler:c++17-lang
USE_GITHUB=	yes
GH_ACCOUNT=	facebook
GH_TAGNAME=	ec43a43
USE_LDCONFIG=	yes

CXXFLAGS+=	-fPIC

CMAKE_ON=	BUILD_SHARED_LIBS

post-install:
	@${RMDIR} ${STAGEDIR}${PREFIX}/include/fb303/test

.include <bsd.port.mk>
