PORTNAME=	libxc
DISTVERSION=	6.2.2
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
GL_TAGNAME=	0a19bedb24d258b2019eb2d027c1b1039d3e6503

CMAKE_ON=	BUILD_SHARED_LIBS ENABLE_FORTRAN ENABLE_PYTHON
CMAKE_OFF=	BUILD_TESTING DISABLE_KXC ENABLE_XHOST

pre-configure:
	${REINPLACE_CMD} -e 's|$${CMAKE_INSTALL_LIBDIR}/pylibxc$$|${PYTHONPREFIX_SITELIBDIR}/pylibxc|'	\
		-e 's|$${CMAKE_INSTALL_PREFIX}/$${CMAKE_INSTALL_LIBDIR}/pylibxc/|${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/pylibxc/|'\
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
