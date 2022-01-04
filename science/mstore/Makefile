PORTNAME=	mstore
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.0
CATEGORIES=	science # chemistry

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Molecular structure store for testing

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libmctc-lib.so:science/mctc-lib

USES=		cmake fortran
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	grimme-lab

CMAKE_ON=	BUILD_SHARED_LIBS

.include <bsd.port.mk>
