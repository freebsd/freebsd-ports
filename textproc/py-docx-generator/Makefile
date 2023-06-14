PORTNAME=	docx-generator
PORTVERSION=	0.8.0
CATEGORIES=	textproc python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Tool to generate docx report from docx template and json data
WWW=		https://github.com/dfir-iris/docx-generator

LICENSE=	LGPL3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docxcompose>0:textproc/py-docxcompose@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docxtpl>0:textproc/py-docxtpl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-docx>0:textproc/py-python-docx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mistletoe>0:textproc/py-mistletoe@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markupsafe>0:textproc/py-markupsafe@${PY_FLAVOR}

USE_GITHUB=	yes
GH_ACCOUNT=	dfir-iris
GH_PROJECT=	${PORTNAME}
GH_TAGNAME=	6b2d68f2ea8b34daac76bd399b083d5e85eee23b

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
