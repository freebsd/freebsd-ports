PORTNAME=	Ipopt
DISTVERSIONPREFIX=	releases/
DISTVERSION=	3.14.9
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Software package for large-scale nonlinear optimization

LICENSE=	EPL

LIB_DEPENDS=	libcoinasl.so:math/asl \
		libcoinmetis.so:math/coin-or-metis \
		libcoinmumps.so:math/coin-or-mumps

USES=		blaslapack compiler:c++11-lang fortran libtool pathfix \
		pkgconfig
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	coin-or

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
