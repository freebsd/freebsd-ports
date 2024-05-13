PORTNAME=	ipy
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	net-mgmt python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	IPy-1.01

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python module for handling IPv4 and IPv6 Addresses and Networks
WWW=		https://github.com/autocracy/python-ipy

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

do-test:
	${PYTHON_CMD} ${WRKSRC}/test/test_IPy.py

.include <bsd.port.mk>
