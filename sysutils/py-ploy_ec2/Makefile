# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ploy_ec2
DISTVERSION=	1.0.0
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Ploy plugin to provision Amazon EC2 instances

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ploy>=1.0.0:${PORTSDIR}/sysutils/py-ploy \
		${PYTHON_PKGNAMEPREFIX}boto>=2.0:${PORTSDIR}/devel/py-boto \
		${PYTHON_PKGNAMEPREFIX}lazy>0:${PORTSDIR}/devel/py-lazy

USES=		python:-2.7 zip
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
