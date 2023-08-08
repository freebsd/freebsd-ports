PORTNAME=	csvkit
PORTVERSION=	1.1.1
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Command line tools for working with CSV
WWW=		https://csvkit.readthedocs.io/

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}agate>=1.6.1:textproc/py-agate@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}agate-excel>=0.2.2:textproc/py-agate-excel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}agate-dbf>=0.2.2:textproc/py-agate-dbf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}agate-sql>=0.5.3:databases/py-agate-sql@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

.include <bsd.port.mk>
