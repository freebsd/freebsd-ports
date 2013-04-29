# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ezjailremote
PORTVERSION=	0.2.1
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Remote control and convenience wrapper for ezjail

RUN_DEPENDS=	ezjail-admin:${PORTSDIR}/sysutils/ezjail \
		${PYTHON_PKGNAMEPREFIX}fabric>0:${PORTSDIR}/devel/py-fabric

USE_ZIP=		yes
USE_PYTHON=		yes
USE_PYDISTUTILS=	easy_install

.include <bsd.port.mk>
