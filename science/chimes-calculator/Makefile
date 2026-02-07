PORTNAME=	chimes-calculator
DISTVERSIONPREFIX=	v.
DISTVERSION=	1.0.2
PORTREVISION=	1
CATEGORIES=	science # chemistry

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Chebyshev Interaction Model for Efficient Simulation
WWW=		https://github.com/rk-lindsey/chimes_calculator

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing fortran shebangfix python:test
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	rk-lindsey
GH_PROJECT=	${PORTNAME:C/-/_/}

SHEBANG_GLOB=	*.sh

post-patch:
	@${REINPLACE_CMD} -e 's|PYTH3=python.*|PYTH3=${PYTHON_CMD}|' ${WRKSRC}/serial_interface/tests/run_tests.sh

.include <bsd.port.mk>
