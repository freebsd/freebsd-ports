# ex:ts=8
# Ports collection makefile for:	py-jabber
# Date created:				Jan 13, 2002
# Whom:	      				ijliao
#
# $FreeBSD$
#

PORTNAME=	jabber
PORTVERSION=	0.2
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	jabberpy
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	jabber.py-${PORTVERSION}-1

MAINTAINER=	ports@FreeBSD.org

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/pyexpat.so:${PORTSDIR}/textproc/py-expat

USE_PYTHON=	yes

SETUP_CMD=	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} setup.py

do-build:
	@${SETUP_CMD} build

do-install:
	@${SETUP_CMD} install

.include <bsd.port.mk>
