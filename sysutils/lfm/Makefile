# ex:ts=8
# New ports collection makefile for:	lfm
# Date created:			Jul 21, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	lfm
PORTVERSION=	0.7
CATEGORIES=	sysutils
MASTER_SITES=	http://www.terra.es/personal7/inigoserna/lfm/

MAINTAINER=	ports@FreeBSD.org

USE_PYTHON=	yes
SETUP_CMD=	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} setup.py

do-build:
	@${SETUP_CMD} build

pre-install:
	@${SH} ${PKGREQ} INSTALL

do-install:
	@${SETUP_CMD} install -c -O1 --prefix=${PREFIX}

.include <bsd.port.mk>
