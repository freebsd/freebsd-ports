# Created by: Kurt Kanzenbach <kurt@kmk-computers.de>
# $FreeBSD$

PORTNAME=		libgeodecomp
PORTVERSION=		0.4.0
PORTREVISION=		14
CATEGORIES=		science devel
MASTER_SITES=		http://www.libgeodecomp.org/archive/

MAINTAINER=		kurt@kmk-computers.de
COMMENT=		LibGeoDecomp is an auto-parallelizing library for computer simulations

LICENSE=		BSL
LICENSE_FILE=		${WRKSRC}/LICENSE

LIB_DEPENDS=		libboost_system.so:devel/boost-libs libboost_date_time.so:devel/boost-libs \
			libboost_filesystem.so:devel/boost-libs

USES=			cmake:outsource compiler:c++11-lib
USE_GCC=		yes
USE_LDCONFIG=		yes

CMAKE_ARGS=		-DWITH_CUDA:BOOL=FALSE -DWITH_VISIT:BOOL=FALSE \
			-DWITH_HPX:BOOL=FALSE -DWITH_OPENCL:BOOL=FALSE \
			-DWITH_OPENCV:BOOL=FALSE -DWITH_TYPEMAPS=FALSE

OPTIONS_DEFINE=		MPI QT4 SILO SCOTCH
OPTIONS_DEFAULT=	MPI SILO SCOTCH

MPI_LIB_DEPENDS=	libmpich.so:net/mpich2
MPI_CMAKE_BOOL=		WITH_MPI

QT4_USES=	qt:4
QT4_USE=		QT=corelib,gui,opengl,qmake_build,moc_build,rcc_build,uic_build
QT4_CMAKE_BOOL=		WITH_QT

SILO_DESC=		Enable Silo dependend output
SILO_LIB_DEPENDS=	libsiloh5.so:science/silo
SILO_CMAKE_BOOL=	WITH_SILO

SCOTCH_DESC=		Enable graph partitioning based on Scotch/Scotch-PT
SCOTCH_BUILD_DEPENDS=	${LOCALBASE}/lib/libscotch.a:cad/scotch
SCOTCH_CMAKE_BOOL=	WITH_SCOTCH

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MQT4}
DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15
.endif

.include <bsd.port.mk>
