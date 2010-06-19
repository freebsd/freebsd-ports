# New ports collection makefile for:	googlecl
# Date created:		2010-06-19
# Whom:			Li-Wen Hsu <lwhsu@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	googlecl
PORTVERSION=	0.9.5
CATEGORIES=	net www python
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Command line tools for the Google Data APIs

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gdata/__init__.py:${PORTSDIR}/devel/py-gdata

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

.include <bsd.port.mk>
