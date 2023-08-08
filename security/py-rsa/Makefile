PORTNAME=	rsa
PORTVERSION=	4.9
CATEGORIES=	security python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Pure-Python RSA implementation
WWW=		https://stuvel.eu/software/rsa/ \
		https://github.com/sybrenstuvel/python-rsa

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyasn1>=0.1.3:devel/py-pyasn1@${PY_FLAVOR}

USES=		cpe dos2unix python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

CPE_VENDOR=	python

.include <bsd.port.mk>
