# Created by: Carlos J. Puga Medina <cpm@FreeBSD.org>

PORTNAME=	numpydoc
PORTVERSION=	0.9.1
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Sphinx extension to support docstrings in Numpy format

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Jinja2>=2.3:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinx>=1.6.5,1:textproc/py-sphinx@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils nose

NO_ARCH=	yes

.include <bsd.port.mk>
