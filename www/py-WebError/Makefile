# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	WebError
PORTVERSION=	0.10.3
PORTREVISION=	1
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

USE_PYTHON=		yes
USE_PYDISTUTILS=	easy_install

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 260
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}simplejson>=2.0.8:${PORTSDIR}/devel/py-simplejson
.endif

.include <bsd.port.post.mk>
