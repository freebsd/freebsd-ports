PORTNAME=	ase
DISTVERSION=	3.22.1
CATEGORIES=	science python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Atomic simulation environment

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=3.1.0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.1.0:science/py-scipy@${PY_FLAVOR} \
		nwchem:science/nwchem
# optional dependencies: x11-toolkits/py-tkinter, www/py-flask (see https://wiki.fysik.dtu.dk/ase/install.html)

USES=		python:3.7+
USE_PYTHON=	distutils concurrent autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
