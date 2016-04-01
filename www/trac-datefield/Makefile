# Created by: Eygene Ryabinkin <rea-fbsd@codelabs.ru>
# $FreeBSD$

PORTNAME=	datefield
PORTVERSION=	1.0.1
PORTREVISION=	4
CATEGORIES=	www python
MASTER_SITES=	http://dist.codelabs.ru/fbsd/
PKGNAMEPREFIX=	trac-
DISTNAME=	datefieldplugin-r${REL}

MAINTAINER=	rea@FreeBSD.org
COMMENT=	Plugin for creating date fields

RUN_DEPENDS+=	trac>=0.11:www/trac

USES=		python:2 zip
USE_PYTHON=	distutils autoplist
WRKSRC=		${WRKDIR}/datefieldplugin/0.11
REL=		7267

.include "${.CURDIR}/../../www/trac/plugin.mk"
.include <bsd.port.mk>
