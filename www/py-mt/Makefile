# ex:ts=8
# Ports collection makefile for:	PyMT
# Date created:			Dec 8, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	mt
PORTVERSION=	1.0
CATEGORIES=	www python
MASTER_SITES=	SF/py${PORTNAME}/py${PORTNAME}/PyMT-${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyMT-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Python module which provides Movable Type XML-RPC connectivity

USE_PYTHON=	yes
NO_BUILD=	yes
PLIST_FILES=	%%PYTHON_SITELIBDIR%%/PyMT.py

do-install:
	@${INSTALL_DATA} ${WRKSRC}/PyMT.py ${PYTHON_SITELIBDIR}

.include <bsd.port.mk>
