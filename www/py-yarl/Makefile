PORTNAME=	yarl
PORTVERSION=	1.20.1
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Yet another URL library
WWW=		https://github.com/aio-libs/yarl

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}expandvars>=0:devel/py-expandvars@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=47:devel/py-setuptools@${PY_FLAVOR} \
		${PY_TOMLI} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}idna>=2.0:dns/py-idna@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}multidict>=4.0:www/py-multidict@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}propcache>=0.2.0:devel/py-propcache@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hypothesis>0:devel/py-hypothesis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-codspeed>0:devel/py-pytest-codspeed@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist cython3 pep517 pytest

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/yarl/_quoting_c*.so

pre-test:
	@cd ${TEST_WRKSRC}/yarl && ${LN} -fs ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/yarl/_quoting_c*.so

.include <bsd.port.mk>
