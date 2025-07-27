PORTNAME=	polymake
DISTVERSION=	4.13
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/V${DISTVERSION}/ \
		https://polymake.org/lib/exe/fetch.php/download/
DISTNAME=	${PORTNAME}-${DISTVERSION}-minimal

MAINTAINER=	bsd@philippost.de
COMMENT=	Software package for research in polyhedral geometry
WWW=		https://www.polymake.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	boost-libs>=1.72:devel/boost-libs \
		ninja:devel/ninja \
		permlib>=0.2.9:math/permlib \
		p5-XML-SAX>=1.02:textproc/p5-XML-SAX \
		p5-XML-Writer>=0.900:textproc/p5-XML-Writer \
		p5-Term-ReadLine-Gnu>=1.37:devel/p5-Term-ReadLine-Gnu \
		p5-Term-ReadKey>=2.38:devel/p5-Term-ReadKey \
		p5-JSON>=2.97:converters/p5-JSON
LIB_DEPENDS=	libcddgmp.so:math/cddlib \
		libflint.so:math/flint2 \
		libgmpxx.so:math/gmp \
		libmpfr.so:math/mpfr
RUN_DEPENDS=	bash>=5.0:shells/bash \
		boost-libs>=1.72:devel/boost-libs \
		permlib>=0.2.9:math/permlib \
		p5-XML-SAX>=1.02:textproc/p5-XML-SAX \
		p5-XML-Writer>=0.900:textproc/p5-XML-Writer \
		p5-Term-ReadLine-Gnu>=1.37:devel/p5-Term-ReadLine-Gnu \
		p5-Term-ReadKey>=2.38:devel/p5-Term-ReadKey \
		p5-JSON>=2.97:converters/p5-JSON

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
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--exec-prefix=${PREFIX} \
		--bindir=${PREFIX}/bin \
		--includedir=${PREFIX}/include \
		--libdir=${PREFIX}/lib \
		--libexecdir=${PREFIX}/libexec/polymake \
		--datadir=${PREFIX}/share/polymake \
		--docdir=${DOCSDIR} \
		--without-prereq \
		--with-libcxx \
		--with-cdd=${LOCALBASE} \
		--with-flint=${LOCALBASE} \
		--with-permlib=${LOCALBASE}/lib \
		--without-java \
		--without-javaview \
		--without-native \
		--without-sympol
CONFIGURE_LOG=	build/bundled.log

# Optional features; SoPlex defaults to off due to licencsing and SCIP defaults
# to off due to a dependency on libsoplex.so.
OPTIONS_DEFINE=	LRS NORMALIZ OPENMP OPTIMIZED_CFLAGS PPL SCIP SINGULAR SOPLEX TESTS
OPTIONS_DEFAULT=	BLISS LRS NORMALIZ OPENMP OPTIMIZED_CFLAGS PPL SINGULAR
# Exlude lrslib on i386 and powerpc because it is marked BROKEN for those
# architectures
OPTIONS_EXCLUDE_i386=	LRS
OPTIONS_EXCLUDE_powerpc=	LRS
OPTIONS_SUB=	yes

# polymake needs either math/bliss or math/nauty to compute graph automorphism
# groups
OPTIONS_SINGLE=	GRAPH
OPTIONS_SINGLE_GRAPH=	BLISS NAUTY

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

BLISS_CONFIGURE_ON=	--with-bliss=${LOCALBASE}
BLISS_CONFIGURE_OFF=	--without-bliss
BLISS_BUILD_DEPENDS=	bliss-graph-tool>=0.73:math/bliss
BLISS_RUN_DEPENDS=	bliss-graph-tool>=0.73:math/bliss

NAUTY_CONFIGURE_ON=	--with-nauty=${LOCALBASE}
NAUTY_CONFIGURE_OFF=	--without-nauty
NAUTY_LIB_DEPENDS=	libnauty.so:math/nauty

LRS_CONFIGURE_ON=	--with-lrs=${LOCALBASE} \
			--with-lrs-include=${LOCALBASE}/include/lrslib
LRS_CONFIGURE_OFF=	--without-lrs
LRS_LIB_DEPENDS=	liblrs.so:math/lrslib

NORMALIZ_CONFIGURE_ON=	--with-libnormaliz=${LOCALBASE}
NORMALIZ_CONFIGURE_OFF=	--without-libnormaliz
NORMALIZ_LIB_DEPENDS=	libnormaliz.so:math/libnormaliz

OPENMP_CONFIGURE_OFF=	--without-openmp

OPTIMIZED_CFLAGS_CFLAGS=	-O3

