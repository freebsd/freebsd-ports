PORTNAME=	libminc
PORTVERSION=	2.5.0
DISTVERSIONPREFIX=	release-
CATEGORIES=	science biology

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Core library and API of the MINC toolkit
WWW=		https://www.bic.mni.mcgill.ca/ServicesSoftware/MINC

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	nifticlib>0:science/nifticlib
LIB_DEPENDS=	libhdf5.so:science/hdf5	\
		libnetcdf.so:science/netcdf

USES=		cmake:testing localbase
CMAKE_ON=	LIBMINC_BUILD_SHARED_LIBS	\
		LIBMINC_MINC1_SUPPORT	\
		LIBMINC_USE_NIFTI LIBMINC_USE_SYSTEM_NIFTI

USE_GITHUB=	yes
GH_ACCOUNT=	BIC-MNI

USE_LDCONFIG=	yes

.include <bsd.port.mk>
