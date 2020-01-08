# $FreeBSD$

PORTNAME=	cron-descriptor
PORTVERSION=	1.2.24
CATEGORIES=	sysutils python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	loader@FreeBSD.org
COMMENT=	Converts cron expressions into human readable strings

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flake8>0:devel/py-flake8@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pep8>0:devel/pep8@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pep8-naming>0:devel/py-pep8-naming@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
USE_PYTHON=	autoplist concurrent distutils

GH_ACCOUNT=	Salamek
NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
