# New ports collection makefile for:	py-kaa-imlib2
# Date created:		2009 January 10
# Whom:			J.R. Oldroyd <fbsd@opal.com>
#
# $FreeBSD$
#

PORTNAME=	kaa-imlib2
PORTVERSION=	0.2.3
CATEGORIES=	multimedia python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	freevo
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	fbsd@opal.com
COMMENT=	Kaa Media Repository - imlib2 wrapper for python

LIB_DEPENDS=	Imlib2.5:${PORTSDIR}/graphics/imlib2
BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/kaa/__init__.py:${PORTSDIR}/multimedia/py-kaa-base
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

.include <bsd.port.mk>
