# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ploy_ec2
DISTVERSION=	1.2.0
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Plugin for ploy to provision Amazon EC2 instances

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-08-15

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ploy>=1.0.0:sysutils/py-ploy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}boto>=2.0:devel/py-boto@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lazy>0:devel/py-lazy@${PY_FLAVOR}

USES=		python:2.7
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
