# ex:ts=8
# Ports collection makefile for:	py-jabber
# Date created:				Jan 13, 2002
# Whom:	      				ijliao
#
# $FreeBSD$
#

PORTNAME=	jabber
PORTVERSION=	0.5
CATEGORIES=	net-im python
MASTER_SITES=	SF/${PORTNAME}py/${PORTNAME}py%20libs/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	jabberpy-${PORTVERSION}-0

MAINTAINER=	flz@FreeBSD.org
COMMENT=	A Python Jabber library

RUN_DEPENDS=	${PYEXPAT}

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	jabber.py
PYDISTUTILS_PKGVERSION=	0.3-1

post-install:
	@${ECHO} "jabber" > ${PYTHON_SITELIBDIR}/jabber.pth

.include <bsd.port.mk>
