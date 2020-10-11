# $FreeBSD$

PORTNAME=	minizinc
DISTVERSION=	2.5.0
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
GH_TAGNAME=	01854690be366b964df9e25eaf5bd244759c4e76 # develop branch
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS

OPTIONS_DEFINE=		WITH_SCIP

WITH_SCIP_DESC=		Build with the SCIP optimizer
WITH_SCIP_CMAKE_BOOL=	USE_SCIP
WITH_SCIP_LIB_DEPENDS=	libscip.so:math/SCIP/
WITH_SCIP_BROKEN=	Build failure: https://github.com/MiniZinc/libminizinc/issues/402

post-patch:
	${REINPLACE_CMD} -e 's|string std_lib_dir;|string std_lib_dir = "${DATADIR}";|' ${WRKSRC}/mzn2doc.cpp
	${REINPLACE_CMD} -e 's|std_lib_dir(stdlibDir) {}|std_lib_dir(stdlibDir.empty() ? "${DATADIR}" : stdlibDir) {}|' ${WRKSRC}/lib/flattener.cpp

.include <bsd.port.mk>
