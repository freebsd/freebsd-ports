# New ports collection makefile for:	py-Lightbox
# Date created:		2007-02-14
# Whom:			Nicola Vitale <nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Lightbox
PORTVERSION=	2.1
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP \
		http://nivi.interfree.it/distfiles/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Lightbox photo display widget for TurboGears

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}TurboGears>=1.0:${PORTSDIR}/www/py-turbogears
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}scriptaculous>=1.8.1:${PORTSDIR}/www/py-scriptaculous

USE_PYTHON=	2.5+
USE_PYDISTUTILS=	easy_install
USE_ZIP=	yes

.include <bsd.port.mk>
