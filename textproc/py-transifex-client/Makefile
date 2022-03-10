# Created by: Kubilay Kocak <koobs@FreeBSD.org>

PORTNAME=	transifex-client
PORTVERSION=	0.14.4
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Command line interface for Transifex

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gitpython>0:devel/py-gitpython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-slugify>=1.26.0:textproc/py-python-slugify@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.19.1:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.11.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>=1.24.2,1<2.0.0,1:net/py-urllib3@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
