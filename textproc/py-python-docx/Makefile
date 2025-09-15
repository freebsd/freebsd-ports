PORTNAME=	python-docx
PORTVERSION=	1.1.0
PORTREVISION=	2
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Python library for creating and updating Microsoft Word files
WWW=		https://github.com/python-openxml/python-docx

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61.0.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>=3.3.4:devel/py-lxml@${PY_FLAVOR}

# Python3 ready
USES=		python
USE_PYTHON=	autoplist pep517
NO_ARCH=	yes

.include <bsd.port.mk>
