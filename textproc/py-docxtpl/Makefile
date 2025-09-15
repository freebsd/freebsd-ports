PORTNAME=	docxtpl
PORTVERSION=	0.20.0
PORTREVISION=	2
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Python docx template engine
WWW=		https://github.com/elapouya/python-docx-template

LICENSE=	LGPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>=3.3.4:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-docx>0:textproc/py-python-docx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docxcompose>0:textproc/py-docxcompose@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
