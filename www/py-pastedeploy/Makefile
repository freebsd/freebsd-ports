# Created by: Dryice Liu	<dryice@dryice.name>
# $FreeBSD$

PORTNAME=	pastedeploy
PORTVERSION=	2.1.1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PasteDeploy-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Load, configure, and compose WSGI applications and servers

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Paste>=1.6:www/py-paste@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
