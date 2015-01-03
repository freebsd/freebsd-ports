# Created by: Dryice Liu	<dryice@dryice.name>
# $FreeBSD$

PORTNAME=	PasteDeploy
PORTVERSION=	1.5.0
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wenheping@gmail.com
COMMENT=	Load, configure, and compose WSGI applications and servers

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Paste>=1.6:${PORTSDIR}/www/py-paste
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
