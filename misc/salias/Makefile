# ex:ts=8
# New ports collection makefile for:	salias
# Date created:			May 16, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	salias
PORTVERSION=	0.2.0
CATEGORIES=	misc python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	py-${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

USE_PYTHON=	yes
SETUP_CMD=	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} setup.py

do-build:
	@${SETUP_CMD} build

do-install:
	@${SETUP_CMD} install

.include <bsd.port.mk>
