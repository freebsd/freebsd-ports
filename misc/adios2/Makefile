PORTNAME=	adios2
DISTVERSIONPREFIX=	v
DISTVERSION=	2.7.1
CATEGORIES=	misc science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Next generation of ADIOS developed in the Exascale Computing Program

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	constant expression evaluates to 18446744073709551613 which cannot be narrowed to type 'unsigned int': https://github.com/ornladios/ADIOS2/issues/2469
BROKEN_powerpc=	constant expression evaluates to 18446744073709551613 which cannot be narrowed to type 'unsigned int': https://github.com/ornladios/ADIOS2/issues/2469

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libblosc.so:archivers/c-blosc \
		libepoll-shim.so:devel/libepoll-shim \
		libfabric.so:net/libfabric \
		libffi.so:devel/libffi \
		libhdf5.so:science/hdf5 \
		libmpi.so:net/openmpi \
		libpng.so:graphics/png \
		libsz.so:science/szip \
		libzmq.so:net/libzmq4 \
		libzfp.so:devel/zfp
RUN_DEPENDS=	bash:shells/bash

USES=		bison cmake compiler:c++11-lang fortran localbase:ldflags pkgconfig \
		perl5 python shebangfix
SHEBANG_FILES=	cmake/install/post/adios2-config.pre.sh.in cmake/install/post/generate-adios2-config.sh.in source/utils/bp4dbg/bp4dbg.py \
		source/utils/adios_deactivate_bp.sh source/utils/adios_reorganize/adios2_reorganize_wrapper
USE_GITHUB=	yes
GH_ACCOUNT=	ornladios
GH_PROJECT=	ADIOS2
USE_LDCONFIG=	yes

CMAKE_OFF=	BUILD_TESTING
LDFLAGS+=	-lepoll-shim

.include <bsd.port.mk>
