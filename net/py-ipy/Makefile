# ex:ts=8
# Ports collection makefile for:	py-ipy
# Date created:			Jan 30, 2002
# Whom:	      			ijliao
#
# $FreeBSD$
#

PORTNAME=	ipy
PORTVERSION=	0.41
CATEGORIES=	net python
MASTER_SITES=	http://c0re.jp/c0de/IPy/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	IPy-${PORTVERSION}

MAINTAINER=	drt@un.bewaff.net

USE_PYTHON=	yes

SETUP_CMD=	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} setup.py

do-build:
	@${SETUP_CMD} build

do-install:
	@${SETUP_CMD} install

.include <bsd.port.mk>
