# New ports collection makefile for:	py-csv
# Date created:		17 January 2002
# Whom:	      		Johann Visagie <wjv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dsv
PORTVERSION=	1.3.3
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	python-${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:U}-${PORTVERSION}

MAINTAINER=	wjv@FreeBSD.org

BUILD_DEPENDS=	${PYDISTUTILS}

USE_PYTHON=	yes
PYTHON_SETUP=	${SETENV} ${MAKE_ENV} ${PYTHON_CMD} setup.py

do-build:
	@ cd ${WRKSRC} && ${PYTHON_SETUP} build

do-install:
	@ cd ${WRKSRC} && ${PYTHON_SETUP} install -c -O1 --prefix=${PREFIX}

.include <bsd.port.mk>
