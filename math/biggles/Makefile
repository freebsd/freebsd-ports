# ex:ts=8
# New ports collection makefile for:	biggles
# Date created:			Nov 25, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	biggles
PORTVERSION=	1.6.3
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	python-${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Create publication-quality 2D scientific plots

BUILD_DEPENDS=	${PYNUMERIC}
LIB_DEPENDS=	plot:${PORTSDIR}/graphics/plotutils

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

.include <bsd.port.mk>
