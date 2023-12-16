PORTNAME=	dpaste
DISTVERSIONPREFIX=	v
DISTVERSION=	3.8
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}django-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Django based pastebin for text and code
WWW=		https://github.com/DarrenOfficial/dpaste

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django32>=3.2:www/py-django32@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj-database-url>=0.5.0:www/py-dj-database-url@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-csp>=3.6:www/py-django-csp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-staticinline>=1.0:www/py-django-staticinline@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docutils>0:textproc/py-docutils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsx-lexer>=0.0.8:textproc/py-jsx-lexer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}misaka>=2.1.0:textproc/py-misaka@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=1.6:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ratelimiter>=1.2.0:devel/py-ratelimiter@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-django>0:devel/py-pytest-django@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	DarrenOfficial
USE_PYTHON=	distutils autoplist pytest

TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest -v -rs --ds=dpaste.settings.tests -o addopts=

.include <bsd.port.mk>
