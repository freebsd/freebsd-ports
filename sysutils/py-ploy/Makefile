# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ploy
PORTVERSION=	1.2.1
PORTREVISION=	2
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Manage servers through a central configuration

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lazy>0:devel/py-lazy \
		${PYTHON_PKGNAMEPREFIX}paramiko1>0:security/py-paramiko1 \
		${PYTHON_PKGNAMEPREFIX}setuptools${PYTHON_SUFFIX}>0:devel/py-setuptools${PYTHON_SUFFIX}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
