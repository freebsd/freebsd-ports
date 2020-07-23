# $FreeBSD$

PORTNAME=	ase
DISTVERSION=	3.19.2
CATEGORIES=	science python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Atomic simulation environment

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR} \
		nwchem:science/nwchem
# optional dependencies: math/py-matplotlib, x11-toolkits/py-tkinter, www/py-flask (see https://wiki.fysik.dtu.dk/ase/install.html)

USES=		python:3.5+
USE_PYTHON=	distutils concurrent autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
