# $FreeBSD$

PORTNAME=	httmock
PORTVERSION=	1.3.0
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dereks@lifeofadishwasher.com
COMMENT=	Mocking library for requests

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=1.0.0:www/py-requests@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes # tests missing from PyPI sdist
USE_PYTHON=	distutils autoplist

GH_ACCOUNT=	patrys

NO_ARCH=	yes

do-test:
	cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
