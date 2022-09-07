PORTNAME=	pycryptodome-test-vectors
DISTVERSION=	1.0.10
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	john@saltant.com
COMMENT=	Optional test vectors for PyCryptodome and PyCryptodomeX
WWW=		https://www.pycryptodome.org/

LICENSE=	BSD2CLAUSE APACHE20
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE.rst

# Officially: 2.7, 3-5-3.10 (same as security/py-cryptodome)
USES=		cpe python:3.7+ zip
CPE_VENDOR=	python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
