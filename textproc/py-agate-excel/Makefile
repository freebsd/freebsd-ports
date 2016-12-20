# $FreeBSD$

PORTNAME=	agate-excel
PORTVERSION=	0.2.0
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Support reading Excel files for agate

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}agate>=1.5.0:textproc/py-agate \
		${PYTHON_PKGNAMEPREFIX}xlrd>=0.9.4:textproc/py-xlrd \
		${PYTHON_PKGNAMEPREFIX}openpyxl>=2.3.0:textproc/py-openpyxl 

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
