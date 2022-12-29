PORTNAME=	brynet
DISTVERSIONPREFIX=	v
DISTVERSION=	1.12.2
CATEGORIES=	net devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Header-only cross-platform C++ TCP network library
WWW=		https://github.com/IronsDu/brynet

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing compiler:c++17-lang

USE_GITHUB=	yes
GH_ACCOUNT=	IronsDu

CMAKE_OFF=	brynet_BUILD_EXAMPLES brynet_BUILD_TESTS
CMAKE_TESTING_ON=	brynet_BUILD_TESTS # tests are built but not run, see https://github.com/IronsDu/brynet/issues/130

NO_BUILD=	yes
NO_ARCH=	yes

pre-patch:
	@${FIND} ${WRKSRC} -name "*.hpp" | ${XARGS} ${REINPLACE_CMD} -i '' -e 's/defined BRYNET_PLATFORM_DARWIN/& || defined BRYNET_PLATFORM_FREEBSD/'

.include <bsd.port.mk>
