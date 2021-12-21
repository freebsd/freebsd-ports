PORTNAME=	gismo
DISTVERSIONPREFIX=	v
DISTVERSION=	21.12.0
CATEGORIES=	math # geometry

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ library for isogeometric analysis (IGA)

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cmake:testing compiler:c++14-lang
USE_GITHUB=	yes
USE_GCC=	yes # clang-11 crashes: https://bugs.llvm.org/show_bug.cgi?id=51468
USE_LDCONFIG=	yes

CMAKE_TESTING_ON=	GISMO_BUILD_UNITTESTS # one test is known to fail: https://github.com/gismo/gismo/issues/466

GH_TUPLE=	gismo:gsElasticity:a94347d:gsElasticity/extensions/gsElasticity \
		gismo:gsKLShell:5247352:gsKLShell/extensions/gsKLShell \
		gismo:gsStructuralAnalysis:f18c4b7:gsStructuralAnalysis/extensions/gsStructuralAnalysis \
		gismo:gsUnitTest:7c42e58:gsUnitTest/extensions/gsUnitTest

.include <bsd.port.pre.mk>

.if ${ARCH} == aarch64
CMAKE_ARGS+=	-DTARGET_ARCHITECTURE="cortex-a53"
.endif

.include <bsd.port.post.mk>
