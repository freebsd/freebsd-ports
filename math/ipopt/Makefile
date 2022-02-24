# Created by: Pedro Giffuni

PORTNAME=	Ipopt
DISTVERSION=	3.14.4
CATEGORIES=	math
MASTER_SITES=	https://www.coin-or.org/download/source/${PORTNAME}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Software package for large-scale nonlinear optimization

LICENSE=	EPL

LIB_DEPENDS=	libcoinasl.so:math/asl \
		libcoinmetis.so:math/coin-or-metis \
		libcoinmumps.so:math/coin-or-mumps

USES=		blaslapack compiler:c++11-lang fortran libtool pathfix \
		pkgconfig
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
TEST_TARGET=	test
INSTALL_TARGET=	install-strip

CONFIGURE_ENV+=	PKG_CONFIG_PATH=${PREFIX}/libdata/pkgconfig \
		CXX="${CXX} -B${LOCALBASE}/bin"
CONFIGURE_ARGS=	--with-lapack-lib="${LAPACKLIB} -L${LOCALBASE}/lib"	\
		--with-blas-lib="${BLASLIB} -L${LOCALBASE}/lib"

CXXFLAGS+=	-ffast-math
DEBUG_CXXFLAGS=	-fomit-frame-pointer

WRKSRC=		${WRKDIR}/${PORTNAME}-releases-${PORTVERSION}
DOCSDIR=	${PREFIX}/share/coin/doc/${PORTNAME}

OPTIONS_DEFINE=		DEBUG

CONFLICTS_BUILD=	coin-or-hsl # coin-or-hsl doesn't contain required by Ipopt code

.include <bsd.port.pre.mk>

.if ${GCC_DEFAULT} >= 10
# workaround for Rank mismatch between actual argument at (1) and actual argument at (2) (scalar and rank-1)
FFLAGS+=	-fallow-argument-mismatch
.endif

.include <bsd.port.post.mk>
