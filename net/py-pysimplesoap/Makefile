PORTNAME=	pysimplesoap
PORTVERSION=	1.16.2
CATEGORIES=	net python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PySimpleSOAP-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python simple and lightweight SOAP Library
WWW=		https://github.com/pysimplesoap/pysimplesoap

LICENSE=	LGPL3+

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
