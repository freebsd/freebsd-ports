# New ports collection makefile for:	py-flask
# Date created:		2010-09-26
# Whom:			Olivier Duchateau <duchateau.olivier@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Flask
PORTVERSION=	0.6.1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	duchateau.olivier@gmail.com
COMMENT=	micro webdevelopment framework for Python

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}werkzeug>=0.6.1:${PORTSDIR}/www/py-werkzeug \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=2.5:${PORTSDIR}/devel/py-Jinja2

LICENSE=	BSD

USE_PYTHON=	2.6+
USE_PYDISTUTILS=	easy_install

.include <bsd.port.mk>
