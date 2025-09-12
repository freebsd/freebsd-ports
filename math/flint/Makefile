PORTNAME=	flint
DISTVERSION=	3.3.1
CATEGORIES=	math
MASTER_SITES=	http://www.flintlib.org/download/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fast library for number theory
WWW=		https://flintlib.org \
		https://github.com/flintlib/flint

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgmp.so:math/gmp \
		libmpfr.so:math/mpfr \
		libopenblas.so:math/openblas

USES=		compiler:c++11-lang gmake localbase pkgconfig python:build # cmake is only intended for Widows, see https://github.com/flintlib/flint/issues/2251#issuecomment-2720292171
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

.if !defined(WITH_DEBUG)
CONFIGURE_ARGS=	--disable-debug
.endif

TEST_TARGET=	check

OPTIONS_DEFINE=			NTL
OPTIONS_GROUP=			OPTIMIZATIONS
OPTIONS_GROUP_OPTIMIZATIONS=	AVX2 AVX512
OPTIONS_DEFAULT=		NTL

AVX2_DESC=			Enable AVX2 instructions
AVX2_CONFIGURE_ENABLE=		avx2

AVX512_DESC=			Enable AVX512 instructions
AVX512_CONFIGURE_ENABLE=	avx512

NTL_DESC=			Victor Shoup's Number Theory Library
NTL_CONFIGURE_WITH=		ntl
NTL_LIB_DEPENDS=		libntl.so:math/ntl

MAKE_ENV+=	VERBOSE=1
MAKE_ARGS+=	VERBOSE=1

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libflint.so.21.0.0

# tests as of 3.3.1: All tests passed.

.include <bsd.port.mk>
