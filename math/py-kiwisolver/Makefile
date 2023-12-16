PORTNAME=	kiwisolver
PORTVERSION=	1.4.5
PORTEPOCH=	1
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lbartoletti@FreeBSD.org
COMMENT=	Fast implementation of the Cassowary constraint solver
WWW=		https://github.com/nucleic/kiwi

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=  ${PYTHON_PKGNAMEPREFIX}cppy>=1.1.0:devel/py-cppy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools_scm>0:devel/py-setuptools_scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}


USES=		compiler:c++11-lang python
USE_PYTHON=	autoplist concurrent distutils

.include <bsd.port.mk>
