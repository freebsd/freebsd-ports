PORTNAME=	Ipopt
DISTVERSIONPREFIX=	releases/
DISTVERSION=	3.14.19
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Software package for large-scale nonlinear optimization
WWW=		https://coin-or.github.io/Ipopt/ \
		https://github.com/coin-or/Ipopt

LICENSE=	EPL

LIB_DEPENDS=	libcoinasl.so:math/asl \
		libcoinmumps.so:math/coin-or-mumps
TEST_DEPENDS=	bash:shells/bash

USES=		blaslapack compiler:c++11-lang fortran libtool pathfix \
		pkgconfig shebangfix
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	coin-or

SHEBANG_FILES=	test/run_unitTests.in

INSTALL_TARGET=	install-strip
TEST_TARGET=	test

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	PKG_CONFIG_PATH=${PREFIX}/libdata/pkgconfig \
		CXX="${CXX} -B${LOCALBASE}/bin"
CONFIGURE_ARGS=	--with-lapack-lib="${LAPACKLIB} -L${LOCALBASE}/lib"	\
		--with-blas-lib="${BLASLIB} -L${LOCALBASE}/lib" \
		--disable-java

CXXFLAGS+=	-ffast-math
DEBUG_CXXFLAGS=	-fomit-frame-pointer

DOCSDIR=	${PREFIX}/share/coin/doc/${PORTNAME}

OPTIONS_DEFINE=		DEBUG

CONFLICTS_BUILD=	coin-or-hsl # coin-or-hsl doesn't contain required by Ipopt code

.include <bsd.port.pre.mk>

.if ${GCC_DEFAULT} >= 10
# workaround for Rank mismatch between actual argument at (1) and actual argument at (2) (scalar and rank-1)
FFLAGS+=	-fallow-argument-mismatch
.endif

.include <bsd.port.post.mk>
