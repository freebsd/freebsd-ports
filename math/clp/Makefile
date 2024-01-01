PORTNAME=	Clp
DISTVERSIONPREFIX=	releases/
DISTVERSION=	1.17.9
PORTREVISION=	1
CATEGORIES=	math
PKGNAMEPREFIX=	coin-or-

MAINTAINER=	co9co9@gmail.com
COMMENT=	Linear Programming Solver
WWW=		https://www.coin-or.org/Clp/index.html

LICENSE=	EPL

BUILD_DEPENDS=	coin-or-Data-Sample>0:math/coin-or-data-sample \
		coin-or-Data-Netlib>0:math/coin-or-data-netlib
LIB_DEPENDS=	libcoinasl.so:math/asl \
		libcoinmetis.so:math/coin-or-metis \
		libcoinmumps.so:math/coin-or-mumps \
		libCoinUtils.so:math/coinutils \
		libOsi.so:math/osi
RUN_DEPENDS=	coin-or-Data-Sample>0:math/coin-or-data-sample \
		coin-or-Data-Netlib>0:math/coin-or-data-netlib

USES=		blaslapack compiler:c++11-lang fortran libtool pathfix pkgconfig tar:tgz
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	coin-or

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

CONFIGURE_ARGS=	--with-lapack-lib="${LAPACKLIB} -L${LOCALBASE}/lib" \
		--with-blas-lib="${BLASLIB} -L${LOCALBASE}/lib" \
		--with-osi-incdir="${LOCALBASE}/include/coin" --with-osi-lib="${LOCALBASE}/lib/libOsi.so" \
		--with-coinutils-incdir="${LOCALBASE}/include/coin" --with-coinutils-lib="${LOCALBASE}/lib/libCoinUtils.so" \
		--with-netlib-datadir="${LOCALBASE}/share/coin/Data/Netlib" \
		--with-sample-datadir="${LOCALBASE}/share/coin/Data/Sample" \
		--datadir=${DATADIR}

TEST_TARGET=	unitTest
TEST_WRKSRC=	${WRKSRC}/${PORTNAME}

OPTIONS_DEFINE=	DEBUG DOCS
PORTDOCS=	*

CXXFLAGS+=	-ffast-math
DEBUG_CXXFLAGS=	-fomit-frame-pointer

.include <bsd.port.mk>
