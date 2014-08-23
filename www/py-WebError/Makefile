# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	WebError
PORTVERSION=	0.10.3
PORTREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Web Error handling and exception catching

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Paste>=1.7:${PORTSDIR}/www/py-paste \
		${PYTHON_PKGNAMEPREFIX}pygments>=1.0:${PORTSDIR}/textproc/py-pygments \
		${PYTHON_PKGNAMEPREFIX}Tempita>=0.3:${PORTSDIR}/textproc/py-Tempita \
		${PYTHON_PKGNAMEPREFIX}webob>=0.9.6.1:${PORTSDIR}/www/py-webob

USES=		python
USE_PYTHON=	distutils autoplist

post-extract:
		${CHMOD} -R a+r ${WRKSRC}

.include <bsd.port.mk>
