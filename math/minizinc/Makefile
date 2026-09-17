PORTNAME=	minizinc
DISTVERSION=	2.10.1
CATEGORIES=	math lang

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Constraint modeling language
WWW=		https://www.minizinc.org/ \
		https://github.com/MiniZinc

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libCbc.so:math/cbc \
		libCgl.so:math/cgl \
		libchuffed_fzn.so:math/chuffed \
		libCoinUtils.so:math/coinutils \
		libgecodekernel.so:math/gecode \
		libmpfr.so:math/mpfr \
		libOsi.so:math/osi \
		libOsiClp.so:math/clp

USES=		bison cmake compiler:c++11-lang
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	MiniZinc
GH_PROJECT=	libminizinc

CMAKE_ON=	BUILD_SHARED_LIBS

CXXFLAGS+=	-DFREEBSD_MZN_STDLIB_DIR="\\\"${DATADIR}\\\""
CXXFLAGS+=	-I${LOCALBASE}/include/highs # workaround for https://github.com/MiniZinc/libminizinc/issues/744
LDFLAGS+=	-L${LOCALBASE}/lib # workaround for https://github.com/MiniZinc/libminizinc/issues/744

CONFLICTS_BUILD=	CoinMP

.include <bsd.port.mk>
