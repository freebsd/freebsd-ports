PORTNAME=	pgpy
PORTVERSION=	0.5.3
PORTREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PGPy-${PORTVERSION}

MAINTAINER=	contact@evilham.com
COMMENT=	Pretty Good Privacy for Python
WWW=		https://github.com/SecurityInnovation/PGPy

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyasn1>=0:devel/py-pyasn1@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.9.0:devel/py-six@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent cryptography distutils

NO_ARCH=	yes

.include <bsd.port.mk>
