# New ports collection makefile for:	py-restclient
# Date created:		Apr. 15, 2007
# Whom:			Li-Wen Hsu <lwhsu@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	restclient
PORTVERSION=	0.9.10
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Convenient library for writing REST clients

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/httplib2/__init__.py:${PORTSDIR}/www/py-httplib2

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
post-patch:
	${REINPLACE_CMD} -e 's,install_requires.*,,' ${WRKSRC}/setup.py

.include <bsd.port.mk>
