# ex:ts=8
# New ports collection makefile for:	py-fckhsum
# Date created:			Jul 5, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	fchksum
PORTVERSION=	1.6
CATEGORIES=	security python
MASTER_SITES=	http://www.azstarnet.com/~donut/programs/fchksum/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

USE_PYTHON=	yes
GNU_CONFIGURE=	yes
SETUP_CMD=	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} setup.py

do-build:
	@${SETUP_CMD} build

do-install:
	@${SETUP_CMD} install

.include <bsd.port.mk>
