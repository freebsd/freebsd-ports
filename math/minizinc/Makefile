# $FreeBSD$

PORTNAME=	minizinc
DISTVERSION=	2.5.2
CATEGORIES=	math lang

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Constraint modeling language

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libCbc.so:math/cbc \
		libCgl.so:math/cgl \
		libgecodekernel.so:devel/gecode \
		libOsiClp.so:math/clp

USES=		bison cmake compiler:c++11-lang
USE_GITHUB=	yes
GH_ACCOUNT=	MiniZinc
GH_PROJECT=	libminizinc
USE_LDCONFIG=	yes

CXXFLAGS+=	-DFREEBSD_MZN_STDLIB_DIR="\\\"${DATADIR}\\\""

CMAKE_ON=	BUILD_SHARED_LIBS

OPTIONS_DEFINE=		WITH_SCIP

WITH_SCIP_DESC=		Build with the SCIP optimizer
WITH_SCIP_CMAKE_BOOL=	USE_SCIP
WITH_SCIP_LIB_DEPENDS=	libscip.so:math/SCIP/

post-patch:
	${REINPLACE_CMD} -e 's|string std_lib_dir;|string std_lib_dir = "${DATADIR}";|' ${WRKSRC}/mzn2doc.cpp

.include <bsd.port.mk>
