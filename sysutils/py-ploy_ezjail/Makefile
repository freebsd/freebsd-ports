# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ploy_ezjail
PORTVERSION=	1.4.0
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Plugin for ploy to provision FreeBSD jails using ezjail

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools${PYTHON_SUFFIX}>0:${PORTSDIR}/devel/py-setuptools${PYTHON_SUFFIX} \
		${PYTHON_PKGNAMEPREFIX}ploy>=1.2.0:${PORTSDIR}/sysutils/py-ploy \
		${PYTHON_PKGNAMEPREFIX}lazy>0:${PORTSDIR}/devel/py-lazy

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
