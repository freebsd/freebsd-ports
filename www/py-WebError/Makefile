# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	WebError
PORTVERSION=	0.13.1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Web Error handling and exception catching

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Paste>=1.7:www/py-paste \
		${PYTHON_PKGNAMEPREFIX}pygments>=1.0:textproc/py-pygments \
		${PYTHON_PKGNAMEPREFIX}Tempita>=0.3:textproc/py-Tempita \
		${PYTHON_PKGNAMEPREFIX}webob>=0.9.6.1:www/py-webob

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
