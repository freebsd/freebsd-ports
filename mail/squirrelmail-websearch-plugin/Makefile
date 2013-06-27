# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	websearch
PORTVERSION=	0.1.6
PORTREVISION=	1
DISTNAME=	${SQUIRREL_PLUGIN_NAME}-${PORTVERSION}
DIST_SUBDIR=	squirrelmail

MAINTAINER=	tabthorpe@FreeBSD.org
COMMENT=	Plugin for Websearch

LICENSE=	GPLv2

RUN_DEPENDS+=	${SQUIRRELDIR}/plugins/compatibility:${PORTSDIR}/mail/squirrelmail-compatibility-plugin

SQUIRREL_PLUGIN_NAME=	web_search

.include "${.CURDIR}/../squirrelmail/bsd.squirrelmail.mk"
.include <bsd.port.mk>
