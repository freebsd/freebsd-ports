# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	web_search
PORTVERSION=	0.1.6
PORTREVISION=	3
CATEGORIES=		mail www

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Plugin for Websearch

LICENSE=	GPLv2

USE_SM_COMPAT=	yes
USE_GENERIC_PKGMESSAGE=	yes

SQUIRREL_PLUGIN_CONFIG=	${SQUIRREL_PLUGIN_NAME}.conf.php

NO_STAGE=	yes

post-patch:
	@${MV} ${WRKSRC}/${_SMSRCDIR}/${SQUIRREL_PLUGIN_CONFIG}.dist ${WRKSRC}/${_SMSRCDIR}/${SQUIRREL_PLUGIN_CONFIG}.sample

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../squirrelmail/bsd.squirrelmail.mk"
.include <bsd.port.post.mk>
