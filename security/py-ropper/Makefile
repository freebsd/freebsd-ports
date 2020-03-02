# $FreeBSD$

PORTNAME=	ropper
DISTVERSION=	1.13.3
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Find gadgets to build rop chains for different architectures

LICENSE=	BSD3CLAUSE
# LICENSE_FILE is not distributed with the Python package.

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}capstone>=4.0.1:devel/py-capstone@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}filebytes>=0.10.0:devel/py-filebytes@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}keystone-engine>=0.9.1.3:devel/py-keystone-engine@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
