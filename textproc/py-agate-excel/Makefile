PORTNAME=	agate-excel
PORTVERSION=	0.4.1
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Support reading Excel files for agate
WWW=		https://agate-excel.rtfd.org/

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}agate>=1.5.0:textproc/py-agate@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xlrd>=0.9.4:textproc/py-xlrd@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openpyxl>=2.3.0:textproc/py-openpyxl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.6.1:devel/py-six@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
