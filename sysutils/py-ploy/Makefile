# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ploy
PORTVERSION=	1.2.1
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Manage servers through a central configuration

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lazy>0:${PORTSDIR}/devel/py-lazy \
		${PYTHON_PKGNAMEPREFIX}paramiko>0:${PORTSDIR}/security/py-paramiko \
		${PYTHON_PKGNAMEPREFIX}setuptools${PYTHON_SUFFIX}>0:${PORTSDIR}/devel/py-setuptools${PYTHON_SUFFIX} \
		${PYTHON_PKGNAMEPREFIX}argparse>0:${PORTSDIR}/devel/py-argparse

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
