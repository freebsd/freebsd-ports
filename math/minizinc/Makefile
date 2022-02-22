PORTNAME=	minizinc
DISTVERSION=	2.6.0
CATEGORIES=	math lang

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Constraint modeling language

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

CONFLICTS_BUILD=	CoinMP

LIB_DEPENDS=	libCbc.so:math/cbc \
		libCgl.so:math/cgl \
		libCoinUtils.so:math/coinutils \
		libgecodekernel.so:math/gecode \
		libOsi.so:math/osi \
		libOsiClp.so:math/clp

USES=		bison cmake compiler:c++11-lang
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	MiniZinc
GH_PROJECT=	libminizinc

CMAKE_ON=	BUILD_SHARED_LIBS

CXXFLAGS+=	-DFREEBSD_MZN_STDLIB_DIR="\\\"${DATADIR}\\\""

OPTIONS_DEFINE=		WITH_SCIP

WITH_SCIP_DESC=		Build with the SCIP optimizer
WITH_SCIP_CMAKE_BOOL=	USE_SCIP
WITH_SCIP_LIB_DEPENDS=	libscip.so:math/SCIP/

post-patch:
	${REINPLACE_CMD} -e 's|string std_lib_dir;|string std_lib_dir = "${DATADIR}";|' ${WRKSRC}/mzn2doc.cpp

.include <bsd.port.mk>
