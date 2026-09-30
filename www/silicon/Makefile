PORTNAME=	silicon
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1-124
DISTVERSIONSUFFIX=	-g91ca205
CATEGORIES=	www devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	High performance, middleware oriented C++14 http web framework
WWW=		http://siliconframework.org/ \
		https://github.com/matt-42/silicon

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	matt-42

NO_ARCH=	yes

CMAKE_ARGS=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5 # CMake 4.5 compatibility, see https://github.com/matt-42/silicon/issues/73

.include <bsd.port.mk>
