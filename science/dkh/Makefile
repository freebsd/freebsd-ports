PORTNAME=	dkh
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2
PORTREVISION=	5
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Wolf, Reiher, and Hess's Douglas-Kroll-Hess relativistic correction

LICENSE=	GPLv3

USES=		cmake fortran
USE_GITHUB=	yes
GH_ACCOUNT=	psi4
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DBUILD_SHARED_LIBS:BOOL=ON

.include <bsd.port.mk>
