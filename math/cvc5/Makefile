PORTNAME=	cvc5
DISTVERSIONPREFIX=	cvc5-
DISTVERSION=	1.0.5
PORTREVISION=	2
CATEGORIES=	math java
MASTER_SITES+=	http://www.antlr3.org/download/:antlr3
DISTFILES+=	antlr-3.4-complete.jar:antlr3
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Automatic theorem prover for SMT (Satisfiability Modulo Theories)
WWW=		https://cvc5.github.io/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	bash:shells/bash \
		${LOCALBASE}/lib/libcadical.a:math/cadical \
		${LOCALBASE}/lib/symfpu.a:math/symfpu \
		${PYTHON_PKGNAMEPREFIX}toml>0:textproc/py-toml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyparsing>0:devel/py-pyparsing@${PY_FLAVOR}
LIB_DEPENDS=	libantlr3c.so:devel/libantlr3c \
		libboost_system.so:devel/boost-libs

USES=		cmake:testing ncurses compiler:c++17-lang \
		localbase:ldflags pkgconfig python:build
USE_LDCONFIG=	yes
USE_GITHUB=	yes

USE_JAVA=	yes
JAVA_BUILD=	yes

CMAKE_BUILD_TYPE=	Production
CMAKE_ARGS+=		-DANTLR_BINARY=${WRKDIR}/antlr3 \
			-DFREEBSD_DISTDIR=${DISTDIR} \
			-DPython_EXECUTABLE:STRING=${PYTHON_CMD}
CMAKE_ON=		BUILD_SHARED_LIBS
CMAKE_OFF=		BUILD_BINDINGS_PYTHON USE_PYTHON3 # Python binding should be a separate port
CMAKE_TESTING_ON=	ENABLE_UNIT_TESTING
CMAKE_TESTING_TARGET=	check # check target runs only quick tests (based on https://github.com/cvc5/cvc5/issues/9569#issuecomment-1484943348)
#CMAKE_TESTING_TARGET=	test # test target also runs longer tests, 2 of which fail, see https://github.com/cvc5/cvc5/issues/9569

OPTIONS_DEFINE=			COCOALIB EDITLINE JAVA
OPTIONS_GROUP=			SOLVERS
OPTIONS_GROUP_SOLVERS=		CRYPTOMINISAT KISSAT
OPTIONS_RADIO=			NUMLIB
OPTIONS_RADIO_NUMLIB=		GMP CLN
OPTIONS_DEFAULT=		CRYPTOMINISAT EDITLINE JAVA GMP # COCOALIB KISSAT
OPTIONS_SUB=			yes

COCOALIB_DESC=			Use CoCoALib for further polynomial operations
COCOALIB_CMAKE_BOOL=		USE_COCOA
COCOALIB_BROKEN=		fails to compile with cocoalib, see https://github.com/cvc5/cvc5/issues/9484

JAVA_CMAKE_BOOL=		BUILD_BINDINGS_JAVA
JAVA_CMAKE_ON=			-DJAVA_INCLUDE_PATH:PATH=${JAVA_HOME}/include \
				-DJAVA_AWT_LIBRARY:PATH=${JAVA_HOME}/jre/lib/${ARCH}/libjawt.so \
				-DJAVA_JVM_LIBRARY:PATH=${JAVA_HOME}/jre/lib/${ATCH}/libjava.so
JAVA_BUILD_DEPENDS=		swig:devel/swig

EDITLINE_DESC=			Use Editline for better interactive support
EDITLINE_CMAKE_BOOL=		USE_EDITLINE
EDITLINE_BUILD_DEPENDS=		libedit>0:devel/libedit
EDITLINE_RUN_DEPENDS=		libedit>0:devel/libedit

# SOLVERS options

CRYPTOMINISAT_DESC=		Use CryptoMiniSat as the SAT solver
CRYPTOMINISAT_CMAKE_BOOL=	USE_CRYPTOMINISAT
CRYPTOMINISAT_LIB_DEPENDS=	libcryptominisat5.so:math/cryptominisat

KISSAT_DESC=			Use Kissat solver
KISSAT_CMAKE_BOOL=		USE_KISSAT
KISSAT_BROKEN=			fails to link with libkissat.so, see https://github.com/cvc5/cvc5/issues/9483

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

PORTSCOUT=	limit:^cvc5-[1-9].* # prevent older generation versions like 1.8

post-extract:
	@${CP} ${DISTDIR}/antlr-3.4-complete.jar ${WRKDIR}/antlr3.jar
	@${ECHO_CMD} "#!/bin/sh" > ${WRKDIR}/antlr3
	@${ECHO_CMD} "exec \"${LOCALBASE}/bin/java\" -classpath \"${WRKDIR}/antlr3.jar\" org.antlr.Tool \"\$$@\"" >> ${WRKDIR}/antlr3
	@${CHMOD} +x ${WRKDIR}/antlr3

xpost-patch:
	@${REINPLACE_CMD} -e "s|sed -i'' -e 's|sed -i '' -e 's|g" \
		${WRKSRC}/src/fix-install-headers.sh

.include <bsd.port.mk>
