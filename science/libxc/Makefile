PORTNAME=	libxc
DISTVERSION=	5.2.3
PORTREVISION=	1
CATEGORIES=	science
MASTER_SITES=	https://www.tddft.org/programs/${PORTNAME}/down/${DISTVERSION}/

MAINTAINER=	jmd@FreeBSD.org
COMMENT=	Library of exchange-correlation functionals for DFT

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake:testing fortran
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS ENABLE_FORTRAN
CMAKE_OFF=	BUILD_TESTING

.include <bsd.port.mk>
