# ex:ts=8
# New ports collection makefile for:	biggles
# Date created:			Nov 25, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	biggles
PORTVERSION=	1.6.4
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	python2-${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Create publication-quality 2D scientific plots

BUILD_DEPENDS=	${PYNUMERIC}
LIB_DEPENDS=	plot:${PORTSDIR}/graphics/plotutils

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	python2-biggles
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/X11R6|${X11BASE}|g' ${WRKSRC}/make.inc
	@${REINPLACE_CMD} -e 's|/usr/X11R6|${X11BASE}|g' ${WRKSRC}/setup.py

.include <bsd.port.mk>
