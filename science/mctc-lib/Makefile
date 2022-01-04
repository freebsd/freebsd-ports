PORTNAME=	mctc-lib
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.3
CATEGORIES=	science # chemistry

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Computation tool chain library to work with molecular structure data

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing fortran
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	grimme-lab

CMAKE_ON=	BUILD_SHARED_LIBS

.include <bsd.port.mk>
