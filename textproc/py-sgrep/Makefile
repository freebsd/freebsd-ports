# ex:ts=8
# New ports collection makefile for: 	py-sgrep
# Date created:			Jun 14, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	sgrep
PORTVERSION=	1.0a
CATEGORIES=	textproc python
MASTER_SITES=	http://www.rexx.com/~dkuhlman/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pysgrep-${PORTVERSION}

MAINTAINER=	ijliao@freebsd.org

USE_PYTHON=	yes
GNU_CONFIGURE=	yes

do-build:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} setup.py build)

do-install:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} setup.py install)

.include <bsd.port.mk>
