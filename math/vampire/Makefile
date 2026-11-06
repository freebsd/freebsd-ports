PORTNAME=	vampire
DISTVERSIONPREFIX=	v
DISTVERSION=	5.1.0
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Automatic theorem prover
WWW=		https://vprover.github.io/ \
		https://github.com/vprover/vampire

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENCE

BROKEN_armv7=	error: static_assert failed due to requirement 'sizeof(void *) == 8'
BROKEN_i386=	error: static_assert failed due to requirement 'sizeof(void *) == 8'
BROKEN_powerpc=	error: static_assert failed due to requirement 'sizeof(void *) == 8'

LIB_DEPENDS=	libcadical.so:math/cadical \
		libz3.so:math/z3

USES=		cmake compiler:c++17-lang dos2unix

USE_GITHUB=	yes
GH_ACCOUNT=	vprover
GH_TUPLE=	joe-hauns:viras:8b8928f:viras/viras

CMAKE_BUILD_TYPE=	Release
xCMAKE_ARGS=	-DCMAKE_BUILD_HOL=On \
		-DBUILD_TESTING=ON
CMAKE_ARGS=	-DBUILD_TESTING=ON

LDFLAGS+=	-lexecinfo

TEST_TARGET=	test

PLIST_FILES=	bin/${PORTNAME}

PORTSCOUT=	limit:^.*[1-9]\.[1-9].*$$ # prevent tags like sledgehammerScheds

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${PORTNAME}* ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

# tests as of 5.1.0: 100% tests passed, 99 tests passed out of 99, Total Test time (real) = 5.49 sec

.include <bsd.port.mk>
