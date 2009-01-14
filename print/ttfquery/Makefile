# ex:ts=8
# Ports collection makefile for:	TTFQuery
# Date created:			Jan 5, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	ttfquery
PORTVERSION=	1.0.1
CATEGORIES=	print
MASTER_SITES=	SF
DISTNAME=	TTFQuery-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	FontTools-based package for querying system fonts

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/FontTools.pth:${PORTSDIR}/print/py-fonttools \
		${PYNUMPY}

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	TTFQuery

.include <bsd.port.mk>
