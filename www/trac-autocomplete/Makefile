# Created by: Eygene Ryabinkin <rea-fbsd@codelabs.ru>
# $FreeBSD$

PORTNAME=	autocomplete
PORTVERSION=	0.4.1
PORTREVISION=	6
CATEGORIES=	www python
MASTER_SITES=	http://dist.codelabs.ru/fbsd/
PKGNAMEPREFIX=	trac-
DISTNAME=	autocompleteusersplugin-r${REL}

MAINTAINER=	rea@FreeBSD.org
COMMENT=	Plugin for autocompletion of user names in ticket fields

RUN_DEPENDS+=	trac>=0.11:www/trac

USES=		python:2 zip
USE_PYTHON=	distutils autoplist
WRKSRC=		${WRKDIR}/autocompleteusersplugin/0.11
REL=		8451

.include "${.CURDIR}/../../www/trac/plugin.mk"
.include <bsd.port.mk>
