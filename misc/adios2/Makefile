PORTNAME=	adios2
DISTVERSIONPREFIX=	v
DISTVERSION=	2.10.2
PORTREVISION=	1
CATEGORIES=	misc science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Next generation of ADIOS developed in the Exascale Computing Program
WWW=		https://github.com/ornladios/ADIOS2

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_armv7=	compilation fails: non-constant-expression cannot be narrowed from type 'uint64_t' (aka 'unsigned long long') to 'size_t' (aka 'unsigned int') in initializer list [-Wc++11-narrowing]
BROKEN_i386=	constant expression evaluates to 18446744073709551613 which cannot be narrowed to type 'unsigned int': https://github.com/ornladios/ADIOS2/issues/2469
BROKEN_powerpc=	constant expression evaluates to 18446744073709551613 which cannot be narrowed to type 'unsigned int': https://github.com/ornladios/ADIOS2/issues/2469

PY_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}mpi4py-mpich>=3.0.3:net/py-mpi4py-mpich@${PY_FLAVOR}
BUILD_DEPENDS=	bash:shells/bash \
		pybind11>0:devel/pybind11 \
		${PYTHON_PKGNAMEPREFIX}pybind11>=2.4:devel/py-pybind11@${PY_FLAVOR} \
		${PY_DEPENDS}
LIB_DEPENDS=	libblosc2.so:archivers/c-blosc2 \
		libepoll-shim.so:devel/libepoll-shim \
		libfabric.so:net/libfabric \
		libhdf5.so:science/hdf5 \
		liblz4.so:archivers/liblz4 \
		libmpi.so:net/mpich \
		libpng16.so:graphics/png \
		libsodium.so:security/libsodium \
		libzmq.so:net/libzmq4 \
		libzfp.so:devel/zfp \
		libzstd.so:archivers/zstd
RUN_DEPENDS=	bash:shells/bash \
		${PY_DEPENDS}

USES=		bison cmake:testing compiler:c++11-lang fortran localbase:ldflags pkgconfig \
		perl5 python shebangfix sqlite
USE_LDCONFIG=	yes

SHEBANG_FILES=	cmake/install/post/adios2-config.pre.sh.in cmake/install/post/generate-adios2-config.sh.in \
		source/utils/adios_reorganize/adios2_reorganize_wrapper source/utils/adios2_deactivate_bp
SHEBANG_GLOB=	*.sh *.py

USE_GITHUB=	yes
GH_ACCOUNT=	ornladios
GH_PROJECT=	ADIOS2

CMAKE_ARGS=	-DFREEBSD_PYTHON_VERSION=${PYTHON_VER}
CMAKE_OFF=	BUILD_TESTING ADIOS2_BUILD_EXAMPLES
LDFLAGS+=	-lepoll-shim

OPTIONS_DEFINE=	DOCS

DOCSDIR=	${PREFIX}/share/doc/ADIOS2
PORTDOCS=	*

# several tests fail, see https://github.com/ornladios/ADIOS2/issues/3286

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/adios2/bindings/adios2_bindings${PYTHON_TAG}.so

.include <bsd.port.mk>
