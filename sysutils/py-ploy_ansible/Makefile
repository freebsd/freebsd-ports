# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ploy_ansible
PORTVERSION=	1.4.1
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Plugin to integrate Ansible with ploy

LICENSE=	GPLv3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ploy>=1.0.0,<2:sysutils/py-ploy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}execnet>0:sysutils/py-execnet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ansible1>=1.8.0,<2.0:sysutils/ansible1@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

USES=		python:-2.7
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

do-test:
	${RM} ${WRKSRC}/tox.ini # clobbers our pytest arguments
	@cd ${WRKSRC} && ${PYTHON_CMD} -m pytest -v -rs

.include <bsd.port.mk>
