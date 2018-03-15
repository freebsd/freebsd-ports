# $FreeBSD$

PORTNAME=	csvkit
PORTVERSION=	1.0.3
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Command line tools for working with CSV

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}agate>=1.5.4:textproc/py-agate@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}agate-excel>=0.2.0:textproc/py-agate-excel@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}agate-dbf>=0.2.0:textproc/py-agate-dbf@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}agate-sql>=0.5.0:databases/py-agate-sql@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.6.1:devel/py-six@${FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
