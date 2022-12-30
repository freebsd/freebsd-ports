PORTNAME=	autopep8
PORTVERSION=	2.0.0
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Automatically formats Python code to conform to the PEP 8 style guide
WWW=		https://github.com/hhatto/autopep8

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycodestyle>=2.9.1:devel/py-pycodestyle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tomli>=0:textproc/py-tomli@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
