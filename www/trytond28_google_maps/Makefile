# Created by: Matthias Petermann <matthias@petermann-it.de>
# $FreeBSD$

PORTNAME=	trytond28_google_maps
PORTVERSION=	2.8.0
PORTREVISION=	3
CATEGORIES=	www finance python
MASTER_SITES=	https://pypi.python.org/packages/source/t/trytond_google_maps/ \
		http://downloads-cdn.tryton.org/${PORTVERSION:R}/
DISTNAME=	trytond_google_maps-${PORTVERSION}

MAINTAINER=	matthias@petermann-it.de
COMMENT=	Tryton Application Platform (Google Maps Module)

DEPRECATED=	Outdated, uses EOLed python27
EXPIRATION_DATE=	2020-02-03

LICENSE=	GPLv3

RUN_DEPENDS=	trytond28_party>=2.8.0:finance/trytond28_party

CONFLICTS=	trytond_google_maps-2.[46].*

USES=		python:2.7
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
