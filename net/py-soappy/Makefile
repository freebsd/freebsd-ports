# Created by: Alexander Leidinger
# $FreeBSD$

PORTNAME=	soappy
PORTVERSION=	0.12.22
PORTREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	SOAPpy-${PORTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	SOAP Services for Python
# Actual LICENSE is in GH Repo but not in pypi release
LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}defusedxml>0:devel/py-defusedxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wstools>0:textproc/py-wstools@${PY_FLAVOR}

USES=		python:2.7 zip
USE_PYTHON=	autoplist distutils

CONFLICTS=	py*-soappy-devel-0.12.*

.include <bsd.port.mk>
