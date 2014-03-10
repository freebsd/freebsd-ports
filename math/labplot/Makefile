# Created by: Kay Lehmann <kay_lehmann@web.de>
# $FreeBSD$

PORTNAME=	labplot
DISTVERSION=	2.0.0.beta2
PORTREVISION=	2
CATEGORIES=	math kde
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION:R}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Data plotting and function analysis tool for KDE

LICENCE=	GPLv2

LIB_DEPENDS=	libgsl.so:${PORTSDIR}/math/gsl

OPTIONS_DEFINE=	CDF HDF5 NETCDF
CDF_DESC=	CDF data support
HDF5_DESC=	HDF5 data support
NETCDF_DESC=	NetCDF data support

WRKSRC=		${WRKDIR}/beta2

USE_BZIP2=	yes
USES=		cmake shared-mime-info
USE_XORG=	xft xpm
USE_GCC=	yes
USE_KDE4=	automoc4 kdelibs kdeprefix
USE_QT4=	moc_build qmake_build rcc_build uic_build
CMAKE_ARGS=	-DOPJ_LIBRARY:STRING=""
INSTALLS_ICONS=	yes

CDF_LIB_DEPENDS=	libcdf.so:${PORTSDIR}/science/cdf
CDF_CMAKE_OFF=		-DCDF_LIBRARY:STRING=""

HDF5_LIB_DEPENDS=	libhdf5.so:${PORTSDIR}/science/hdf5	
HDF5_CMAKE_OFF=		-DHDF5_LIBRARY:STRING=""

NETCDF_LIB_DEPENDS=	libnetcdf.so:${PORTSDIR}/science/netcdf
NETCDF_CMAKE_OFF=	-DNETCDF_LIBRARY:STRING=""

post-patch:
	@${REINPLACE_CMD} -e \
		's|/usr/local/|${LOCALBASE}/|g' ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e \
		's|i->\(children<T>\)|\1|' \
		${WRKSRC}/src/backend/core/AbstractAspect.h
	@${REINPLACE_CMD} -e \
		's|!isnan|!std::isnan|' \
		${WRKSRC}/src/backend/worksheet/plots/cartesian/CartesianCoordinateSystem.cpp 

.include <bsd.port.mk>
