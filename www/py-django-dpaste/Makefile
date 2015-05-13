# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dpaste
PORTVERSION=	2.5
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}django-

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Pastebin Django application that powers dpaste.de

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django>=1.4:${PORTSDIR}/www/py-django \
		${PYTHON_PKGNAMEPREFIX}django-mptt>=0.6.0:${PORTSDIR}/www/py-django-mptt \
		${PYTHON_PKGNAMEPREFIX}pygments>=1.6:${PORTSDIR}/textproc/py-pygments \
		${PYTHON_PKGNAMEPREFIX}requests>=2.0.0:${PORTSDIR}/www/py-requests
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tox>=1.6.1:${PORTSDIR}/devel/py-tox

OPTIONS_DEFINE=	MIGRATIONS TESTS

MIGRATIONS_DESC=	Schema and data migration support (via south)
TESTS_DESC=		Include tox for test suite

MIGRATIONS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}south>=0.8.2:${PORTSDIR}/databases/py-south
TESTS_BUILD_DEPENDS=	${TEST_DEPENDS}

USE_GITHUB=	yes
USES=		python
USE_PYTHON=	distutils autoplist

GH_ACCOUNT=	bartTC

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYSETUP} test

.include <bsd.port.mk>
