PORTNAME=	polymake
DISTVERSION=	4.15
CATEGORIES=	math
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/V${DISTVERSION}/ \
		https://polymake.org/lib/exe/fetch.php/download/
DISTNAME=	${PORTNAME}-${DISTVERSION}-minimal

MAINTAINER=	bsd@philippost.de
COMMENT=	Software package for research in polyhedral geometry
WWW=		https://www.polymake.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

_BR_DEPENDS=	boost-libs>=1.72:devel/boost-libs \
		p5-JSON>=2.97:converters/p5-JSON \
		p5-Term-ReadKey>=2.38:devel/p5-Term-ReadKey \
		p5-Term-ReadLine-Gnu>=1.37:devel/p5-Term-ReadLine-Gnu \
		p5-XML-SAX>=1.02:textproc/p5-XML-SAX \
		p5-XML-Writer>=0.900:textproc/p5-XML-Writer \
		permlib>=0.2.9:math/permlib
BUILD_DEPENDS=	${_BR_DEPENDS} \
		ninja:devel/ninja
LIB_DEPENDS=	libcddgmp.so:math/cddlib \
		libflint.so:math/flint2 \
		libgmpxx.so:math/gmp \
		libmpfr.so:math/mpfr
RUN_DEPENDS=	${_BR_DEPENDS} \
		bash>=5.0:shells/bash

USES=		compiler:c++14-lang gmake gnome perl5 readline shebangfix \
		tar:bzip2
USE_GNOME=	libxml2 libxslt
USE_LDCONFIG=	${PREFIX}/lib
USE_PERL5=	build run

SHEBANG_FILES=	resources/host-agent/bin/env resources/host-agent/bin/polymake
SHEBANG_GLOB=	*.pl *.sh

# polymake's configure script expects options to be disabled by --without-option
# and most options to be enabled by --with-option=DIR
HAS_CONFIGURE=	yes
CONFIGURE_LOG=	build/bundled.log
CONFIGURE_ARGS=	--bindir=${PREFIX}/bin \
		--datadir=${DATADIR} \
		--docdir=${DOCSDIR} \
		--exec-prefix=${PREFIX} \
		--includedir=${PREFIX}/include \
		--libdir=${PREFIX}/lib \
		--libexecdir=${PREFIX}/libexec/polymake \
		--prefix=${PREFIX} \
		--with-cdd=${LOCALBASE} \
		--with-flint=${LOCALBASE} \
		--with-libcxx \
		--with-permlib=${LOCALBASE}/lib \
		--without-java \
		--without-javaview \
		--without-native \
		--without-prereq \
		--without-sympol

# The port uses the minimal distribution tarball without bundled libraries.
# Set WRKSRC accordingly.
WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

# Optional features; SoPlex defaults to off due to licencsing and SCIP defaults
# to off due to a dependency on libsoplex.so.
OPTIONS_DEFINE=		LRS NORMALIZ OPENMP PPL SCIP SINGULAR SOPLEX TESTS
OPTIONS_DEFAULT=	LRS NAUTY NORMALIZ OPENMP PPL SINGULAR
# polymake needs either math/bliss or math/nauty to compute graph automorphism
# groups
OPTIONS_SINGLE=		GRAPH
OPTIONS_SINGLE_GRAPH=	BLISS NAUTY
# Exlude lrslib on i386 and powerpc because it is marked BROKEN for those
# architectures
OPTIONS_EXCLUDE_i386=	LRS
OPTIONS_EXCLUDE_powerpc=	LRS
OPTIONS_SUB=		yes

BLISS_DESC=	Compute graph automorphism groups using bliss
GRAPH_DESC=	Graph automorphism groups
LRS_DESC=	Convex hull computation and vertex enumeration
NAUTY_DESC=	Compute graph automorphism groups using nauty
NORMALIZ_DESC=	Computations in affine monoids and lattice polytopes
PPL_DESC=	Manipulation of convex polyhedra
SCIP_DESC=	Solver for mixed integer linear and nonlinear problems
SINGULAR_DESC=	Computation of Groebner bases
SOPLEX_DESC=	Solver for linear programming problems
TESTS_DESC=	Run bundled self tests after build

BLISS_LIB_DEPENDS=	libbliss.so:math/bliss
BLISS_CONFIGURE_WITH=	bliss=${LOCALBASE}

LRS_LIB_DEPENDS=	liblrs.so:math/lrslib
LRS_CONFIGURE_ON=	--with-lrs-include=${LOCALBASE}/include/lrslib
LRS_CONFIGURE_WITH=	lrs=${LOCALBASE}

