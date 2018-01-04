# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ploy_ansible
PORTVERSION=	1.3.1
PORTREVISION=	1
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Plugin to integrate Ansible with ploy

LICENSE=	GPLv3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ploy>=1.0.0:sysutils/py-ploy@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}execnet>0:sysutils/py-execnet@${FLAVOR} \
		ansible1<2.0:sysutils/ansible1
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lazy>0:devel/py-lazy@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-capturelog>0:devel/py-pytest-capturelog@${FLAVOR}

USES=		python:-2.7
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && \
	${RM} tox.ini && \
	${PYTHON_CMD} -m pytest -rsw ploy_ansible

.include <bsd.port.mk>
