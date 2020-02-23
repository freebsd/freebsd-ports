# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ezjailremote
PORTVERSION=	0.2.2
PORTREVISION=	2
CATEGORIES=	sysutils python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Remote control and convenience wrapper for ezjail

LICENSE=	BSD2CLAUSE

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-08-15

RUN_DEPENDS=	ezjail-admin:sysutils/ezjail \
		${PYTHON_PKGNAMEPREFIX}fabric1>0:devel/py-fabric1@${PY_FLAVOR}

USES=		python:2.7
USE_PYTHON=	distutils autoplist

USE_GITHUB=	yes
GH_ACCOUNT=	tomster
GH_PROJECT=	ezjail-remote

NO_ARCH=	yes

.include <bsd.port.mk>
