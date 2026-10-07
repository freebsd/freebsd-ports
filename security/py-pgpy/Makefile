PORTNAME=	PGPy
DISTVERSION=	0.6.0
CATEGORIES=	security python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

PATCH_SITES=	https://github.com/SecurityInnovation/PGPy/commit/
PATCHFILES=	ad905b3c42dcf47d2e76c0d18b4bc1051cbbd4d9.patch:-p1 \
		5cdda87f74bcbb1dd7d29bb49b6a0ee67e41a7ce.patch:-p1 \
		5c057b0d58cc269fdf0340a5e9802b295db8df2b.patch:-p1

MAINTAINER=	contact@evilham.com
COMMENT=	Pretty Good Privacy for Python
WWW=		https://github.com/SecurityInnovation/PGPy

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyasn1>=0:devel/py-pyasn1@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent cryptography pep517 pytest

NO_ARCH=	yes

.include <bsd.port.mk>
