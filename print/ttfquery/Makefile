# ex:ts=8
# Ports collection makefile for:	TTFQuery
# Date created:			Jan 5, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	ttfquery
PORTVERSION=	0.2.6
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	TTFQuery-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	FontTools-based package for querying system fonts

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/FontTools.pth:${PORTSDIR}/print/py-fonttools \
		${PYNUMERIC}

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

.include <bsd.port.mk>
