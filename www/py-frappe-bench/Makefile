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

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>0:devel/py-click \
		${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2 \
		${PYTHON_PKGNAMEPREFIX}virtualenv>0:devel/py-virtualenv \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests \
		${PYTHON_PKGNAMEPREFIX}honcho>0:sysutils/py-honcho \
		${PYTHON_PKGNAMEPREFIX}semantic_version>0:devel/py-semantic_version \
		${PYTHON_PKGNAMEPREFIX}GitPython>=1.0.1:devel/py-gitpython \
		${PYTHON_PKGNAMEPREFIX}pip>0:devel/py-pip \
		git:devel/git

USE_GITHUB=	yes
GH_ACCOUNT=	frappe
GH_PROJECT=	bench

USES=		python
USE_PYTHON=	autoplist distutils concurrent

.include <bsd.port.mk>
