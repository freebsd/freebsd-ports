# ex:ts=8
# Ports collection Makefile for:	xmltools
# Date created:			Jan 4, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	xmltools
PORTVERSION=	1.3.7
PORTREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	ftp://ftp.logilab.org/pub/xmltools/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	High level xml tools for Python

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_VERSION} == "python1.5" || ${PYTHON_VERSION} == "python1.6"
XMLDIR=		xml
.else
XMLDIR=		_xmlplus
.endif

RUN_DEPENDS=	${PYXML} \
		${PYTHON_SITELIBDIR}/gtk-1.2/GDK.py:${PORTSDIR}/x11-toolkits/py-gtk \
		${PYTHON_SITELIBDIR}/${XMLDIR}/xpath/__init__.py:${PORTSDIR}/textproc/py-4suite

.include <bsd.port.post.mk>
