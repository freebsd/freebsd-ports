# ex:ts=8
# Ports collection Makefile for:	xmltools
# Date created:			Jan 4, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	xmltools
PORTVERSION=	1.4.0
CATEGORIES=	textproc python
MASTER_SITES=	ftp://ftp.logilab.org/pub/xmltools/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	High level XML tools for Python

USE_GNOME=	pygtk2
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

.include <bsd.port.pre.mk>

RUN_DEPENDS=	${PYXML} \
		${PYTHON_SITELIBDIR}/_xmlplus/xpath/__init__.py:${PORTSDIR}/textproc/py-4suite

.include <bsd.port.post.mk>
