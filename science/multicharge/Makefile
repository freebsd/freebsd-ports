PORTNAME=	multicharge
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.2
CATEGORIES=	science # chemistry

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Electronegativity equilibration model for atomic partial charges

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	mstore>0:science/mstore
LIB_DEPENDS=	libmctc-lib.so:science/mctc-lib \
		libopenblas.so:math/openblas

USES=		cmake:testing fortran
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	grimme-lab

CMAKE_ON=	BUILD_SHARED_LIBS

.include <bsd.port.mk>
