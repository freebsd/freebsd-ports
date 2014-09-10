# Created by: Stephen Montgomery-Smith <stephen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sage
PORTVERSION=	6.2
PORTREVISION=	4
CATEGORIES=	math
MASTER_SITES=	http://boxen.math.washington.edu/home/sagemath/sage-mirror/src/ \
		http://mirrors.xmission.com/sage/src/ \
		http://www-ftp.lip6.fr/pub/math/sagemath/src/ \
		http://www.sagemath.org/src-old/
PKGNAMESUFFIX=	-math
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${PYTHON_SOURCE}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Open source Mathematics software

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING.txt

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		convert:${PORTSDIR}/graphics/ImageMagick \
		ffmpeg:${PORTSDIR}/multimedia/ffmpeg \
		automake:${PORTSDIR}/devel/automake \
		autoconf:${PORTSDIR}/devel/autoconf
LIB_DEPENDS=	libatlas.so:${PORTSDIR}/math/atlas \
		liblapack.so:${PORTSDIR}/math/lapack \
		libjpeg.so:${PORTSDIR}/graphics/jpeg
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

PYTHON_SOURCE=	python/Python-2.7.6.tar.xz

# 387 option: this only makes a difference for the amd64 architecture.  Causes
# the internal floating point calculations to be performed with extended
# precision.
OPTIONS_DEFINE_amd64=	387
387_DESC=		Use 387 instead of SSE FPU

.include <bsd.port.options.mk>

pre-extract:
	@${ECHO_MSG}
	@${ECHO_MSG} Instead of installing the port, which will take a considerable amount of
	@${ECHO_MSG} extra time and space, you can instead type \"make build\".  Then you can move
	@${ECHO_MSG} work/${PORTNAME}-${PORTVERSION} to wherever you like, and run sage from there.
	@${ECHO_MSG} However, there is no guarantee that this alternative will always work.
	@sleep 10

PLIST_FILES=	bin/sage
USE_GCC=	yes
USE_TEX=	latex:build
USES=		fortran gmake iconv tk
MAKE_JOBS_SAFE=	yes
LDFLAGS:=	-Wl,-rpath=${WRKSRC}/local/lib ${LDFLAGS}
FFLAGS+=	-Wl,-rpath=${WRKSRC}/local/lib ${FPM_FLAG}
CFLAGS+=	-Wl,-rpath=${WRKSRC}/local/lib ${FPM_FLAG}
CXXFLAGS+=	-Wl,-rpath=${WRKSRC}/local/lib ${FPM_FLAG}
# Note that the above addition to LDFLAGS, as a side effect, provides a
# work-around for the make(1) idiosyncracy mentioned in PR 164361 (which
# otherwise breaks the build of the maxima sub-package).

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
	${CP} ${DISTDIR}/${PYTHON_SOURCE} ${WRKSRC}/upstream/.

	${REINPLACE_CMD} 's/$$MAKE $$gettext/$$MAKE PTHREAD_LIBS=${PTHREAD_LIBS} $$gettext/' ${WRKSRC}/build/pkgs/git/spkg-install

# Create the wrappers for the compiler invocations.
	@${MKDIR} ${WRKSRC}/local/bin
	@${LN} -s -f ${LOCALBASE}/bin/gmake ${WRKSRC}/local/bin/make
	@${SED} -e "s#%%CC%%#`which ${CC}`#" \
		-e 's#%%LDFLAGS%%#${LDFLAGS} ${FPM_FLAG}#' \
		${FILESDIR}/gcc.in > ${WRKSRC}/local/bin/cc
	@${CHMOD} +x ${WRKSRC}/local/bin/cc
	@${LN} -s -f cc ${WRKSRC}/local/bin/gcc
	@${SED} -e "s#%%CC%%#`which ${CXX}`#" \
		-e 's#%%LDFLAGS%%#${LDFLAGS} ${FPM_FLAG}#' \
		${FILESDIR}/gcc.in > ${WRKSRC}/local/bin/c++
	@${CHMOD} +x ${WRKSRC}/local/bin/c++
	@${LN} -s -f c++ ${WRKSRC}/local/bin/g++
	@${SED} -e "s#%%CC%%#`which ${FC}`#" \
		-e 's#%%LDFLAGS%%#${LDFLAGS} ${FPM_FLAG}#' \
		${FILESDIR}/gcc.in > ${WRKSRC}/local/bin/gfortran
	@${CHMOD} +x ${WRKSRC}/local/bin/gfortran

