# ex:ts=8
# Ports collection makefile for:	py-probstat
# Date created:			Oct 12, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	probstat
PORTVERSION=	0.912
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}_${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Probability And Statistics Utils for Python

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/probstat.so
PLIST_SUB=	PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR:S,^${LOCALBASE}/,,g}
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

.include <bsd.port.mk>
