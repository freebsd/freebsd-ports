PORTNAME=	libxc
DISTVERSION=	7.1.2
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

LDFLAGS+=	-lexecinfo

CMAKE_ON=	BUILD_SHARED_LIBS ENABLE_FORTRAN ENABLE_PYTHON
CMAKE_OFF=	BUILD_TESTING DISABLE_KXC ENABLE_XHOST
TEST_ENV=	${MAKE_ENV} PYTEST_DISABLE_PLUGIN_AUTOLOAD=1

pre-configure:
	${REINPLACE_CMD} -e 's|$${CMAKE_INSTALL_LIBDIR}/pylibxc$$|${PYTHONPREFIX_SITELIBDIR}/pylibxc|'	\
		-e 's|$${CMAKE_INSTALL_PREFIX}/$${CMAKE_INSTALL_LIBDIR}/pylibxc/|${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/pylibxc/|'\
		${WRKSRC}/CMakeLists.txt

pre-test:
	@${LN} -sf ${BUILD_WRKSRC}/libxc.so ${WRKSRC}/pylibxc/libxc.so

# tests as of 7.1.2: 100% tests passed, 0 tests failed out of 23

.include <bsd.port.mk>
