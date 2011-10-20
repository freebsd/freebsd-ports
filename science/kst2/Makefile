# New ports collection makefile for:	kst
# Date created:			Fri Apr 30 17:28:56 CEST 2004
# Whom:				Markus Brueffer <markus@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	kst
DISTVERSION=	2.0.4
CATEGORIES=	science kde
MASTER_SITES=	SF/${PORTNAME}/Kst%20${DISTVERSION:C/-r.*//}/

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Data viewing and plotting tool

LIB_DEPENDS=	gsl.16:${PORTSDIR}/math/gsl

LATEST_LINK=	kst2

USE_CMAKE=	yes
USE_QT_VER=	4
QT_COMPONENTS=	gui xml designer svg opengl \
		qmake_build moc_build rcc_build uic_build
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

CMAKE_SOURCE_PATH=	${WRKSRC}/cmake
CMAKE_ARGS+=	-Dkst_install_prefix=${PREFIX}

MAN1=		kst2.1

OPTIONS=	FITS "Support for data in FITS format" off \
		NETCDF "Support for data in NetCDF format" off

.include <bsd.port.options.mk>

.if defined(WITH_FITS)
LIB_DEPENDS+=	cfitsio.0:${PORTSDIR}/astro/cfitsio
PLIST_SUB+=	FITS=""
.else
PLIST_SUB+=	FITS="@comment "
.endif

.if defined(WITH_NETCDF)
LIB_DEPENDS+=	netcdf.4:${PORTSDIR}/science/netcdf
PLIST_SUB+=	NETCDF=""
.else
PLIST_SUB+=	NETCDF="@comment "
.endif

post-patch:
	${REINPLACE_CMD} -e '/^Exec=kst2/s,\(kst2\).*,\1 %f,' \
		${WRKSRC}/src/kst/kst2.desktop

pre-configure:
.if !defined(WITH_FITS)
	${REINPLACE_CMD} -e '/find_package(CFITSIO)/d' \
		${CMAKE_SOURCE_PATH}/CMakeLists.txt
.endif
.if !defined(WITH_NETCDF)
	${REINPLACE_CMD} -e '/find_package(Netcdf)/d' \
		${CMAKE_SOURCE_PATH}/CMakeLists.txt
.endif

.include <bsd.port.mk>
