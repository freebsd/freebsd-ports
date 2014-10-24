# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ploy_ansible
DISTVERSION=	1.0.0
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Ploy plugin to integrate with Ansible

LICENSE=	GPLv3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ploy>=1.0.0:${PORTSDIR}/sysutils/py-ploy \
		${PYTHON_PKGNAMEPREFIX}execnet>0:${PORTSDIR}/sysutils/py-execnet \
		ansible>0:${PORTSDIR}/sysutils/ansible

USES=		python:-2.7 zip
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
