PORTNAME=	erd
DISTVERSIONPREFIX=	v
DISTVERSION=	3.0.6
PORTREVISION=	6
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	AcesIII electron repulsion integrals
WWW=		https://github.com/psi4/erd

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake fortran
.if !exists(/usr/include/omp.h)
CMAKE_OFF=	ENABLE_OPENMP
.endif
USE_GITHUB=	yes
GH_ACCOUNT=	psi4
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DBUILD_SHARED_LIBS:BOOL=ON \
		-DENABLE_XHOST:BOOL=OFF

.include <bsd.port.mk>
