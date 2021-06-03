# Created by: Kubilay Kocak <koobs@FreeBSD.org>

PORTNAME=	aiohttp
DISTVERSION=	3.7.4.post0
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Async http client/server framework (asyncio)

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}attrs>=17.3.0:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}chardet>=2.0<5.0,1:textproc/py-chardet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}multidict>=4.5<7.0:www/py-multidict@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}async_timeout>=3.0<4.0:devel/py-async_timeout@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yarl>=1.0<2.0:www/py-yarl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=3.6.5:devel/py-typing-extensions@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=3.8.2:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-timeout>0:devel/py-pytest-timeout@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>0:devel/py-pytest-xdist@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-mock>0:devel/py-pytest-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}async_generator>0:devel/py-async_generator@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gunicorn>0:www/py-gunicorn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}aiodns>0:dns/py-aiodns@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cryptography>0:security/py-cryptography@${PY_FLAVOR}
# cryptography is only needed here until trustme is ported (which depends on it)
# to be ported	${PYTHON_PKGNAMEPREFIX}brotlypy>0:archivers/py-brotlipy@${PY_FLAVOR}
# to be ported	${PYTHON_PKGNAMEPREFIX}trustme>0:security/py-trustme@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils cython

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 30700
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}idna_ssl>=1.0:dns/py-idna_ssl@${PY_FLAVOR}
.endif

pre-configure:
	@${TOUCH} ${WRKSRC}/aiohttp/*.pyx

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/aiohttp/*.so

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.post.mk>
