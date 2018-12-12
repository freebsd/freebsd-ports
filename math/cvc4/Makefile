# $FreeBSD$

PORTNAME=	cvc4
DISTVERSION=	1.6
PORTREVISION=	2
CATEGORIES=	math java
MASTER_SITES=	https://cvc4.cs.stanford.edu/downloads/builds/src/

MAINTAINER=	greg@unrelenting.technology
COMMENT=	Automatic theorem prover for SMT (Satisfiability Modulo Theories)

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libantlr3c.so:devel/libantlr3c \
		libboost_system.so:devel/boost-libs
BUILD_DEPENDS=	bash:shells/bash \
		antlr3:devel/antlr3

USES=		autoreconf gmake python:3.5+,build libtool localbase pkgconfig shebangfix
USE_JAVA=	yes
JAVA_BUILD=	yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-dependency-tracking \
			--with-swig=${LOCALBASE}/bin/swig3.0 \
			ANTLR=${LOCALBASE}/bin/antlr3
CONFIGURE_SHELL=	${LOCALBASE}/bin/bash
USE_LDCONFIG=		yes
SHEBANG_FILES=		src/mk* src/theory/mk* src/base/mk* src/expr/mk* src/options/mk* test/regress/run_regression.py

OPTIONS_DEFINE=		CRYPTOMINISAT JAVA READLINE DEBUG
OPTIONS_RADIO=		NUMLIB
OPTIONS_RADIO_NUMLIB=	GMP CLN
OPTIONS_DEFAULT=	CRYPTOMINISAT READLINE GMP
OPTIONS_SUB=		yes

CRYPTOMINISAT_DESC=	Use CryptoMiniSat as the SAT solver
GMP_DESC=		Use GMP numeric library
CLN_DESC=		Use CLN numeric library (disables portfolio mode)

CRYPTOMINISAT_CONFIGURE_ON=	--with-cryptominisat --with-cryptominisat-dir=${LOCALBASE}
CRYPTOMINISAT_LIB_DEPENDS=	libcryptominisat5.so:math/cryptominisat

JAVA_CONFIGURE_ON=		--enable-language-bindings=c,c++,java \
				JAVA_CPPFLAGS="-I${JAVA_HOME}/include -I${JAVA_HOME}/include/freebsd" \
				JAVAC=${JAVAC} JAVAH=${JAVAH} JAR=${JAR}
JAVA_CONFIGURE_OFF=		--enable-language-bindings=c,c++
JAVA_BUILD_DEPENDS=		swig3.0:devel/swig30

READLINE_CONFIGURE_WITH=	readline
READLINE_USES=			readline

GMP_CONFIGURE_WITH=		gmp
GMP_CONFIGURE_ON=		--with-portfolio
GMP_LIB_DEPENDS=		libgmp.so:math/gmp \
				libboost_thread.so:devel/boost-libs
# note: CVC4 already depends on boost-libs, so portfolio mode is "free" in terms of pkg dependencies

CLN_CONFIGURE_WITH=		cln
CLN_LIB_DEPENDS=		libcln.so:math/cln \
				libgmp.so:math/gmp

DEBUG_CONFIGURE_ON=		--with-build=debug
DEBUG_CONFIGURE_OFF=		--with-build=production
DEBUG_INSTALL_TARGET_OFF=	install-strip

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MREADLINE} || ${PORT_OPTIONS:MCLN}
LICENSE=		GPLv3
CONFIGURE_ARGS+=	--enable-gpl
.endif

# use the fixed compiler version from ports to prevent failures on FreeBSD_10
LLVM_VERSION=	60
BUILD_DEPENDS+=	clang${LLVM_VERSION}:devel/llvm${LLVM_VERSION}
CC=	clang${LLVM_VERSION}
CXX=	clang++${LLVM_VERSION}

.include <bsd.port.mk>
