PORTNAME=	docxcompose
PORTVERSION=	2.2.0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Python library for concatenating/appending Microsoft Word files.
WWW=		https://github.com/4teamwork/docxcompose

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>=3.3.4:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-docx>0:textproc/py-python-docx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Babel>0:devel/py-babel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

.include <bsd.port.mk>
