# ex:ts=8
# New ports collection makefile for:	biggles
# Date created:			Nov 25, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	biggles
PORTVERSION=	1.6.0
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	python-${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${PYDISTUTILS} \
		${PYTHON_SITELIBDIR}/Numeric.pth:${PORTSDIR}/math/py-numeric
LIB_DEPENDS=	plot:${PORTSDIR}/graphics/plotutils

USE_PYTHON=	yes

SETUP_CMD=	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} setup.py

do-build:
	@${SETUP_CMD} build

do-install:
	@${SETUP_CMD} install

.include <bsd.port.mk>
