PORTNAME=	adios2
DISTVERSIONPREFIX=	v
DISTVERSION=	2.8.2
PORTREVISION=	1
CATEGORIES=	misc science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Next generation of ADIOS developed in the Exascale Computing Program

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	constant expression evaluates to 18446744073709551613 which cannot be narrowed to type 'unsigned int': https://github.com/ornladios/ADIOS2/issues/2469
BROKEN_powerpc=	constant expression evaluates to 18446744073709551613 which cannot be narrowed to type 'unsigned int': https://github.com/ornladios/ADIOS2/issues/2469

PY_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}mpi4py>=3.0.3:net/py-mpi4py@${PY_FLAVOR}
BUILD_DEPENDS=	bash:shells/bash \
		pybind11>0:devel/pybind11 \
		${PYTHON_PKGNAMEPREFIX}pybind11>=2.4:devel/py-pybind11@${PY_FLAVOR} \
		${PY_DEPENDS}
LIB_DEPENDS=	libblosc.so:archivers/c-blosc \
		libepoll-shim.so:devel/libepoll-shim \
		libfabric.so:net/libfabric \
		libffi.so:devel/libffi \
		libhdf5.so:science/hdf5 \
		libmpi.so:net/mpich \
		libpng.so:graphics/png \
		libsodium.so:security/libsodium \
		libsz.so:science/libaec \
		libzmq.so:net/libzmq4 \
		libzfp.so:devel/zfp
RUN_DEPENDS=	bash:shells/bash \
		${PY_DEPENDS}

USES=		bison cmake:testing compiler:c++11-lang fortran localbase:ldflags pkgconfig \
		perl5 python shebangfix
USE_LDCONFIG=	yes

SHEBANG_FILES=	cmake/install/post/adios2-config.pre.sh.in cmake/install/post/generate-adios2-config.sh.in \
		source/utils/adios_reorganize/adios2_reorganize_wrapper source/utils/adios2_deactivate_bp
SHEBANG_GLOB=	*.sh *.py

USE_GITHUB=	yes
GH_ACCOUNT=	ornladios
GH_PROJECT=	ADIOS2

CMAKE_ARGS=	-DFREEBSD_PYTHON_VERSION=${PYTHON_VER}
CMAKE_OFF=	BUILD_TESTING
LDFLAGS+=	-lepoll-shim

OPTIONS_DEFINE=	DOCS

DOCSDIR=	${PREFIX}/share/doc/ADIOS2
PORTDOCS=	*

# several tests fail, see https://github.com/ornladios/ADIOS2/issues/3286

.include <bsd.port.mk>
