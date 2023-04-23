PORTNAME=	h5z-zfp
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Registered ZFP compression plugin for HDF5
WWW=		https://h5z-zfp.readthedocs.io/en/latest/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libhdf5.so:science/hdf5 \
		libzfp.so:devel/zfp

USES=		cmake fortran localbase
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	LLNL
GH_PROJECT=	${PORTNAME:tu}

OPTIONS_DEFINE=		FORTRAN

FORTRAN_CMAKE_BOOL=	FORTRAN_INTERFACE

.include <bsd.port.mk>
