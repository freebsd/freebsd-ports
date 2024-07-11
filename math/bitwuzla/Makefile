PORTNAME=	bitwuzla
DISTVERSION=	0.5.0
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	SMT solver for the theories of fixed-size bit-vectors
WWW=		https://bitwuzla.github.io/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gmp>0:math/gmp \
		${LOCALBASE}/lib/symfpu.a:math/symfpu
LIB_DEPENDS=	libcadical.so:math/cadical \
		libgmp.so:math/gmp
TEST_DEPENDS=	googletest>0:devel/googletest

USES=		compiler:c++17-lang localbase:ldflags meson pkgconfig python:build
USE_GITHUB=	yes
USE_LDCONFIG=	yes

LDFLAGS+=	-lcadical

MESON_ARGS=	-Ddefault_library=shared \
		-Dtesting=disabled

do-test: # 1 test hangs, see https://github.com/bitwuzla/bitwuzla/issues/117
	@cd ${WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CONFIGURE_CMD} ${CONFIGURE_ARGS} -Dtesting=enabled && \
		cd ${BUILD_WRKSRC} && \
		${DO_MAKE_BUILD} test

.include <bsd.port.mk>