post-build:
	${RM} -rf ${WRKSRC}/tmp/.sage
	${CHMOD} -R a+rX ${WRKSRC}

check regression-test test: build
	@${ECHO_MSG} This test can also be performed after installation by typing \"sage -testall\".
	@${ECHO_MSG}
	cd ${WRKSRC} && ${SETENV} DOT_SAGE=${WRKSRC}/tmp/.sage ./sage -testall
	${RM} -f ${WRKSRC}/python*.core

INSTALL_SAGE_DIR=	${PREFIX}/${PORTNAME}-${PORTVERSION}
STAGED_SAGE_DIR=	${STAGEDIR}${INSTALL_SAGE_DIR}
do-install:
	cd ${WRKDIR} && ${FIND} -s ${WRKSRC} | \
		${GREP} -v '^${WRKSRC}/upstream/' | \
		${GREP} -v '^${WRKSRC}/tmp' | \
		${SED} -e 's#${WRKDIR}/##' | \
		${CPIO} -pmud -R ${BINOWN}:${BINGRP} ${STAGEDIR}${PREFIX}
	${ECHO_CMD} | ${SETENV} DOT_SAGE=${STAGED_SAGE_DIR}/tmp/.sage ${STAGED_SAGE_DIR}/sage
	${RM} -rf ${STAGED_SAGE_DIR}/tmp/.sage
	${SED} -e "s+#SAGE_ROOT.*+SAGE_ROOT=${INSTALL_SAGE_DIR}+" ${WRKSRC}/sage > ${STAGEDIR}${PREFIX}/bin/sage
	${CHMOD} ${BINMODE} ${STAGEDIR}${PREFIX}/bin/sage

post-install:
	@${FIND} -s ${STAGED_SAGE_DIR} -not -type d | \
		${SED} -e 's#${STAGEDIR}${PREFIX}/##' >> ${TMPPLIST}
	@${FIND} -s ${STAGED_SAGE_DIR} -type d -empty | \
		${SED} -e 's#${STAGEDIR}${PREFIX}/#@exec ${MKDIR} %D/#' >> ${TMPPLIST}
	@${FIND} -s ${STAGED_SAGE_DIR} -type d -depth | \
		${SED} -e 's#${STAGEDIR}${PREFIX}/#@dirrm #' >> ${TMPPLIST}

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

.ifdef MAINTAINER_MODE
test-fbsd-patches:	patch
	${RM} -rf ${WRKSRC}/build/pkgs/*/src; \
	for d in ${WRKSRC}/build/pkgs/*; do \
		if ls $$d/fbsd-patch-* > /dev/null 2>&1; then \
			${ECHO_MSG} Testing patches in $${d##*/}; \
			b=$${d##*/}-`${CAT} $$d/package-version.txt | ${SED} 's/\.p.*//'`; \
			c=${WRKSRC}/upstream/$$b.tar.bz2 ; \
			if [ ! -e $$c ]; then \
				${ECHO_MSG} Couldn\'t find $$c; \
				exit 1; \
			fi; \
			if ! (cd $$d && tar xf $$c && ${MV} $$b src); then \
				${ECHO_MSG} Unable to unarchive $$c; \
				exit 1; \
			fi; \
			if ! (cd $$d && ${CAT} fbsd-patch-* | patch); then \
				${ECHO_MSG} Patches in $${d##*/} failed; \
				exit 1; \
			fi; \
		fi; \
	done; \
	${RM} -rf ${WRKSRC}/build/pkgs/*/src
.endif

.include <bsd.port.post.mk>
