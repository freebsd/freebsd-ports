# ex:ts=8
# Ports collection makefile for:	py-jabber
# Date created:				Jan 13, 2002
# Whom:	      				ijliao
#
# $FreeBSD$
#

PORTNAME=	jabber
PORTVERSION=	0.4
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	jabberpy
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	jabberpy${PORTVERSION}-0

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Python Jabber library

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/pyexpat.so:${PORTSDIR}/textproc/py-expat

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

.include <bsd.port.mk>
