# Created by: Kay Lehmann <kay_lehmann@web.de>
# $FreeBSD$

PORTNAME=	labplot
DISTVERSION=	2.0.0.beta1
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

USE_BZIP2=	yes
USES=		cmake
USE_XORG=	xft xpm
USE_GCC=	yes
USE_KDE4=	automoc4 kdelibs kdeprefix
USE_QT4=	moc_build qmake_build rcc_build uic_build
CMAKE_ARGS=	-DOPJ_LIBRARY:STRING=""

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCDF}
LIB_DEPENDS+=	libcdf.so:${PORTSDIR}/science/cdf
.else
CMAKE_ARGS+=	-DCDF_LIBRARY:STRING=""
.endif

.if ${PORT_OPTIONS:MHDF5}
LIB_DEPENDS+=	libhdf5.so:${PORTSDIR}/science/hdf5
.else
CMAKE_ARGS+=	-DHDF5_LIBRARY:STRING=""
.endif

.if ${PORT_OPTIONS:MNETCDF}
LIB_DEPENDS+=	libnetcdf.so:${PORTSDIR}/science/netcdf
.else
CMAKE_ARGS+=	-DNETCDF_LIBRARY:STRING=""
.endif

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
