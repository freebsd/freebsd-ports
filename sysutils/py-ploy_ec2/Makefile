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

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools${PYTHON_SUFFIX}>0:devel/py-setuptools${PYTHON_SUFFIX} \
		${PYTHON_PKGNAMEPREFIX}ploy>=1.0.0:sysutils/py-ploy \
		${PYTHON_PKGNAMEPREFIX}boto>=2.0:devel/py-boto \
		${PYTHON_PKGNAMEPREFIX}lazy>0:devel/py-lazy

USES=		python:-2.7
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
