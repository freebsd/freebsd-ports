# $FreeBSD$

PORTNAME=	csvkit
PORTVERSION=	1.0.1
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Command line tools for working with CSV

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}agate>=1.5.4:textproc/py-agate \
		${PYTHON_PKGNAMEPREFIX}agate-excel>=0.2.0:textproc/py-agate-excel \
		${PYTHON_PKGNAMEPREFIX}agate-dbf>=0.2.0:textproc/py-agate-dbf \
		${PYTHON_PKGNAMEPREFIX}agate-sql>=0.5.0:databases/py-agate-sql \
		${PYTHON_PKGNAMEPREFIX}six>=1.6.1:devel/py-six

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
