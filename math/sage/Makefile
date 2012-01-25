# New ports collection makefile for:	sage
# Date created:		24 January 2012
# Whom:			Stephen Montgomery-Smith <stephen@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sage
PORTVERSION=	4.8
CATEGORIES=	math
MASTER_SITES=	http://modular.math.jmu.edu/src/ \
		http://boxen.math.washington.edu/sage/src/ \
		http://mirrors.xmission.com/sage/src/
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

MAKE_ENV+=	SAGE_PORT=yes \
		SAGE_FORTRAN=${LOCALBASE}/bin/${FC} \
		SAGE_FORTRAN_LIB=${LOCALBASE}/lib/gcc${GCC_DEFAULT_V}/libgfortran.so \
		SAGE_ATLAS_LIB=${LOCALBASE}/lib

# The following is needed for the lapack subpackage.
MAKE_ARGS+=	ARCH="${AR}"

post-patch:
	@${MKDIR} ${WRKSRC}/local/bin
	@${LN} -s ${LOCALBASE}/bin/gmake ${WRKSRC}/local/bin/make
	@${LN} -s ${LOCALBASE}/bin/bash ${WRKSRC}/local/bin/sh
	@${LN} -s ${LOCALBASE}/bin/${FC} ${WRKSRC}/local/bin/gfortran
	@${MKDIR} ${WRKSRC}/tmp
	@for p in ${FILESDIR}/spkg-patch-*; do \
	        t=`${ECHO_CMD} $$p | ${SED} -e "s+^${FILESDIR}/spkg-patch-++" -e 's+_-_.*++'`; \
       		if ! [ -e ${WRKSRC}/spkg/standard/$$t.spkg ]; then \
			${ECHO_CMD} "$$t not found."; \
			exit 1; \
		fi; \
		tarballs="$$tarballs $$t"; \
	done ;\
	tarballs=`for t in $$tarballs; do ${ECHO_CMD} $$t; done | uniq`; \
	\
	cd ${WRKSRC}/tmp || exit 1; \
	for t in $$tarballs; do \
		f=${WRKSRC}/spkg/standard/$$t.spkg; \
		if [ -e $$f-orig ]; then \
			${MV} $$f-orig $$f; \
		fi; \
		${BZIP2_CMD} -dc $$f | ${TAR} -xf -; \
		${ECHO_CMD} "Patching $$t:"; \
		for p in ${FILESDIR}/spkg-patch-$${t}_-_*; do \
			${ECHO_CMD} "	applying $$p" | ${SED} -e 's#${FILESDIR}/.*_-_##' ; \
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
.if ${OSVERSION} >= 900000
IGNORE=		the port isn't tested for FreeBSD 9 or later
.endif

.if !defined(DISABLE_MAKE_JOBS)
MAKE_ENV+=	MAKE="make -j${MAKE_JOBS_NUMBER}"
.endif

# The following code is copied from bsd.port.mk, but with extra code that
# removes an extra space from ${LDFLAGS}.  The space messes up the build of
# the maxima subpackage.  See
# http://www.freebsd.org/cgi/query-pr.cgi?pr=164361
do-build:
	LDFLAGS=${LDFLAGS:C|^ ||}; \
	cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} LDFLAGS="$${LDFLAGS}" ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${_MAKE_JOBS} ${MAKE_ARGS} ${ALL_TARGET}
	${MKDIR} ${WRKDIR}/bin
	${SED} -e "s+#SAGE_ROOT.*+SAGE_ROOT=${INSTALL_SAGE_DIR}+" ${WRKSRC}/sage > ${WRKDIR}/bin/sage

INSTALL_SAGE_DIR=	${PREFIX}/${PORTNAME}-${PORTVERSION}
do-install:
	cd ${WRKDIR} && ${FIND} -s ${WRKSRC} | ${SED} -e 's#${WRKDIR}/##' | \
		${CPIO} -pmud -R root:wheel ${PREFIX}
	${ECHO_CMD} | ${INSTALL_SAGE_DIR}/sage
	${INSTALL_SCRIPT} ${WRKDIR}/bin/sage ${PREFIX}/bin

post-install:
	${FIND} -s ${INSTALL_SAGE_DIR} -not -type d | \
		${SED} -e 's#${PREFIX}/##' >> ${TMPPLIST}
	${FIND} -s ${INSTALL_SAGE_DIR} -type d -empty | \
		${SED} -e 's#${PREFIX}/#@exec ${MKDIR} %D/#' >> ${TMPPLIST}
	${FIND} -s ${INSTALL_SAGE_DIR} -type d -depth | \
		${SED} -e 's#${PREFIX}/#@dirrm #' >> ${TMPPLIST}

.include <bsd.port.post.mk>
