PORTNAME=	dkh
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2
PORTREVISION=	6
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Wolf, Reiher, and Hess's Douglas-Kroll-Hess relativistic correction
WWW=		http://www.reiher.ethz.ch/software/dkh-x2c.html

LICENSE=	GPLv3

USES=		cmake fortran
.if !exists(/usr/include/omp.h)
CMAKE_OFF=	ENABLE_OPENMP
.endif
USE_GITHUB=	yes
GH_ACCOUNT=	psi4
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DBUILD_SHARED_LIBS:BOOL=ON

.include <bsd.port.mk>
