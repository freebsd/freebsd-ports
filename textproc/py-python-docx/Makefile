# $FreeBSD$

PORTNAME=	python-docx
PORTVERSION=	0.8.10
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Python library for creating and updating Microsoft Word files

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>=3.3.4:devel/py-lxml@${PY_FLAVOR}

# Python3 ready
USES=		python
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

.include <bsd.port.mk>
