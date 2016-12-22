# $FreeBSD$

PORTNAME=	csvkit
PORTVERSION=	0.9.1
PORTREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Command line tools for working with CSV

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}agate-dbf>=0.1.0:textproc/py-agate-dbf \
		${PYTHON_PKGNAMEPREFIX}agate-excel>=0.1.0:textproc/py-agate-excel \
		${PYTHON_PKGNAMEPREFIX}agate>=1.2.2:textproc/py-agate \
		${PYTHON_PKGNAMEPREFIX}dateutil>=2.2:devel/py-dateutil \
		${PYTHON_PKGNAMEPREFIX}dbf>0.94.003:databases/py-dbf \
		${PYTHON_PKGNAMEPREFIX}six>=1.6.1:devel/py-six \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy10>=0.9.3:databases/py-sqlalchemy10

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
