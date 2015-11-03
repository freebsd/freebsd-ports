# Created by: antoine@FreeBSD.org
# $FreeBSD$

PORTNAME=	rekall_gui
PORTVERSION=	1.4.1
PORTREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	GUI component of the Rekall framework

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}codegen>=1.0:${PORTSDIR}/devel/py-codegen \
		${PYTHON_PKGNAMEPREFIX}Flask>=0.10.1:${PORTSDIR}/www/py-flask \
		${PYTHON_PKGNAMEPREFIX}Flask-Sockets>=0:${PORTSDIR}/www/py-flask-sockets \
		${PYTHON_PKGNAMEPREFIX}gevent>=1.0.2:${PORTSDIR}/devel/py-gevent \
		${PYTHON_PKGNAMEPREFIX}gevent-websocket>=0.9.3:${PORTSDIR}/www/py-gevent-websocket \
		${PYTHON_PKGNAMEPREFIX}ipython>=3.0.0:${PORTSDIR}/devel/ipython \
		${PYTHON_PKGNAMEPREFIX}rekall-core>=1.4.0:${PORTSDIR}/security/py-rekall-core

USES=		python:2 shebangfix
SHEBANG_FILES=	manuskript/static/bower_components/bootstrap/test-infra/uncached-npm-install.sh
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

.include <bsd.port.pre.mk>

PYDISTUTILS_INSTALLARGS+=--install-data ${PYTHONPREFIX_SITELIBDIR}

.include <bsd.port.post.mk>
