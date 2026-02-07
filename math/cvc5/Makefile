PORTNAME=	cvc5
DISTVERSIONPREFIX=	cvc5-
DISTVERSION=	1.3.2
CATEGORIES=	math java
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Automatic theorem prover for SMT (Satisfiability Modulo Theories)
WWW=		https://cvc5.github.io/ \
		https://github.com/cvc5/cvc5

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	bash:shells/bash \
		${LOCALBASE}/lib/symfpu.a:math/symfpu \
		${PYTHON_PKGNAMEPREFIX}toml>0:textproc/py-toml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tomli>0:textproc/py-tomli@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pexpect>0:misc/py-pexpect@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pybind11>0:devel/py-pybind11@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyparsing>0:devel/py-pyparsing@${PY_FLAVOR}
LIB_DEPENDS=	libcadical.so:math/cadical

TEST_ENV=	ARGS=-V

USES=		cmake:testing ncurses compiler:c++17-lang \
		localbase:ldflags pkgconfig python:build
USE_LDCONFIG=	yes
USE_GITHUB=	yes

CMAKE_BUILD_TYPE=	Production
CMAKE_ARGS+=		-DFREEBSD_DISTDIR=${DISTDIR} \
			-DPython_EXECUTABLE:STRING=${PYTHON_CMD}
CMAKE_ON=		BUILD_SHARED_LIBS
CMAKE_OFF=		BUILD_BINDINGS_PYTHON USE_PYTHON3 # Python binding should be a separate port
CMAKE_TESTING_ON=	ENABLE_UNIT_TESTING
CMAKE_TESTING_TARGET=	check # check target runs only quick tests (based on https://github.com/cvc5/cvc5/issues/9569#issuecomment-1484943348)
#CMAKE_TESTING_TARGET=	test # test target also runs longer tests, 2 of which fail, see https://github.com/cvc5/cvc5/issues/9569

PLIST_SUB=		VERSION=${DISTVERSION}

OPTIONS_DEFINE=			COCOALIB EDITLINE GLPK JAVA POLY
OPTIONS_GROUP=			SOLVERS
OPTIONS_GROUP_SOLVERS=		CRYPTOMINISAT KISSAT
OPTIONS_RADIO=			NUMLIB
OPTIONS_RADIO_NUMLIB=		GMP CLN
OPTIONS_DEFAULT=		CRYPTOMINISAT EDITLINE GMP KISSAT # COCOALIB GLPK JAVA POLY are broken
OPTIONS_SUB=			yes

COCOALIB_DESC=			Use CoCoALib for further polynomial operations
COCOALIB_CMAKE_BOOL=		USE_COCOA
COCOALIB_BROKEN=		fails to compile with cocoalib, see https://github.com/cvc5/cvc5/issues/9484

JAVA_CMAKE_BOOL=		BUILD_BINDINGS_JAVA
JAVA_CMAKE_ON=			-DJAVA_INCLUDE_PATH:PATH=${JAVA_HOME}/include \
				-DJAVA_AWT_LIBRARY:PATH=${JAVA_HOME}/jre/lib/${ARCH}/libjawt.so \
				-DJAVA_JVM_LIBRARY:PATH=${JAVA_HOME}/jre/lib/${ATCH}/libjava.so
JAVA_BUILD_DEPENDS=		swig:devel/swig
JAVA_BROKEN=			compilation fails: error: unmappable character for encoding ASCII, see https://github.com/cvc5/cvc5/issues/11145

EDITLINE_DESC=			Use Editline for better interactive support
EDITLINE_CMAKE_BOOL=		USE_EDITLINE
EDITLINE_BUILD_DEPENDS=		libedit>0:devel/libedit
EDITLINE_RUN_DEPENDS=		libedit>0:devel/libedit

POLY_DESC=			Use LibPoly for polynomial arithmetic
POLY_CMAKE_BOOL=		USE_POLY
POLY_LIB_DEPENDS=		libpoly.so:math/libpoly
POLY_BROKEN=		compilation fails with libpoly API mismatch, see poly_conversion.cpp:250

# SOLVERS options

CRYPTOMINISAT_DESC=		Use CryptoMiniSat as the SAT solver
CRYPTOMINISAT_CMAKE_BOOL=	USE_CRYPTOMINISAT
CRYPTOMINISAT_LIB_DEPENDS=	libcryptominisat5.so:math/cryptominisat

GLPK_DESC=			Use GLPK simplex solver
GLPK_CMAKE_BOOL=		USE_GLPK
GLPK_LIB_DEPENDS=		libglpk.so:math/glpk
GLPK_BROKEN=		requires GLPK-cut-log patch, see cmake/deps-utils/glpk-cut-log.patch

KISSAT_DESC=			Use Kissat solver
KISSAT_CMAKE_BOOL=		USE_KISSAT
KISSAT_LIB_DEPENDS=		libkissat.so:math/kissat

# NUMLIB options

GMP_DESC=			Use GMP numeric library
GMP_LIB_DEPENDS=		libgmp.so:math/gmp

CLN_DESC=			Use CLN numeric library
CLN_CMAKE_BOOL=			USE_CLN
CLN_LIB_DEPENDS=		libcln.so:math/cln \
				libgmp.so:math/gmp

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCLN}
LICENSE=		GPLv3
CMAKE_ARGS+=		-DENABLE_GPL:BOOL=ON
.endif

PORTSCOUT=	limit:^[1-9]\.[0-9]+\.[0-9]+ # prevent older generation versions like 1.8, 1.7, etc.

# tests as of 1.3.1: 1 test fails, see https://github.com/cvc5/cvc5/issues/12215
# tests as of 1.3.2: 100% tests passed, 0 tests failed out of 4115, see https://github.com/cvc5/cvc5/issues/12215

.include <bsd.port.mk>
