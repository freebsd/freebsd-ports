PORTNAME=	minorminer
DISTVERSION=	0.2.9
CATEGORIES=	math python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Heuristic tool for minor embedding of graphs

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fasteners>=0.15:devel/py-fasteners@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}homebase>=1.0.1:devel/py-homebase@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}networkx>=2.4:math/py-networkx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dwave-networkx>=0.8.11:science/py-dwave-networkx@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}rectangle-packer>=2.0.1:math/py-rectangle-packer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.8.0:science/py-scipy@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS}

USES=		python:3.6+
USE_PYTHON=	distutils cython autoplist

USE_GITHUB=	yes
GH_ACCOUNT=	dwavesystems

post-install:
	@${STRIP_CMD} \
		${STAGEDIR}${PYTHON_SITELIBDIR}/minorminer/_minorminer${PYTHON_EXT_SUFFIX}.so \
		${STAGEDIR}${PYTHON_SITELIBDIR}/minorminer/busclique${PYTHON_EXT_SUFFIX}.so

.include <bsd.port.mk>
