# $FreeBSD$

PORTNAME=	toil
DISTVERSION=	3.22.0
CATEGORIES=	misc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Pipeline management software for clusters

LICENSE=	APACHE20

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-08-15

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}addict>0:devel/py-addict@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dateutil>0:devel/py-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dill>0:devel/py-dill@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docker>0:sysutils/py-docker@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}future>0:devel/py-future@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pathlib2>0:devel/py-pathlib2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.10.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}subprocess32>0:devel/py-subprocess32@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>0:devel/py-pytest-cov@${PY_FLAVOR}

USES=		python:2.7
USE_PYTHON=	distutils concurrent autoplist

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m pytest

.include <bsd.port.mk>
