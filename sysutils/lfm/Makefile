# ex:ts=8
# New ports collection makefile for:	lfm
# Date created:			Jul 21, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	lfm
PORTVERSION=	0.4
CATEGORIES=	sysutils
MASTER_SITES=	http://www.terra.es/personal7/inigoserna/lfm/

MAINTAINER=	ports@FreeBSD.org

USE_PYTHON=	yes
SETUP_CMD=	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} setup.py

do-build:
	@${SETUP_CMD} build

do-install:
	@${SETUP_CMD} install

.include <bsd.port.mk>
