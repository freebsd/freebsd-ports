PORTNAME=	yarl
PORTVERSION=	1.9.7
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Yet another URL library
WWW=		https://github.com/aio-libs/yarl

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}expandvars>=0:devel/py-expandvars@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}multidict>0:www/py-multidict@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}idna>0:dns/py-idna@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-runner>0:devel/py-pytest-runner@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517 cython pytest

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/yarl/_quoting_c*.so

pre-test:
	@cd ${TEST_WRKSRC}/yarl && ${LN} -fs ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/yarl/_quoting_c*.so

.include <bsd.port.mk>
