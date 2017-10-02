# Created by: Thomas Zander <riggs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	MechanicalSoup
PORTVERSION=	0.8.0
DISTVERSIONPREFIX=	v
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Python library for automating interaction with websites

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-runner>=0:devel/py-pytest-runner
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup>=4:www/py-beautifulsoup \
		${PYTHON_PKGNAMEPREFIX}requests>=2.11:www/py-requests \
		${PYTHON_PKGNAMEPREFIX}six>=1.10:devel/py-six
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=0:devel/py-pytest-cov \
		${PYTHON_PKGNAMEPREFIX}requests-mock>=0:www/py-requests-mock

USE_GITHUB=	yes
GH_ACCOUNT=	hickford

NO_ARCH=	yes
USES=		python
USE_PYTHON=	autoplist concurrent distutils

.include <bsd.port.mk>
