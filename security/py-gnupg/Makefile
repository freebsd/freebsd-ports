# ex:ts=8
# New ports collection makefile for:	py-gnupg
# Date created:			Jul 11, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gnupg
PORTVERSION=	0.3.2
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	py-gnupg
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	GnuPGInterface-${PORTVERSION}

MAINTAINER=	shell@shellhung.org

USE_PYTHON=	yes

SETUP_CMD=	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} setup.py

do-build:
	@${SETUP_CMD} build

do-install:
	@${SETUP_CMD} install -c -O1 --prefix=${PREFIX}

.include <bsd.port.mk>
