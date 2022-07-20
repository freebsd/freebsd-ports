PORTNAME=	pyexcel-ods3
PORTVERSION=	0.6.1
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Read, manipulate and write data in ods format

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>=0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyexcel-ezodf>=0.3.3:textproc/py-pyexcel-ezodf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyexcel-io>=0.6.2:textproc/py-pyexcel-io@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
