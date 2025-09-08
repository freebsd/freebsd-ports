PORTNAME=	cryptojwt
PORTVERSION=	1.10.0
CATEGORIES=	security python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python implementation of JWT, JWE, JWS and JWK
WWW=		https://cryptojwt.readthedocs.io/en/latest/ \
		https://github.com/IdentityPython/JWTConnect-Python-CryptoJWT

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uv-dynamic-versioning>=0:devel/py-uv-dynamic-versioning@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=2.25.1:www/py-requests@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	autoplist concurrent cryptography pep517

NO_ARCH=	yes

SHEBANG_FILES=	src/cryptojwt/tools/jwtpeek.py

.include <bsd.port.mk>
