PORTNAME=	tblite
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.0
CATEGORIES=	science # chemistry

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Light-weight tight-binding framework

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	mstore>0:science/mstore # unclear if this is really needed
LIB_DEPENDS=	libdftd4.so:science/dftd4 \
		libmctc-lib.so:science/mctc-lib \
		libmulticharge.so:science/multicharge \
		libopenblas.so:math/openblas \
		libs-dftd3.so:science/simple-dftd3 \
		libtoml-f.so:textproc/toml-f

USES=		cmake:testing fortran
USE_GITHUB=	yes
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS

.include <bsd.port.mk>
