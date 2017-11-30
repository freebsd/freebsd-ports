# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ezjailremote
PORTVERSION=	0.2.2
PORTREVISION=	1
CATEGORIES=	sysutils python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Remote control and convenience wrapper for ezjail

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	ezjail-admin:sysutils/ezjail \
		${PYTHON_PKGNAMEPREFIX}fabric>0:devel/py-fabric@${FLAVOR}

USE_GITHUB=	yes
GH_ACCOUNT=	tomster
GH_PROJECT=	ezjail-remote

USES=		python:2.7
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
