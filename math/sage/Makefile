# Created by: Stephen Montgomery-Smith <stephen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sage
PORTVERSION=	5.12
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://boxen.math.washington.edu/home/sagemath/sage-mirror/src/ \
		http://mirrors.xmission.com/sage/src/ \
		http://www-ftp.lip6.fr/pub/math/sagemath/src/ \
		http://www.sagemath.org/src-old/
PKGNAMESUFFIX=	-math
EXTRACT_SUFX=	.tar

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Open source Mathematics software

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash
LIB_DEPENDS=	atlas:${PORTSDIR}/math/atlas \
		lapack:${PORTSDIR}/math/lapack \
		jpeg:${PORTSDIR}/graphics/jpeg
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

# 387 option: this only makes a difference for the amd64 architecture.  Causes
# the internal floating point calculations to be performed with extended
# precision.
OPTIONS_DEFINE_amd64=	387
387_DESC=		Use 387 instead of SSE FPU

NO_STAGE=	yes
.include <bsd.port.options.mk>

PLIST_FILES=	bin/sage
USE_FORTRAN=	yes
USE_GCC=	yes
USE_TK=		yes
USE_GMAKE=	yes
USE_TEX=	latex:build
USES=		iconv
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

# Optimization flags will be defined by the source
CFLAGS:=	${CFLAGS:C/^-O.*$//}
FFLAGS:=	${CFLAGS:C/^-O.*$//}

MAKE_ENV+=	SAGE_PORT=yes \
		SAGE_INSTALL_GCC=no \
		SAGE_ATLAS_LIB=${LOCALBASE}/lib \
		DOT_SAGE=${WRKSRC}/tmp/.sage \
		SAGE_FAT_BINARY=yes

LATEST_LINK=	sage-math	# Conflicts with graphics/sage.

# The following is needed for the lapack subpackage.
MAKE_ARGS+=	ARCH="${AR}"

post-patch:
# Create the wrappers for the compiler invocations.
	@${MKDIR} ${WRKSRC}/local/bin
	@${LN} -s -f ${LOCALBASE}/bin/gmake ${WRKSRC}/local/bin/make
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
# spkg-${GENERIC_NAME_OF_TARBALL}_-_${NAME_OF_PATCH}.
# The actual name of the tarball will be deduced from the second line of the
# patch.

	@${MKDIR} ${WRKSRC}/tmp
	@${RM} -rf ${WRKSRC}/tmp/*
	@for p in ${FILESDIR}/spkg-patch-*; do \
		q=$${p#*/spkg-patch-}; \
		original_name=$${q%_-_*}; \
		actual_name=`cat $$p | ${HEAD} -2 | ${TAIL} -1 | ${SED} -e 's/+++ //' -e 's|/.*||'`; \
       		if ! [ -e ${WRKSRC}/spkg/standard/$$actual_name.spkg ]; then \
			${ECHO_MSG} "$$actual_name not found."; \
			exit 1; \
		fi; \
		tarballs="$$tarballs $$original_name|$$actual_name"; \
	done ;\
	tarballs=`${PRINTF} "%s\n" $$tarballs | ${SORT} -u`; \
	\
	cd ${WRKSRC}/tmp || exit 1; \
	for t in $$tarballs; do \
		original_name=$${t%|*}; actual_name=$${t#*|}; \
		f=${WRKSRC}/spkg/standard/$$actual_name.spkg; \
		if [ -e $$f-orig ]; then \
			${MV} $$f-orig $$f; \
		fi; \
		${TAR} -xf $$f; \
		${ECHO_MSG} "Patching $$actual_name:"; \
		for p in ${FILESDIR}/spkg-patch-$${original_name}_-_*; do \
			${ECHO_MSG} "	applying $${p#*_-_}" ; \
			${PATCH} < $$p 2>/dev/null || exit 1; \
		done; \
		${MV} $$f $$f-orig; \
		${TAR} -cyf $$f $$actual_name; \
		${RM} -rf $$actual_name; \
	done

post-build:
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

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 701106
BROKEN=		POSIX semaphores are required, and the support only works in FreeBSD 7-STABLE and later
.endif

.if ${PORT_OPTIONS:M387}
FPM_FLAG=	-mfpmath=387
.else
FPM_FLAG=
.endif

MAKE_ENV+=	MAKE="${MAKE} -j${MAKE_JOBS_NUMBER}"

.include <bsd.port.post.mk>
