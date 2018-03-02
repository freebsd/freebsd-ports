# Created by: Olivier Duchateau <duchateau.olivier@gmail.com>
# $FreeBSD$

PORTNAME=	requests
PORTVERSION=	2.18.4
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	HTTP library written in Python for human beings

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}chardet>=3.0.2:textproc/py-chardet@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}idna>=2.5:dns/py-idna@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>=1.21.1:net/py-urllib3@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}certifi>=2017.4.17:security/py-certifi@${FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=2.8.0:devel/py-pytest@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-mock>0:devel/py-pytest-mock@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>0:devel/py-pytest-xdist@${FLAVOR}

# Actually 2.6-2.7,3.3+
USES=		python
USE_PYTHON=	autoplist concurrent distutils

CONFLICTS_INSTALL=	py*-requests1-*

NO_ARCH=	yes

# Automated tests failinng due to httpbin issue
# https://github.com/kennethreitz/httpbin/issues/403

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
