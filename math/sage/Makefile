# Created by: Stephen Montgomery-Smith <stephen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sage
PORTVERSION=	6.7
PORTREVISION=	8
CATEGORIES=	math
MASTER_SITES=	http://boxen.math.washington.edu/home/sagemath/sage-mirror/src/ \
		http://mirrors.xmission.com/sage/src/ \
		http://www-ftp.lip6.fr/pub/math/sagemath/src/ \
		http://mirrors.mit.edu/sage/src/ \
		http://www.sagemath.org/src-old/
PKGNAMESUFFIX=	-math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Open source Mathematics software

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2020-06-05

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING.txt

BUILD_DEPENDS=	bash:shells/bash \
		convert:graphics/ImageMagick6 \
		ffmpeg:multimedia/ffmpeg \
		automake:devel/automake \
		autoconf:devel/autoconf
LIB_DEPENDS=	libatlas.so:math/atlas \
		liblapack.so:math/lapack
RUN_DEPENDS=	bash:shells/bash

pre-extract:
	@${ECHO_MSG}
	@${ECHO_MSG} Instead of installing the port, which will take a considerable amount of
	@${ECHO_MSG} extra time and space, you can instead type \"make build\".  Then you can move
	@${ECHO_MSG} work/${PORTNAME}-${PORTVERSION} to wherever you like, and run sage from there.
	@${ECHO_MSG} However, there is no guarantee that this alternative will always work.
.  if !(defined(PACKAGE_BUILDING) || defined(BATCH))
	@sleep 10
.  endif

PLIST_FILES=	bin/sage
USE_TEX=	latex:build
USES=		gmake iconv jpeg tk perl5

# Optimization flags will be defined by the source
CFLAGS:=	${CFLAGS:C/^-O.*$//}
FFLAGS:=	${CFLAGS:C/^-O.*$//}

MAKE_ENV+=	SAGE_PORT=yes \
		SAGE_ATLAS_LIB=${LOCALBASE}/lib \
		DOT_SAGE=${WRKSRC}/tmp/.sage \
		SAGE_FAT_BINARY=yes \
		PERL=${PERL}

# The following is needed for the lapack subpackage.
MAKE_ARGS+=	ARCH="${AR}"

post-patch:
# Create wrapper for invocation of make.
	@${MKDIR} ${WRKSRC}/local/bin
	@${LN} -s -f ${LOCALBASE}/bin/gmake ${WRKSRC}/local/bin/make

# Create wrapper for invocation of ld.
	@${SED} -e 's#%%LD%%#${LOCALBASE}/bin/ld#' \
		${FILESDIR}/ld.in > ${WRKSRC}/local/bin/ld
	@${CHMOD} +x ${WRKSRC}/local/bin/ld

post-build:
	${RM} -r ${WRKSRC}/tmp/.sage
	${CHMOD} -R a+rX ${WRKSRC}

check regression-test test: build
	@${ECHO_MSG} This test can also be performed after installation by typing \"sage -testall\".
	@${ECHO_MSG}
	cd ${WRKSRC} && ${SETENV} DOT_SAGE=${WRKSRC}/tmp/.sage ./sage -testall
	${RM} ${WRKSRC}/python*.core

# Don't build docs (because of mysterious race conditions).
ALL_TARGET=	build

INSTALL_SAGE_DIR=	${PREFIX}/${PORTNAME}-${PORTVERSION}
STAGED_SAGE_DIR=	${STAGEDIR}${INSTALL_SAGE_DIR}
do-install:
	cd ${WRKDIR} && ${FIND} -s ${WRKSRC} | \
		${GREP} -v '^${WRKSRC}/upstream/' | \
		${GREP} -v '^${WRKSRC}/tmp' | \
		${SED} -e 's#${WRKDIR}/##' | \
		${CPIO} -pmud -R ${BINOWN}:${BINGRP} ${STAGEDIR}${PREFIX}
	${ECHO_CMD} | ${SETENV} DOT_SAGE=${STAGED_SAGE_DIR}/tmp/.sage ${STAGED_SAGE_DIR}/sage
	${RM} -r ${STAGED_SAGE_DIR}/tmp/.sage
	${SED} -e "s+#SAGE_ROOT.*+SAGE_ROOT=${INSTALL_SAGE_DIR}+" ${WRKSRC}/sage > ${STAGEDIR}${PREFIX}/bin/sage
	${CHMOD} ${BINMODE} ${STAGEDIR}${PREFIX}/bin/sage

post-install:
	@${FIND} -s ${STAGED_SAGE_DIR} -not -type d | \
		${SED} -e 's#${STAGEDIR}${PREFIX}/##' >> ${TMPPLIST}
	@${FIND} -s ${STAGED_SAGE_DIR} -type d -empty | \
		${SED} -e 's#${STAGEDIR}${PREFIX}/#@dir #' >> ${TMPPLIST}

.include <bsd.port.pre.mk>

MAKE_ENV+=	MAKE="${MAKE} -j${MAKE_JOBS_NUMBER}"

.ifdef MAINTAINER_MODE
test-fbsd-patches:	patch
	${RM} -r ${WRKSRC}/build/pkgs/*/src; \
	for d in ${WRKSRC}/build/pkgs/*; do \
		if ls $$d/fbsd-patch-* > /dev/null 2>&1; then \
			${ECHO_MSG} Testing patches in $${d##*/}; \
			b=$${d##*/}-`${CAT} $$d/package-version.txt | ${SED} 's/\.p.*//'`; \
			c=${WRKSRC}/upstream/$$b.tar.bz2 ; \
			if [ ! -e $$c ]; then \
				c=${WRKSRC}/upstream/$$b.tar.gz ; \
				if [ ! -e $$c ]; then \
					${ECHO_MSG} Couldn\'t find $$c; \
					exit 1; \
				fi; \
			fi; \
			b=`echo $$b | sed 's/python/Python/'` ; \
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
	${RM} -r ${WRKSRC}/build/pkgs/*/src
.endif

.include <bsd.port.post.mk>
