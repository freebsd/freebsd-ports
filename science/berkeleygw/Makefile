PORTNAME=	BerkeleyGW
DISTVERSION=	4.0
PORTREVISION=	2
CATEGORIES=	science
MASTER_SITES=	https://app.box.com/shared/static/
DISTFILES=	22edl07muvhfnd900tnctsjjftbtcqc4.gz

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Scientific program aimed at the ab initio virtual experimentation
WWW=		https://berkeleygw.org

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/license.txt

BROKEN_powerpc64le=	compilation fails: Error: Unclassifiable statement at (1) (for this syntax in Common/typedefs.f90:578: SCALAR :: epshead !< head of dielectric matrix at q->0)

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libfftw3.so:math/fftw3
RUN_DEPENDS=	bash:shells/bash

USES=		blaslapack:openblas gmake fortran:gfortran python shebangfix

SHEBANG_GLOB=	*.sh *.py *awk

BINARY_ALIAS=	make=${GMAKE} gcc=${CC}

MAKE_ARGS=	FREEBSD_GCC_DEFAULT=${GCC_DEFAULT} FREEBSD_PREFIX=${PREFIX} INSTDIR=${STAGEDIR}${PREFIX}

TEST_TARGET=	check # 2 testcases fail: https://groups.google.com/a/berkeleygw.org/g/help/c/jVdxCAzM7A4

OPTIONS_DEFINE=	EXAMPLES

EXAMPLES_MAKE_ARGS=	INSTALL_EXAMPLES=yes

PORTEXAMPLES=	*

.include <bsd.port.pre.mk>

.if ${GCC_DEFAULT} >= 10
BROKEN_i386=	f951: internal compiler error: Segmentation fault
.endif

post-patch:
	@${LN} -s ${WRKSRC}/config/generic.serial.freebsd.mk ${WRKSRC}/arch.mk
	@${LN} -s ${WRKSRC}/flavor_real.mk ${WRKSRC}/flavor.mk
	@${FIND} ${WRKSRC} -name "script*" -o -name "*.scr" | ${XARGS} ${REINPLACE_CMD} -i '' 's|#! */bin/bash.*|#!/bin/sh|'
	# fix bad shebang
	@${REINPLACE_CMD} -e 's|^#!/.*|#!${PYTHON_CMD}|' ${WRKSRC}/Sigma/unfold_sigma.py

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*.x

.include <bsd.port.post.mk>