NAUTY_LIB_DEPENDS=	libnauty.so:math/nauty
NAUTY_CONFIGURE_WITH=	nauty=${LOCALBASE}

NORMALIZ_LIB_DEPENDS=		libnormaliz.so:math/libnormaliz
NORMALIZ_CONFIGURE_WITH=	libnormaliz=${LOCALBASE}

OPENMP_CONFIGURE_WITH=	openmp

PPL_LIB_DEPENDS=	libppl.so:devel/ppl
PPL_CONFIGURE_WITH=	ppl=${LOCALBASE}

SCIP_LIB_DEPENDS=	libscip.so:math/SCIP
SCIP_CONFIGURE_WITH=	scip=${LOCALBASE}

SINGULAR_LIB_DEPENDS=		libSingular.so:math/singular
SINGULAR_CONFIGURE_WITH=	singular=${LOCALBASE}

SOPLEX_LIB_DEPENDS=	libsoplex-pic.so:math/SoPlex
SOPLEX_CONFIGURE_WITH=	soplex=${LOCALBASE}

TESTS_VARS=	USE_PERL5+=test

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( \
	${OSVERSION} >= 1404501 && ${OSVERSION} < 1500000 || \
	${OSVERSION} >= 1501501 && ${OSVERSION} < 1600000 || \
	${OSVERSION} >= 1600017 )
USES+=		llvm:max=19
.endif

# Deal with site specific installation directory
# polymake installs a perlxs module which depends on the perl configuration
PERL_ARCHNAME=	${:!${PERL} -E 'use Config; print "\$Config::Config{archname}";'!}
PLIST_SUB+=	PERL_ARCHNAME=${PERL_ARCHNAME} \
		PERL_VERSION=${PERL_VERSION} \
		VER=${DISTVERSION} \
		SOVER=${SOVER}

# Keep track of the major version
SOVER=		${DISTVERSION:R}

post-install:
	${RLN} ${STAGEDIR}${PREFIX}/lib/libpolymake.so.${DISTVERSION} \
		${STAGEDIR}${PREFIX}/lib/libpolymake.so.${SOVER}
	${RLN} ${STAGEDIR}${PREFIX}/lib/libpolymake.so.${DISTVERSION} \
		${STAGEDIR}${PREFIX}/lib/libpolymake.so

.for _lp in libpolymake-apps libpolymake-apps-rt
	${RLN} ${STAGEDIR}${PREFIX}/lib/${_lp}.so.${DISTVERSION} \
		${STAGEDIR}${PREFIX}/lib/${_lp}.so.${SOVER}
	${RLN} ${STAGEDIR}${PREFIX}/lib/${_lp}.so.${DISTVERSION} \
		${STAGEDIR}${PREFIX}/lib/${_lp}.so

	${RLN} ${STAGEDIR}${PREFIX}/lib/${_lp}.so.${DISTVERSION} \
		${STAGEDIR}${PREFIX}/libexec/polymake/lib/${_lp}.so.${SOVER}
	${RLN} ${STAGEDIR}${PREFIX}/lib/${_lp}.so.${DISTVERSION} \
		${STAGEDIR}${PREFIX}/libexec/polymake/lib/${_lp}.so

	${RLN} ${STAGEDIR}${PREFIX}/libexec/polymake/lib/${_lp}.so.${DISTVERSION} \
		${STAGEDIR}${PREFIX}/libexec/polymake/lib/${_lp}.so.${SOVER}
	${RLN} ${STAGEDIR}${PREFIX}/libexec/polymake/lib/${_lp}.so.${DISTVERSION} \
		${STAGEDIR}${PREFIX}/libexec/polymake/lib/${_lp}.so
.endfor

# strip the libraries
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libpolymake.so.${DISTVERSION} \
		${STAGEDIR}${PREFIX}/libexec/polymake/lib/libpolymake-*.so.${DISTVERSION} \
		${common fan fulton graph group ideal matroid polytope topaz tropical \
			:L:C|^(.*)$|${STAGEDIR}${PREFIX}/libexec/polymake/lib/\1.so|} \
		${STAGEDIR}${PREFIX}/libexec/polymake/perlx/${PERL_VERSION}/${PERL_ARCHNAME}/auto/Polymake/Ext/Ext.so

post-install-TESTS-on: test

# Set HOME=${WRKDIR} to prevent polymake writing its .polymake directory outside
# WRKDIR. Also tests fail if TERM is not defined.
test:
	@(cd ${WRKSRC} && \
		HOME=${WRKDIR} TERM=vt100 perl/polymake --script run_testcases)

.include <bsd.port.mk>
