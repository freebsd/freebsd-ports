PORTNAME=	docx-generator
PORTVERSION=	0.9.1
DISTVERSIONPREFIX=	v
CATEGORIES=	textproc python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Tool to generate docx report from docx template and json data
WWW=		https://github.com/dfir-iris/docx-generator

LICENSE=	LGPL3

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>0:devel/py-poetry-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docxcompose>0:textproc/py-docxcompose@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docxtpl>0:textproc/py-docxtpl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-docx>0:textproc/py-python-docx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mistletoe>0:textproc/py-mistletoe@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markupsafe>0:textproc/py-markupsafe@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR}

USE_GITHUB=	yes
GH_ACCOUNT=	dfir-iris
GH_PROJECT=	${PORTNAME}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

.include <bsd.port.mk>
