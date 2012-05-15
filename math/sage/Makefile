# New ports collection makefile for:	sage
# Date created:		24 January 2012
# Whom:			Stephen Montgomery-Smith <stephen@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sage
PORTVERSION=	5.0
CATEGORIES=	math
MASTER_SITES=	http://boxen.math.washington.edu/home/sagemath/sage-mirror/src/ \
		http://mirrors.xmission.com/sage/src/ \
		http://www-ftp.lip6.fr/pub/math/sagemath/src/ \
		http://www.sagemath.org/src-old/
EXTRACT_SUFX=	.tar

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Open source Mathematics software

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		latex:${PORTSDIR}/print/teTeX-base
LIB_DEPENDS=	atlas:${PORTSDIR}/math/atlas \
		lapack:${PORTSDIR}/math/lapack \
		jpeg:${PORTSDIR}/graphics/jpeg
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

# 387 option: this only makes a difference for the amd64 architecture.  Causes
# the internal floating point calculations to be performed with extended
# precision.
# Optional packages: see http://www.sagemath.org/packages/optional/
OPTIONS=	\
	387			"Use 387 instead of SSE FPU"	Off \
	4TI2			4ti2				Off \
	TOPCOM			TOPCOM				Off \
	BIOPYTHON		biopython			Off \
	CBC			cbc				Off \
	CUNNINGHAM_TABLES	cunningham_tables		Off \
	DB_CREMONA_ELLCURVE	db_cremona_ellcurve		Off \
	DB_GAP			db_gap				Off \
	DB_JONES_NUMFIELD	db_jones_numfield		Off \
	DB_KOHEL		db_kohel			Off \
	DB_ODLYZKO_ZETA		db_odlyzko_zeta			Off \
	DB_SLOANE_OEIS		db_sloane_oeis			Off \
	DB_STEIN_WATKINS_MINI	db_stein_watkins_mini		Off \
	DB_SYMBOLIC_DATA	db_symbolic_data		Off \
	DOT2TEX			dot2tex				Off \
	EXTRA_DOCS		extra_docs			Off \
	GAP_PACKAGES		gap_packages			Off \
	GDBM			gdbm				Off \
	GINV			ginv				Off \
	GIT			git				Off \
	GMPY			gmpy				Off \
	GNUPLOTPY		gnuplotpy			Off \
	GUPPY			guppy				Off \
	JAVA3D			java3d				Off \
	JSMATH_IMAGE_FONTS	jsmath_image_fonts		Off \
	KASH3			kash3				Off \
	KNOBOO			knoboo				Off \
	LIE			lie				Off \
	LRCALC			lrcalc				Off \
	LRS			lrs				Off \
	MPC			mpc				Off \
	MPI4PY			mpi4py				Off \
	NAUTY			nauty				Off \
	NZMATH			nzmath				Off \
	P_GROUP_COHOMOLOGY	p_group_cohomology		Off \
	PYCRYPTOPLUS		pycryptoplus			Off \
	PYOPENSSL		pyopenssl			Off \
	PYX			pyx				Off \
	QHULL			qhull				Off \
	SAGE_MODE		sage-mode			Off \
	TRAC			trac				Off

PLIST_FILES=	bin/sage
USE_FORTRAN=	yes
USE_TK=		yes
USE_GMAKE=	yes
USE_ICONV=	yes
MAKE_JOBS_SAFE=	yes
LDFLAGS:=	-Wl,-rpath=${WRKSRC}/local/lib ${LDFLAGS}
FFLAGS+=	-Wl,-rpath=${WRKSRC}/local/lib ${FPM_FLAG}
CFLAGS+=	-Wl,-rpath=${WRKSRC}/local/lib ${FPM_FLAG}
CXXFLAGS+=	-Wl,-rpath=${WRKSRC}/local/lib ${FPM_FLAG}
# Note that the above addition to LDFLAGS, as a side effect, provides a
# work-around for the make(1) idiosyncracy mentioned in PR 164361 (which
# otherwise breaks the build of the maxima sub-package).

