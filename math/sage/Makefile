# New ports collection makefile for:	sage
# Date created:		24 January 2012
# Whom:			Stephen Montgomery-Smith <stephen@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sage
PORTVERSION=	4.8
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://modular.math.jmu.edu/src/ \
		http://boxen.math.washington.edu/sage/src/ \
		http://mirrors.xmission.com/sage/src/ \
		http://www.sagemath.org/src-old/
EXTRACT_SUFX=	.tar

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Open source Mathematics software

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		latex:${PORTSDIR}/print/teTeX-base \
		autoconf-2.68:${PORTSDIR}/devel/autoconf
LIB_DEPENDS=	atlas:${PORTSDIR}/math/atlas \
		lapack:${PORTSDIR}/math/lapack \
		jpeg:${PORTSDIR}/graphics/jpeg
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

PLIST_FILES=	bin/sage

USE_FORTRAN=	yes
USE_TK=		yes
USE_GMAKE=	yes
USE_ICONV=	yes
MAKE_JOBS_SAFE=	yes
LDFLAGS:=	-Wl,-rpath=${WRKSRC}/local/lib ${LDFLAGS}
FFLAGS+=	-Wl,-rpath=${WRKSRC}/local/lib
CFLAGS+=	-Wl,-rpath=${WRKSRC}/local/lib
CXXFLAGS+=	-Wl,-rpath=${WRKSRC}/local/lib
# Note that the above addition to LDFLAGS, as a side effect, provides a
# work-around for the make(1) idiosyncracy mentioned in PR 164361 (which
# otherwise breaks the build of the maxima sub-package).

MAKE_ENV+=	SAGE_PORT=yes \
		SAGE_FORTRAN=${LOCALBASE}/bin/${FC} \
		SAGE_FORTRAN_LIB=${LOCALBASE}/lib/gcc${GCC_DEFAULT_V}/libgfortran.so \
		SAGE_ATLAS_LIB=${LOCALBASE}/lib

NO_LATEST_LINK=	yes	# Conflicts with graphics/sage.

# The following is needed for the lapack subpackage.
MAKE_ARGS+=	ARCH="${AR}"

post-patch:
	@${MKDIR} ${WRKSRC}/local/bin
	@${LN} -s -f ${LOCALBASE}/bin/gmake ${WRKSRC}/local/bin/make
	@${LN} -s -f ${LOCALBASE}/bin/bash ${WRKSRC}/local/bin/sh
	@${SED} -e 's#%%CC%%#${LOCALBASE}/bin/${CC}#' -e 's#%%CFLAGS%%#${CFLAGS}#' ${FILESDIR}/gcc.in > ${WRKSRC}/local/bin/cc
	@${CHMOD} +x ${WRKSRC}/local/bin/cc
	@${LN} -s -f cc ${WRKSRC}/local/bin/gcc
	@${SED} -e 's#%%CC%%#${LOCALBASE}/bin/${CXX}#' -e 's#%%CFLAGS%%#${CXXFLAGS}#' ${FILESDIR}/gcc.in > ${WRKSRC}/local/bin/c++
	@${CHMOD} +x ${WRKSRC}/local/bin/c++
	@${LN} -s -f c++ ${WRKSRC}/local/bin/g++
	@${SED} -e 's#%%CC%%#${LOCALBASE}/bin/${FC}#' -e 's#%%CFLAGS%%#${FFLAGS}#' ${FILESDIR}/gcc.in > ${WRKSRC}/local/bin/gfortran
	@${CHMOD} +x ${WRKSRC}/local/bin/gfortran
	@${MKDIR} ${WRKSRC}/tmp
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
		${BZIP2_CMD} -dc $$f | ${TAR} -xf -; \
		${ECHO_MSG} "Patching $$t:"; \
		for p in ${FILESDIR}/spkg-patch-$${t}_-_*; do \
			${ECHO_MSG} "	applying $${p#*_-_}" ; \
			${PATCH} < $$p 2>/dev/null || exit 1; \
		done; \
		${MV} $$f $$f-orig; \
		${TAR} -cf - $$t | ${BZIP2_CMD} -c > $$f; \
		${RM} -rf $$t; \
	done

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 701106
IGNORE=		POSIX semaphores are required, and the support only works in FreeBSD 7-STABLE and later
.endif

.if !defined(DISABLE_MAKE_JOBS)
MAKE_ENV+=	MAKE="make -j${MAKE_JOBS_NUMBER}"
.endif

check regression-test test: build
	@${ECHO_MSG} This test can also be performed after installation by typing \"sage --testall\".
	@${ECHO_MSG}
	cd ${WRKSRC}; local/bin/sage-starts; \
	${LOCALBASE}/bin/bash -c ". local/bin/sage-env && sage-maketest"

INSTALL_SAGE_DIR=	${PREFIX}/${PORTNAME}-${PORTVERSION}
do-install:
	cd ${WRKDIR} && ${FIND} -s ${WRKSRC} | ${SED} -e 's#${WRKDIR}/##' | \
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
