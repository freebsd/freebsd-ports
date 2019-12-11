# $FreeBSD$

PORTNAME=	cvc4
DISTVERSION=	1.7
PORTREVISION=	3
CATEGORIES=	math java
MASTER_SITES+=	http://www.antlr3.org/download/:antlr3
DISTFILES+=	antlr-3.4-complete.jar:antlr3
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	fc8907afc08d.patch:-p1 # Install Java bindings

MAINTAINER=	greg@unrelenting.technology
COMMENT=	Automatic theorem prover for SMT (Satisfiability Modulo Theories)

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libantlr3c.so:devel/libantlr3c \
		libboost_system.so:devel/boost-libs

USES=		cmake ncurses compiler:c++17-lang \
		pkgconfig python:3.5+,build shebangfix

SHEBANG_FILES=	src/base/mktagheaders \
		src/base/mktags

USE_GITHUB=	yes
GH_ACCOUNT=	CVC4
GH_PROJECT=	CVC4

USE_JAVA=	yes
JAVA_BUILD=	yes

USE_LDCONFIG=		yes

CMAKE_BUILD_TYPE=	Production
CMAKE_ARGS+=		-DANTLR_BINARY=${WRKDIR}/antlr3

OPTIONS_DEFINE=		CRYPTOMINISAT JAVA PYTHON READLINE
OPTIONS_RADIO=		NUMLIB
OPTIONS_RADIO_NUMLIB=	GMP CLN
OPTIONS_DEFAULT=	CRYPTOMINISAT JAVA PYTHON READLINE GMP
OPTIONS_SUB=		yes

CRYPTOMINISAT_DESC=	Use CryptoMiniSat as the SAT solver
GMP_DESC=		Use GMP numeric library
CLN_DESC=		Use CLN numeric library (disables portfolio mode)

CRYPTOMINISAT_CMAKE_BOOL=	USE_CRYPTOMINISAT
CRYPTOMINISAT_LIB_DEPENDS=	libcryptominisat5.so:math/cryptominisat

JAVA_CMAKE_BOOL=	BUILD_BINDINGS_JAVA
JAVA_CMAKE_ON=		-DJAVA_INCLUDE_PATH:PATH=${JAVA_HOME}/include \
			-DJAVA_AWT_LIBRARY:PATH=${JAVA_HOME}/jre/lib/${ARCH}/libjawt.so \
			-DJAVA_JVM_LIBRARY:PATH=${JAVA_HOME}/jre/lib/${ATCH}/libjava.so
JAVA_BUILD_DEPENDS=	swig3.0:devel/swig30

PYTHON_CMAKE_BOOL=	BUILD_BINDINGS_PYTHON USE_PYTHON3
PYTHON_BUILD_DEPENDS=	swig3.0:devel/swig30

READLINE_CMAKE_BOOL=	USE_READLINE
READLINE_USES=		readline:port

GMP_CMAKE_BOOL=		ENABLE_PORTFOLIO
GMP_CMAKE_ON=		-DENABLE_DUMPING=OFF
GMP_LIB_DEPENDS=	libgmp.so:math/gmp \
			libboost_thread.so:devel/boost-libs
# note: CVC4 already depends on boost-libs, so portfolio mode is "free" in terms of pkg dependencies

CLN_CMAKE_BOOL=		USE_CLN
CLN_LIB_DEPENDS=	libcln.so:math/cln \
			libgmp.so:math/gmp

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MREADLINE} || ${PORT_OPTIONS:MCLN}
LICENSE=		GPLv3
CMAKE_ARGS+=		-DENABLE_GPL:BOOL=ON
.endif

post-extract:
	@${CP} ${DISTDIR}/antlr-3.4-complete.jar ${WRKDIR}/antlr3.jar
	@${ECHO_CMD} "#!/bin/sh" > ${WRKDIR}/antlr3
	@${ECHO_CMD} "exec \"${LOCALBASE}/bin/java\" -classpath \"${WRKDIR}/antlr3.jar\" org.antlr.Tool \"\$$@\"" >> ${WRKDIR}/antlr3
	@${CHMOD} +x ${WRKDIR}/antlr3

post-patch:
	@${REINPLACE_CMD} -e "s|sed -i 's|sed -i '' 's|g" \
	${WRKSRC}/src/fix-install-headers.sh

# make a relative symlink instead of absolute to build dir
post-install-JAVA-on:
	@${LN} -sf CVC4-1.7.0.jar ${STAGEDIR}${PREFIX}/share/java/cvc4/CVC4.jar

.include <bsd.port.mk>
