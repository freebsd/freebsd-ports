PORTNAME=	txrequests
PORTVERSION=	0.9.6
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Asynchronous Python HTTP for Humans
WWW=		https://github.com/tardyp/txrequests

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Use www/py-requests-futures as upstream is unmaintained since 2018
EXPIRATION_DATE=	2022-12-31
BROKEN=	Fails to build with latest devel/py-twisted

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=1.2.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}twisted>=9.0.0:devel/py-twisted@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

TEST_ENV=	PYTHONPATH=${TEST_WRKSRC}

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${LOCALBASE}/bin/trial ${WRKSRC}/test_txrequests.py

.include <bsd.port.mk>