USE_AUTOTOOLS=	autoconf
run-autotools:
		@${DO_NADA}
do-configure:
		@${DO_NADA}

.include <bsd.port.pre.mk>

.if defined(WITH_4TI2) || defined(WITH_TOPCOM) || defined(WITH_BIOPYTHON) || \
    defined(WITH_CBC) || defined(WITH_CUNNINGHAM_TABLES) || \
    defined(WITH_DB_CREMONA_ELLCURVE) || defined(WITH_DB_GAP) || \
    defined(WITH_DB_JONES_NUMFIELD) || defined(WITH_DB_KOHEL) || \
    defined(WITH_DB_ODLYZKO_ZETA) || defined(WITH_DB_SLOANE_OEIS) || \
    defined(WITH_DB_STEIN_WATKINS_MINI) || defined(WITH_DB_SYMBOLIC_DATA) || \
    defined(WITH_DOT2TEX) || defined(WITH_EXTRA_DOCS) || \
    defined(WITH_GAP_PACKAGES) || defined(WITH_GDBM) || defined(WITH_GINV) || \
    defined(WITH_GIT) || defined(WITH_GMPY) || defined(WITH_GNUPLOTPY) || \
    defined(WITH_GUPPY) || defined(WITH_JAVA3D) || \
    defined(WITH_JSMATH_IMAGE_FONTS) || defined(WITH_KASH3) || \
    defined(WITH_KNOBOO) || defined(WITH_LIE) || defined(WITH_LRCALC) || \
    defined(WITH_LRS) || defined(WITH_MPC) || defined(WITH_MPI4PY) || \
    defined(WITH_NAUTY) || defined(WITH_NZMATH) || \
    defined(WITH_P_GROUP_COHOMOLOGY) || defined(WITH_PYCRYPTOPLUS) || \
    defined(WITH_PYOPENSSL) || defined(WITH_PYX) || defined(WITH_QHULL) || \
    defined(WITH_SAGE_MODE) || defined(WITH_TRAC)
WITH_OPTIONAL_PKGS=	yes
.endif

.ifdef WITH_OPTIONAL_PKGS
USE_PERL5_BUILD=	yes
.endif

