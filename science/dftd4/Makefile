PORTNAME=	dftd4
DISTVERSIONPREFIX=	v
DISTVERSION=	3.3.0
CATEGORIES=	science # chemistry

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Atomic-charge dependent london dispersion correction computation

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	mstore>0:science/mstore
LIB_DEPENDS=	libmctc-lib.so:science/mctc-lib \
		libmulticharge.so:science/multicharge \
		libopenblas.so:math/openblas

USES=		cmake:testing fortran
USE_GITHUB=	yes
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS

.include <bsd.port.mk>
