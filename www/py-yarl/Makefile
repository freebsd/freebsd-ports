# $FreeBSD$

PORTNAME=	yarl
PORTVERSION=	0.12.0
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Yet another URL library

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	cython:lang/cython
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}multidict>=2.0:www/py-multidict
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest \
		${PYTHON_PKGNAMEPREFIX}pytest-runner>0:devel/py-pytest-runner

USES=		python:3.4+
USE_PYTHON=	autoplist distutils

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/yarl/_quoting.so
.include <bsd.port.mk>
