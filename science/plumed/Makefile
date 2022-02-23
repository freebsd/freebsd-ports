PORTNAME=	plumed
DISTVERSIONPREFIX=	v
DISTVERSION=	2.8.0
CATEGORIES=	science graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	PLUgin for MolEcular Dynamics

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

BROKEN_i386=	undefined reference to `__atomic_load'

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libblas.so:math/blas \
		libfftw3.so:math/fftw3 \
		libgsl.so:math/gsl \
		liblapack.so:math/lapack
RUN_DEPENDS=	bash:shells/bash
TEST_DEPENDS=	gawk:lang/gawk

USES=		autoreconf compiler:c++11-lang gmake localbase pkgconfig shebangfix
USE_LDCONFIG=	yes

SHEBANG_GLOB=	*.sh
SHEBANG_FILES=	src/maketools/makecmd \
		src/maketools/xxd \
		regtest/scripts/check \
		regtest/scripts/run \
		regtest/scripts/what

USE_GITHUB=	yes
GH_PROJECT=	plumed2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared --disable-python

TEST_TARGET=	check # the 'installcheck' target checks installed version
# 1 test is known to fail: https://github.com/plumed/plumed2/issues/782

BINARY_ALIAS=	make=${GMAKE} # only needed for tests

post-patch:
	@${REINPLACE_CMD} -e 's|#! /bin/bash|#! ${LOCALBASE}/bin/bash|' ${WRKSRC}/src/lib/Makefile

post-install:
	@${RMDIR} ${STAGEDIR}${PREFIX}/lib/plumed/obj
	@cd ${STAGEDIR}${PREFIX} && ${STRIP_CMD} bin/plumed lib/plumed/plumed-runtime lib/libplumed.so lib/libplumedKernel.so

.include <bsd.port.mk>
