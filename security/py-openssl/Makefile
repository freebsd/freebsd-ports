# ex:ts=8
# Ports collection makefile for:	py-openssl
# Date created:			Feb 10, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	openssl
PORTVERSION=	0.4.1
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pyopenssl
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyOpenSSL-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

USE_PYTHON=	yes
USE_OPENSSL=	yes

SETUP_CMD=	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} setup.py

do-build:
	@${SETUP_CMD} build

do-install:
	@${SETUP_CMD} install

.include <bsd.port.mk>
