PORTNAME=	kiwisolver
PORTVERSION=	1.4.9
PORTEPOCH=	1
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast implementation of the Cassowary constraint solver
WWW=		https://github.com/nucleic/kiwi

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=  ${PYTHON_PKGNAMEPREFIX}cppy>=1.1.0:devel/py-cppy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}


USES=		python
USE_PYTHON=	autoplist concurrent distutils

.include <bsd.port.mk>
