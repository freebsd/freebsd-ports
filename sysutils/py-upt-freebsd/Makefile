PORTNAME=	upt-freebsd
DISTVERSION=	0.3
CATEGORIES=	sysutils ports-mgmt python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	tipecaml@gmail.com
COMMENT=	FreeBSD backend for upt
WWW=		https://framagit.org/upt/upt-freebsd

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}upt>=0.4:sysutils/py-upt@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

TEST_ENV=	PORTSDIR="/nonexistent"

do-test:
	@cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m unittest -v

.include <bsd.port.mk>
