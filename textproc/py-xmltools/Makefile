# ex:ts=8
# Ports collection Makefile for:	xmltools
# Date created:			Jan 4, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	xmltools
PORTVERSION=	1.4.0
PORTREVISION=	4
CATEGORIES=	textproc python
MASTER_SITES=	LOGILAB
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	High level XML tools for Python

BROKEN=		leaves files behind after deinstallation
DEPRECATED=	has been broken for 4 months
EXPIRATION_DATE=2010-01-08

USE_GNOME=	pygtk2
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

.include <bsd.port.pre.mk>

RUN_DEPENDS=	${PYXML} \
		${PYTHON_SITELIBDIR}/_xmlplus/xpath/__init__.py:${PORTSDIR}/textproc/py-4suite

post-patch:
	${REINPLACE_CMD} 's/from.*import.*nested_scopes//' ${WRKSRC}/setup.py

.include <bsd.port.post.mk>
