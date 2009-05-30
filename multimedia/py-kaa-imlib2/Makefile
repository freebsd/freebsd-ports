# New ports collection makefile for:	py-kaa-imlib2
# Date created:		2009 January 10
# Whom:			J.R. Oldroyd <fbsd@opal.com>
#
# $FreeBSD$
#

PORTNAME=	kaa-imlib2
PORTVERSION=	0.2.3
PORTREVISION=	1
CATEGORIES=	multimedia python
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	freevo
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	fbsd@opal.com
COMMENT=	Kaa Media Repository - imlib2 wrapper for python

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/kaa/__init__.py:${PORTSDIR}/multimedia/py-kaa-base
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_EFL=	imlib2

.include <bsd.port.mk>
