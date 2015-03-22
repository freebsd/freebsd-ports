# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ploy
PORTVERSION=	1.2.0
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Manage servers through a central configuration

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lazy>0:${PORTSDIR}/devel/py-lazy \
		${PYTHON_PKGNAMEPREFIX}paramiko>0:${PORTSDIR}/security/py-paramiko

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
