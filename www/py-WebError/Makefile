# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	WebError
PORTVERSION=	0.13.1
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Web Error handling and exception catching

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Paste>=1.7:www/py-paste@${PY_FLAVOR} \
		${PY_PYGMENTS} \
		${PYTHON_PKGNAMEPREFIX}Tempita>=0.3:textproc/py-Tempita@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}webob>=0.9.6.1:www/py-webob@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
