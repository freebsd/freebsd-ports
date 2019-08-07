# $FreeBSD$

PORTNAME=	adios2
DISTVERSIONPREFIX=	v
DISTVERSION=	2.4.0
CATEGORIES=	misc science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Next generation of ADIOS developed in the Exascale Computing Program

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libblosc.so:archivers/c-blosc \
		libfabric.so:net/libfabric \
		libffi.so:devel/libffi \
		libmpi.so:net/openmpi \
		libpng.so:graphics/png \
		libzfp.so:devel/zfp
RUN_DEPENDS=	bash:shells/bash

USES=		bison cmake pkgconfig perl5 python shebangfix
SHEBANG_FILES=	cmake/install/post/adios2-config.pre.sh.in cmake/install/post/generate-adios2-config.sh.in source/utils/bp4dbg/bp4dbg.py
USE_GITHUB=	yes
GH_ACCOUNT=	ornladios
GH_PROJECT=	ADIOS2
USE_LDCONFIG=	yes

CMAKE_OFF=	BUILD_TESTING

.include <bsd.port.mk>
