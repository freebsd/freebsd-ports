# $FreeBSD$

PORTNAME=	csvkit
PORTVERSION=	1.0.5
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Command line tools for working with CSV

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}agate>=1.5.4:textproc/py-agate@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}agate-excel>=0.2.0:textproc/py-agate-excel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}agate-dbf>=0.2.0:textproc/py-agate-dbf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}agate-sql>=0.5.0:databases/py-agate-sql@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.6.1:devel/py-six@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

.include <bsd.port.mk>
