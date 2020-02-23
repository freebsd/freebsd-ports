# Created by: Fukang Chen <loader@FreeBSD.org>
# $FreeBSD$

PORTNAME=	frappe-bench
PORTVERSION=	0.92
DISTVERSIONPREFIX=	v
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	loader@FreeBSD.org
COMMENT=	Frappe / ERPNext apps setup tool

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.md

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-08-15

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}virtualenv>0:devel/py-virtualenv@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}honcho>0:sysutils/py-honcho@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}semantic_version>0:devel/py-semantic_version@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}GitPython>=1.0.1:devel/py-gitpython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pip>0:devel/py-pip@${PY_FLAVOR} \
		git:devel/git

USE_GITHUB=	yes
GH_ACCOUNT=	frappe
GH_PROJECT=	bench

NO_ARCH=	yes
USES=		python:2.7
USE_PYTHON=	autoplist distutils concurrent

.include <bsd.port.mk>
