PORTNAME=	permlib
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.9
PORTREVISION=	1
CATEGORIES=	math

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	c2c0ae7e078df6c91c16c7326081c483700fde75.patch:-p1 # backport https://github.com/tremlin/PermLib/pull/8

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ header-only library for permutation computations

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	boost-libs>0:devel/boost-libs
RUN_DEPENDS=	boost-libs>0:devel/boost-libs

USES=		cmake:testing

USE_GITHUB=	yes
GH_ACCOUNT=	tremlin
GH_PROJECT=	PermLib

CMAKE_TESTING_ON=	BUILD_TESTS # tests are broken, see https://github.com/tremlin/PermLib/issues/7

NO_BUILD=	yes
NO_ARCH=	yes

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} include ${STAGEDIR}${PREFIX}
	${FIND} ${STAGEDIR}${PREFIX}/include -name "*.orig" -delete

.include <bsd.port.mk>
