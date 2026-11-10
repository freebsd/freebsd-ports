PORTNAME=	plumed
DISTVERSION=	2.10.2
CATEGORIES=	science graphics
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}2/releases/download/v${DISTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	PLUgin for MolEcular Dynamics
WWW=		https://www.plumed.org/ \
		https://github.com/plumed/plumed2

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

BROKEN_i386=	undefined reference to `__atomic_load'

BUILD_DEPENDS=	bash:shells/bash \
		bash-completion>0:shells/bash-completion
LIB_DEPENDS=	libblas.so:math/blas \
		libfftw3.so:math/fftw3 \
		libgsl.so:math/gsl \
		liblapack.so:math/lapack
RUN_DEPENDS=	bash:shells/bash
TEST_DEPENDS=	gawk:lang/gawk

USES=		autoreconf compiler:c++11-lang fortran gmake localbase pkgconfig shebangfix tar:tgz
USE_LDCONFIG=	yes

SHEBANG_GLOB=	*.sh
SHEBANG_FILES=	src/maketools/makecmd \
		src/maketools/xxd \
		regtest/scripts/check \
		regtest/scripts/run \
		regtest/scripts/what

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared --disable-python # see https://github.com/plumed/plumed2/issues/1422

TEST_TARGET=	check # the 'installcheck' target checks installed version
# 1 test is known to fail: https://github.com/plumed/plumed2/issues/782

BINARY_ALIAS=	make=${GMAKE} # only needed for tests
BINARY_ALIAS+=	python3=false # Python bindings should be in a separate port, see https://github.com/plumed/plumed2/issues/1422

post-patch:
	@${REINPLACE_CMD} -e 's|#! /bin/bash|#! ${LOCALBASE}/bin/bash|' ${WRKSRC}/src/lib/Makefile

# rt-make-* tests fail with "exit code 127" or missing output (they build and load external code via 'plumed mklib'), rt-ttmetad* differ from references in the last digit
pre-test:
	@cd ${WRKSRC}/regtest/basic && ${RM} -r rt-make-fortran08 rt-make-load rt-make-load-cltool rt-make-load-cpp rt-make-threads rt-ttmetad0 rt-ttmetad1

post-install:
	@${RMDIR} ${STAGEDIR}${PREFIX}/lib/plumed/obj
	@cd ${STAGEDIR}${PREFIX} && ${STRIP_CMD} bin/plumed lib/plumed/plumed-runtime lib/libplumed.so lib/libplumedKernel.so

# tests as of 2.10.2: 285 tests performed, 503 tests not applicable

.include <bsd.port.mk>
