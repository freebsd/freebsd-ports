# $FreeBSD$

PORTNAME=	yarl
PORTVERSION=	1.4.2
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Yet another URL library

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}multidict>=4.0:www/py-multidict@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}idna>=2.0:dns/py-idna@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-runner>0:devel/py-pytest-runner@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	autoplist distutils cython

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/yarl/_quoting.so

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m pytest

.include <bsd.port.mk>
