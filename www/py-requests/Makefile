# Created by: Olivier Duchateau <duchateau.olivier@gmail.com>
# $FreeBSD$

PORTNAME=	requests
PORTVERSION=	2.17.3
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	HTTP library written in Python for human beings

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS?=	${PYTHON_PKGNAMEPREFIX}chardet>=3.0.2:textproc/py-chardet \
		${PYTHON_PKGNAMEPREFIX}idna>=2.5:dns/py-idna \
		${PYTHON_PKGNAMEPREFIX}urllib3>=1.21.1:net/py-urllib3 \
		${PYTHON_PKGNAMEPREFIX}certifi>=2017.4.17:security/py-certifi
TEST_DEPENDS?=	${PYTHON_PKGNAMEPREFIX}pytest>=2.8.1:devel/py-pytest \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>0:devel/py-pytest-xdist \
		${PYTHON_PKGNAMEPREFIX}execnet>=1.1:sysutils/py-execnet \
		${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock

USES?=		python
USE_PYTHON=	autoplist concurrent distutils

CONFLICTS_INSTALL=	py*-requests1-*

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
