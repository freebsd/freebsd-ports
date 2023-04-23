PORTNAME=	libxc
DISTVERSION=	6.0.0
PORTREVISION=	1
CATEGORIES=	science
MASTER_SITES=	https://www.tddft.org/programs/${PORTNAME}/down/${DISTVERSION}/

MAINTAINER=	jmd@FreeBSD.org
COMMENT=	Library of exchange-correlation functionals for DFT
WWW=		https://www.tddft.org/programs/libxc/

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake:testing fortran python
USE_LDCONFIG=	yes
TEST_DEPENDS=	bash:shells/bash

CMAKE_ON=	BUILD_SHARED_LIBS ENABLE_FORTRAN ENABLE_PYTHON
CMAKE_OFF=	BUILD_TESTING

pre-configure:
	${REINPLACE_CMD} -e 's|$${CMAKE_INSTALL_LIBDIR}/pylibxc$$|${PYTHONPREFIX_SITELIBDIR}/pylibxc|'	\
		-e 's|$${CMAKE_INSTALL_PREFIX}/$${CMAKE_INSTALL_LIBDIR}/pylibxc/|${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/pylibxc/|'\
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
