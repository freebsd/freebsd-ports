# ex:ts=8
# Ports collection makefile for:	py-mhash
# Date created:			Feb 10, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	mhash
PORTVERSION=	1.0
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	mhash
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-mhash-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	mhash:${PORTSDIR}/security/mhash

USE_PYTHON=	yes
CFLAGS+=	-I${LOCALBASE}/include

SETUP_CMD=	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} setup.py

do-build:
	@${SETUP_CMD} build_ext -L${LOCALBASE}/lib

do-install:
	@${SETUP_CMD} install

.include <bsd.port.mk>
