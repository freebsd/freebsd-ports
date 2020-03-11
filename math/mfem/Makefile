# $FreeBSD$

PORTNAME=	mfem
DISTVERSIONPREFIX=	v
DISTVERSION=	4.1
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Lightweight, general, scalable C++ library for finite element methods

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++11-lang
USE_GITHUB=	yes
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS

OPTIONS_DEFINE=	MPI

MPI_CMAKE_BOOL=	MFEM_USE_MPI
MPI_BROKEN=	see https://github.com/mfem/mfem/issues/622

.include <bsd.port.mk>
