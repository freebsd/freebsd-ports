PORTNAME=	bitwuzla # successor of Boolector
DISTVERSION=	0.8.2
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	SMT solver for the theories of fixed-size bit-vectors
WWW=		https://bitwuzla.github.io/ \
		https://github.com/bitwuzla/bitwuzla

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gmp>0:math/gmp \
		${LOCALBASE}/lib/symfpu.a:math/symfpu
LIB_DEPENDS=	libcadical.so:math/cadical \
		libcryptominisat5.so:math/cryptominisat \
		libgmp.so:math/gmp
TEST_DEPENDS=	googletest>0:devel/googletest

USES=		compiler:c++17-lang localbase:ldflags meson pkgconfig python:build
USE_GITHUB=	yes
USE_LDCONFIG=	yes

CFLAGS+=	-I${LOCALBASE}/include/cadical
CXXFLAGS+=	-I${LOCALBASE}/include/cadical
LDFLAGS+=	-lcadical

MESON_ARGS=	-Ddefault_library=shared \
		-Dtesting=disabled

BINARY_ALIAS=	git=false

do-test: # 1 test hangs, see https://github.com/bitwuzla/bitwuzla/issues/117
	@cd ${WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CONFIGURE_CMD} ${CONFIGURE_ARGS} -Dtesting=enabled && \
		cd ${BUILD_WRKSRC} && \
		${DO_MAKE_BUILD} test

# tests as of 0.8.2:
# Ok:                 3935
# Expected Fail:      0
# Fail:               0
# Unexpected Pass:    0
# Skipped:            0
# Timeout:            0

.include <bsd.port.mk>
