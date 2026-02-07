PORTNAME=	linbox
PORTVERSION=	1.7.1
DISTVERSIONPREFIX=	v
CATEGORIES=	math

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	C++ library for exact, high-performance linear algebra
WWW=		https://linalg.org/

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	dual

BUILD_DEPENDS=	fflas-ffpack-config:math/fflas-ffpack
LIB_DEPENDS=	libgmp.so:math/gmp		\
		libgivaro.so:math/givaro
RUN_DEPENDS=	bash:shells/bash

USE_GITHUB=	yes
GH_ACCOUNT=	linbox-team

USES=		autoreconf blaslapack:openblas compiler:c++11-lang gmake	\
		libtool localbase pkgconfig shebangfix

SHEBANG_FILES=	benchmarks/perfpublisher.sh linbox-auto-install.sh	\
		linbox-config.in tests/jenkins-maker.sh	\
		tests/perfpublisher.sh tests/test_leak.sh
USE_CXXSTD=	c++14
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

OPTIONS_DEFINE=		DOXYGEN
OPTIONS_RADIO=		SIZE
OPTIONS_RADIO_SIZE=	FULL MIN
OPTIONS_DEFAULT=	FULL
OPTIONS_SUB=		yes

MIN_DESC=		Lightweight package, with less dependencies
MIN_CONFIGURE_ON=	--without-saclib --without-ocl

FULL_DESC=		Complete package with all its dependencies
FULL_BUILD_DEPENDS=	gnuplot:math/gnuplot		\
			opencl>0:devel/opencl
FULL_LIB_DEPENDS=	libflint.so:math/flint2		\
			libfplll.so:math/fplll		\
			libiml.so:math/iml		\
			libmpfr.so:math/mpfr		\
			libntl.so:math/ntl		\
			libOpenCL.so:devel/ocl-icd	\
			libtinyxml2.so:textproc/tinyxml2
FULL_RUN_DEPENDS=	gnuplot:math/gnuplot
FULL_USES=		ghostscript
FULL_CONFIGURE_WITH=	flint fplll ghostscript gnuplot iml mpfr ntl ocl

DOXYGEN_VARS=		BINARY_ALIAS=sed=${LOCALBASE}/bin/gsed
DOXYGEN_CONFIGURE_ENABLE=doc
DOXYGEN_CONFIGURE_WITH=	docdir=${DOCSDIR}
DOXYGEN_BUILD_DEPENDS=	gsed:textproc/gsed	\
			dot:graphics/graphviz	\
			doxygen:devel/doxygen

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

.if defined(PACKAGE_BUILDING)
CONFIGURE_ARGS+=--disable-sse --disable-sse2 --disable-sse3 --disable-ssse3	\
		--disable-sse41 --disable-sse42 --disable-fma --disable-fma4	\
		--disable-avx --disable-avx2
.endif

.include <bsd.port.mk>
