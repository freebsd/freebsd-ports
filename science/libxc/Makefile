PORTNAME=	libxc
DISTVERSION=	7.0.0
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library of exchange-correlation functionals for DFT
WWW=		https://gitlab.com/libxc/libxc

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/COPYING

TEST_DEPENDS=	bash:shells/bash

USES=		cmake:testing fortran python
USE_LDCONFIG=	yes

USE_GITLAB=	yes

CMAKE_ON=	BUILD_SHARED_LIBS ENABLE_FORTRAN ENABLE_PYTHON
CMAKE_OFF=	BUILD_TESTING DISABLE_KXC ENABLE_XHOST

pre-configure:
	${REINPLACE_CMD} -e 's|$${CMAKE_INSTALL_LIBDIR}/pylibxc$$|${PYTHONPREFIX_SITELIBDIR}/pylibxc|'	\
		-e 's|$${CMAKE_INSTALL_PREFIX}/$${CMAKE_INSTALL_LIBDIR}/pylibxc/|${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/pylibxc/|'\
		${WRKSRC}/CMakeLists.txt

# tests as of 7.0.0: 100% tests passed, 0 tests failed out of 20556

.include <bsd.port.mk>
