# Created by: John Hixson <john@ixsystems.com>
# $FreeBSD$

PORTNAME=	django-json-rpc
PORTVERSION=	0.6.2
PORTREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	http://wiki.pcbsd.org/ports/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	john@ixsystems.com
COMMENT=	Simple JSON-RPC implementation for Django

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/django/bin/django-admin.py:${PORTSDIR}/www/py-django

LICENSE=	MIT

USES=	tar:bzip2
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.mk>