# Optimization flags will be defined by the source
CFLAGS:=	${CFLAGS:C/^-O.*$//}
FFLAGS:=	${CFLAGS:C/^-O.*$//}

MAKE_ENV+=	SAGE_PORT=yes \
		SAGE_FORTRAN=${LOCALBASE}/bin/${FC} \
		SAGE_FORTRAN_LIB=${LOCALBASE}/lib/gcc${GCC_DEFAULT_V}/libgfortran.so \
		SAGE_ATLAS_LIB=${LOCALBASE}/lib \
		DOT_SAGE=${WRKSRC}/tmp/.sage

LATEST_LINK=	sage-math	# Conflicts with graphics/sage.

# The following is needed for the lapack subpackage.
MAKE_ARGS+=	ARCH="${AR}"

.if ${OSVERSION} < 701106
BROKEN=		POSIX semaphores are required, and the support only works in FreeBSD 7-STABLE and later
.endif

.if defined(WITH_387) && ${ARCH} == amd64
FPM_FLAG=	-mfpmath=387
.else
FPM_FLAG=
.endif

.if !defined(DISABLE_MAKE_JOBS)
MAKE_ENV+=	MAKE="make -j${MAKE_JOBS_NUMBER}"
.endif

post-patch:
# Create the wrappers for the compiler invokations.
	@${MKDIR} ${WRKSRC}/local/bin
	@${LN} -s -f ${LOCALBASE}/bin/gmake ${WRKSRC}/local/bin/make
	@${LN} -s -f ${LOCALBASE}/bin/bash ${WRKSRC}/local/bin/sh
	@${SED} -e 's#%%CC%%#${LOCALBASE}/bin/${CC}#' \
		-e 's#%%LDFLAGS%%#${LDFLAGS} ${FPM_FLAG}#' \
		${FILESDIR}/gcc.in > ${WRKSRC}/local/bin/cc
	@${CHMOD} +x ${WRKSRC}/local/bin/cc
	@${LN} -s -f cc ${WRKSRC}/local/bin/gcc
	@${SED} -e 's#%%CC%%#${LOCALBASE}/bin/${CXX}#' \
		-e 's#%%LDFLAGS%%#${LDFLAGS} ${FPM_FLAG}#' \
		${FILESDIR}/gcc.in > ${WRKSRC}/local/bin/c++
	@${CHMOD} +x ${WRKSRC}/local/bin/c++
	@${LN} -s -f c++ ${WRKSRC}/local/bin/g++
	@${SED} -e 's#%%CC%%#${LOCALBASE}/bin/${FC}#' \
		-e 's#%%LDFLAGS%%#${LDFLAGS} ${FPM_FLAG}#' \
		${FILESDIR}/gcc.in > ${WRKSRC}/local/bin/gfortran
	@${CHMOD} +x ${WRKSRC}/local/bin/gfortran

# Apply the patches to the appropriate xz'ed tarballs contained in
# ${WRKSRC}/spkg/standard.  The names of the patches are
# spkg-${NAME_OF_TARBALL}_-_${NAME_OF_PATCH}.

	@${MKDIR} ${WRKSRC}/tmp
	@${RM} -rf ${WRKSRC}/tmp/*
	@for p in ${FILESDIR}/spkg-patch-*; do \
		q=$${p#*/spkg-patch-}; t=$${q%_-_*}; \
       		if ! [ -e ${WRKSRC}/spkg/standard/$$t.spkg ]; then \
			${ECHO_MSG} "$$t not found."; \
			exit 1; \
		fi; \
		tarballs="$$tarballs $$t"; \
	done ;\
	tarballs=`${PRINTF} "%s\n" $$tarballs | ${SORT} -u`; \
	\
	cd ${WRKSRC}/tmp || exit 1; \
	for t in $$tarballs; do \
		f=${WRKSRC}/spkg/standard/$$t.spkg; \
		if [ -e $$f-orig ]; then \
			${MV} $$f-orig $$f; \
		fi; \
		${TAR} -xf $$f; \
		${ECHO_MSG} "Patching $$t:"; \
		for p in ${FILESDIR}/spkg-patch-$${t}_-_*; do \
			${ECHO_MSG} "	applying $${p#*_-_}" ; \
			${PATCH} < $$p 2>/dev/null || exit 1; \
		done; \
		${MV} $$f $$f-orig; \
		${TAR} -cyf $$f $$t; \
		${RM} -rf $$t; \
	done

# Here we check dependencies of the optional packages on ports, and on other
# optional packages.  If you find any dependencies not listed here, please
# contact the maintainer.

.ifdef WITH_4TI2
OPT_PKG_LIST:=	${OPT_PKG_LIST}|4ti2-
.endif
.ifdef WITH_TOPCOM
OPT_PKG_LIST:=	${OPT_PKG_LIST}|topcom-
.endif
.ifdef WITH_BIOPYTHON
OPT_PKG_LIST:=	${OPT_PKG_LIST}|biopython-
.endif
.ifdef WITH_CBC
OPT_PKG_LIST:=	${OPT_PKG_LIST}|cbc-
.endif
.ifdef WITH_CUNNINGHAM_TABLES
OPT_PKG_LIST:=	${OPT_PKG_LIST}|cunningham_tables-
.endif
.ifdef WITH_DB_CREMONA_ELLCURVE
OPT_PKG_LIST:=	${OPT_PKG_LIST}|database_cremona_ellcurve-
.endif
.ifdef WITH_DB_GAP
OPT_PKG_LIST:=	${OPT_PKG_LIST}|database_gap-
.endif
.ifdef WITH_DB_JONES_NUMFIELD
OPT_PKG_LIST:=	${OPT_PKG_LIST}|database_jones_numfield-
.endif
.ifdef WITH_DB_KOHEL
OPT_PKG_LIST:=	${OPT_PKG_LIST}|database_kohel-
.endif
.ifdef WITH_DB_ODLYZKO_ZETA
OPT_PKG_LIST:=	${OPT_PKG_LIST}|database_odlyzko_zeta-
.endif
.ifdef WITH_DB_SLOANE_OEIS
OPT_PKG_LIST:=	${OPT_PKG_LIST}|database_sloane_oeis-
.endif
.ifdef WITH_DB_STEIN_WATKINS_MINI
OPT_PKG_LIST:=	${OPT_PKG_LIST}|database_stein_watkins_mini
.endif
.ifdef WITH_DB_SYMBOLIC_DATA
OPT_PKG_LIST:=	${OPT_PKG_LIST}|database_symbolic_data-
.endif
.ifdef WITH_DOT2TEX
OPT_PKG_LIST:=	${OPT_PKG_LIST}|dot2tex-
.endif
.ifdef WITH_EXTRA_DOCS
OPT_PKG_LIST:=	${OPT_PKG_LIST}|extra_docs-
.endif
.ifdef WITH_GAP_PACKAGES
OPT_PKG_LIST:=	${OPT_PKG_LIST}|gap_packages-
.endif
.ifdef WITH_GDBM
OPT_PKG_LIST:=	${OPT_PKG_LIST}|gdbm-
.endif
.ifdef WITH_GINV
OPT_PKG_LIST:=	${OPT_PKG_LIST}|ginv-
.endif
.ifdef WITH_GIT
OPT_PKG_LIST:=	${OPT_PKG_LIST}|git-
.endif
.ifdef WITH_GMPY
OPT_PKG_LIST:=	${OPT_PKG_LIST}|gmpy-
.endif
.ifdef WITH_GNUPLOTPY
OPT_PKG_LIST:=	${OPT_PKG_LIST}|gnuplotpy-
RUN_DEPENDS+=	gnuplot:${PORTSDIR}/math/gnuplot
.endif
.ifdef WITH_GUPPY
OPT_PKG_LIST:=	${OPT_PKG_LIST}|guppy-
.endif
.ifdef WITH_JAVA3D
OPT_PKG_LIST:=	${OPT_PKG_LIST}|java3d-
USE_JAVA=	yes
.endif
.ifdef WITH_JSMATH_IMAGE_FONTS
OPT_PKG_LIST:=	${OPT_PKG_LIST}|jsmath_image_fonts-
.endif
.ifdef WITH_KASH3
OPT_PKG_LIST:=	${OPT_PKG_LIST}|kash3-
.endif
.ifdef WITH_KNOBOO
OPT_PKG_LIST:=	${OPT_PKG_LIST}|knoboo-
.endif
.ifdef WITH_LIE
OPT_PKG_LIST:=	${OPT_PKG_LIST}|lie-
.endif
.ifdef WITH_LRCALC
OPT_PKG_LIST:=	${OPT_PKG_LIST}|lrcalc-
.endif
.ifdef WITH_LRS
OPT_PKG_LIST:=	${OPT_PKG_LIST}|lrs-
.endif
.ifdef WITH_MPC
OPT_PKG_LIST:=	${OPT_PKG_LIST}|mpc-
.endif
.ifdef WITH_MPI4PY
OPT_PKG_LIST:=	${OPT_PKG_LIST}|mpi4py-
LIB_DEPENDS+=	mpi:${PORTSDIR}/net/openmpi
MAKE_ENV+=	PATH=$${PATH}:${LOCALBASE}/`${MAKE} -C ${PORTSDIR}/net/openmpi -V MPIDIR`/bin
.endif
.ifdef WITH_NAUTY
OPT_PKG_LIST:=	${OPT_PKG_LIST}|nauty-
.endif
.ifdef WITH_NZMATH
OPT_PKG_LIST:=	${OPT_PKG_LIST}|nzmath-
.endif
.ifdef WITH_P_GROUP_COHOMOLOGY
.if !defined(WITH_DB_GAP)
IGNORE=	DB_GAP must be set if P_GROUP_COHOMOLOGY is set
.endif
OPT_PKG_LIST:=	${OPT_PKG_LIST}|p_group_cohomology-
.endif
.ifdef WITH_PYCRYPTOPLUS
OPT_PKG_LIST:=	${OPT_PKG_LIST}|pycryptoplus-
.endif
.ifdef WITH_PYOPENSSL
OPT_PKG_LIST:=	${OPT_PKG_LIST}|pyopenssl-
.endif
.ifdef WITH_PYX
OPT_PKG_LIST:=	${OPT_PKG_LIST}|pyx-
.endif
.ifdef WITH_QHULL
OPT_PKG_LIST:=	${OPT_PKG_LIST}|qhull-
.endif
.ifdef WITH_SAGE_MODE
OPT_PKG_LIST:=	${OPT_PKG_LIST}|sage_mode-
.endif
.ifdef WITH_TRAC
OPT_PKG_LIST:=	${OPT_PKG_LIST}|trac-
.endif
OPT_PKG_LIST:=	${OPT_PKG_LIST:C/\|//}	# Remove the leading '|'

post-build:
.ifdef WITH_OPTIONAL_PKGS
	${SETENV} ${MAKE_ENV} ${WRKSRC}/sage -optional | \
	${PERL} -lne 'print if $$p && /^\S+$$/; $$p=1 if /NOT INSTALLED:/' | \
	${GREP} -E '^(${OPT_PKG_LIST})' | \
	${XARGS} -n1 ${SETENV} ${MAKE_ENV} \
	${WRKSRC}/sage -i
#	${MAKE} -C ${.CURDIR} do-build # Not sure if this is necessary.
.endif
	${RM} -rf ${WRKSRC}/tmp/.sage
	${CHMOD} -R a+rX ${WRKSRC}

check regression-test test: build
	@${ECHO_MSG} This test can also be performed after installation by typing \"sage -testall\".
	@${ECHO_MSG}
	cd ${WRKSRC} && ${SETENV} DOT_SAGE=${WRKSRC}/tmp/.sage ./sage -testall
	${RM} -f ${WRKSRC}/python.core

INSTALL_SAGE_DIR=	${PREFIX}/${PORTNAME}-${PORTVERSION}
do-install:
	cd ${WRKDIR} && ${FIND} -s ${WRKSRC} | \
		${GREP} -v '^${WRKSRC}/spkg/standard/' | \
		${GREP} -v '^${WRKSRC}/spkg/optional/' | \
		${GREP} -v '^${WRKSRC}/spkg/logs/' | \
		${GREP} -v '^${WRKSRC}/spkg/build/' | \
		${GREP} -v '^${WRKSRC}/tmp' | \
		${GREP} -v -E '^${WRKSRC}/[^\/]+\.log$$' | \
		${GREP} -v '^${WRKSRC}/Makefile' | \
		${SED} -e 's#${WRKDIR}/##' | \
		${CPIO} -pmud -R ${BINOWN}:${BINGRP} ${PREFIX}
	${ECHO_CMD} | ${SETENV} DOT_SAGE=${INSTALL_SAGE_DIR}/tmp/.sage ${INSTALL_SAGE_DIR}/sage
	${RM} -rf ${INSTALL_SAGE_DIR}/tmp/.sage
	${SED} -e "s+#SAGE_ROOT.*+SAGE_ROOT=${INSTALL_SAGE_DIR}+" ${WRKSRC}/sage > ${PREFIX}/bin/sage
	${CHOWN} ${BINOWN}:${BINGRP} ${PREFIX}/bin/sage
	${CHMOD} ${BINMODE} ${PREFIX}/bin/sage

post-install:
	@${FIND} -s ${INSTALL_SAGE_DIR} -not -type d | \
		${SED} -e 's#${PREFIX}/##' >> ${TMPPLIST}
	@${FIND} -s ${INSTALL_SAGE_DIR} -type d -empty | \
		${SED} -e 's#${PREFIX}/#@exec ${MKDIR} %D/#' >> ${TMPPLIST}
	@${FIND} -s ${INSTALL_SAGE_DIR} -type d -depth | \
		${SED} -e 's#${PREFIX}/#@dirrm #' >> ${TMPPLIST}

.include <bsd.port.post.mk>