PPL_CONFIGURE_ON=	--with-ppl=${LOCALBASE}
PPL_CONFIGURE_OFF=	--without-ppl
PPL_LIB_DEPENDS=	libppl.so:devel/ppl

SCIP_CONFIGURE_ON=	--with-scip=${LOCALBASE}
SCIP_CONFIGURE_OFF=	--without-scip
SCIP_LIB_DEPENDS=	libscip.so:math/SCIP

SINGULAR_CONFIGURE_ON=	--with-singular=${LOCALBASE}
SINGULAR_CONFIGURE_OFF=	--without-singular
SINGULAR_LIB_DEPENDS=	libSingular.so:math/singular

SOPLEX_CONFIGURE_ON=	--with-soplex=${LOCALBASE}
SOPLEX_CONFIGURE_OFF=	--without-soplex
SOPLEX_LIB_DEPENDS=	libsoplex-pic.so:math/SoPlex

TESTS_VARS=	USE_PERL5+=test

# The port uses the minimal distribution tarball without bundled libraries.
# Set WRKSRC accordingly.
WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

.include <bsd.port.options.mk>

# Deal with site specific installation directory
# polymake installs a perlxs module which depends on the perl configuration
PERL_ARCHNAME=	${:!${PERL} -E 'use Config; print "\$Config::Config{archname}";'!}
PLIST_FILES=	libexec/polymake/perlx/${PERL_VERSION}/${PERL_ARCHNAME}/auto/Polymake/Ext/Ext.so

# Keep track of the major version
DISTVERSION_MAJ=	${:!expr ${DISTVERSION} : '\([0-9]*\).*'!}

post-install:
	${RLN} ${STAGEDIR}${PREFIX}/lib/libpolymake.so.${DISTVERSION} \
		${STAGEDIR}${PREFIX}/lib/libpolymake.so.${DISTVERSION_MAJ}
	${RLN} ${STAGEDIR}${PREFIX}/lib/libpolymake.so.${DISTVERSION} \
		${STAGEDIR}${PREFIX}/lib/libpolymake.so

	${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/lib/libpolymake.so.${DISTVERSION} \

.for _lp in libpolymake-apps libpolymake-apps-rt
	${RLN} ${STAGEDIR}${PREFIX}/lib/${_lp}.so.${DISTVERSION} \
		${STAGEDIR}${PREFIX}/lib/${_lp}.so.${DISTVERSION_MAJ}
	${RLN} ${STAGEDIR}${PREFIX}/lib/${_lp}.so.${DISTVERSION} \
		${STAGEDIR}${PREFIX}/lib/${_lp}.so

	${RLN} ${STAGEDIR}${PREFIX}/lib/${_lp}.so.${DISTVERSION} \
		${STAGEDIR}${PREFIX}/libexec/polymake/lib/${_lp}.so.${DISTVERSION_MAJ}
	${RLN} ${STAGEDIR}${PREFIX}/lib/${_lp}.so.${DISTVERSION} \
		${STAGEDIR}${PREFIX}/libexec/polymake/lib/${_lp}.so

	${RLN} ${STAGEDIR}${PREFIX}/libexec/polymake/lib/${_lp}.so.${DISTVERSION} \
		${STAGEDIR}${PREFIX}/libexec/polymake/lib/${_lp}.so.${DISTVERSION_MAJ}
	${RLN} ${STAGEDIR}${PREFIX}/libexec/polymake/lib/${_lp}.so.${DISTVERSION} \
		${STAGEDIR}${PREFIX}/libexec/polymake/lib/${_lp}.so
# strip the libraries
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/polymake/lib/${_lp}.so.${DISTVERSION}
.endfor

	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/polymake/perlx/${PERL_VERSION}/${PERL_ARCHNAME}/auto/Polymake/Ext/Ext.so

.for l in common fan fulton graph group matroid polytope topaz tropical
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/polymake/lib/${l}.so
.endfor

# only strip libexec/polymake/lib/ideal.so iff SINGULAR=on, if SINGULAR=off it
# is an empty file and stripping fails
.if ${PORT_OPTIONS:MSINGULAR}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/polymake/lib/ideal.so
.endif

.for lp in libpolymake-apps libpolymake-apps-rt
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/polymake/lib/${lp}.so.${DISTVERSION}
.endfor

post-install-TESTS-on: test

# Set HOME=${WRKDIR} to prevent polymake writing its .polymake directory outside
# WRKDIR.
test:
	@cd ${WRKSRC} && HOME=${WRKDIR} perl/polymake --script run_testcases

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} >= 504200
BROKEN=	polymake has not been checked for compatibility with perl 5.42 or newer
.endif

.include <bsd.port.post.mk>
