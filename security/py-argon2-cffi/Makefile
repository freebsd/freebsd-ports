PORTNAME=	argon2-cffi
PORTVERSION=	21.3.0
CATEGORIES=	security python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Secure Argon2 password hashing algorithm
WWW=		https://argon2-cffi.readthedocs.io/en/stable/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}argon2-cffi-bindings>=0:security/py-argon2-cffi-bindings@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}coverage>=5.0.2:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hypothesis>=0:devel/py-hypothesis@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils pytest

NO_ARCH=	yes
TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHON_SITELIBDIR}

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 30800
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}typing-extensions>=0:devel/py-typing-extensions@${PY_FLAVOR}
.endif

post-patch:
	@${SED} -e 's|%%PORTVERSION%%|${PORTVERSION}|' ${FILESDIR}/setup.py > ${WRKSRC}/setup.py

.include <bsd.port.post.mk>
