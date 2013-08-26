# Created by: Kay Lehmann <kay_lehmann@web.de>
# $FreeBSD$

PORTNAME=	labplot
DISTVERSION=	2.0.0.alpha3
PORTREVISION=	1
CATEGORIES=	math kde
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION:R}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Data plotting and function analysis tool for KDE

LICENSE=	GPLv2

LIB_DEPENDS=	gsl:${PORTSDIR}/math/gsl

OPTIONS_DEFINE=	CDF HDF5 NETCDF
CDF_DESC=	CDF data support
HDF5_DESC=	HDF5 data support
NETCDF_DESC=	NetCDF data support

USE_BZIP2=	yes
USE_XORG=	xft xpm
USE_KDE4=	automoc4 kdelibs kdeprefix
USE_QT4=	moc_build qmake_build rcc_build uic_build
USES=		cmake
CMAKE_ARGS=	-DOPJ_LIBRARY:STRING=""

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCDF}
LIB_DEPENDS+=	cdf:${PORTSDIR}/science/cdf
.else
CMAKE_ARGS+=	-DCDF_LIBRARY:STRING=""
.endif

.if ${PORT_OPTIONS:MHDF5}
LIB_DEPENDS+=	hdf5:${PORTSDIR}/science/hdf5
.else
CMAKE_ARGS+=	-DHDF5_LIBRARY:STRING=""
.endif

.if ${PORT_OPTIONS:MNETCDF}
LIB_DEPENDS+=	netcdf:${PORTSDIR}/science/netcdf
.else
CMAKE_ARGS+=	-DNETCDF_LIBRARY:STRING=""
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|/usr/local/|${LOCALBASE}/|g' ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e \
		's|i->\(children<T>\)|\1|' \
		${WRKSRC}/src/backend/core/AbstractAspect.h

.include <bsd.port.mk>
