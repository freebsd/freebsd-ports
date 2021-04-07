PORTNAME=	upt
DISTVERSION=	0.11
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	tipecaml@gmail.com
COMMENT=	Package software from any package manager to any distribution

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}colorlog>0:devel/py-colorlog@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}spdx-lookup>0:misc/py-spdx-lookup@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils concurrent

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m unittest -v

.include <bsd.port.mk>
