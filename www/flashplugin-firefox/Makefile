# New ports collection makefile for:	flashplugin-firefox
# Date created:				16.07.2004
# Whom:					Roman Y. Bogdanov <sam@brj.pp.ru>
#
# $FreeBSD$
#

PORTNAME=	flashplugin-firefox
PORTVERSION=	0.4.10
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.swift-tools.net/Flash/
DISTNAME=	flash-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	sam@brj.pp.ru
COMMENT=	A GPL standalone Flash (TM) plugin for FireFox web browser

LIB_DEPENDS=	flash.0:${PORTSDIR}/graphics/libflash
RUN_DEPENDS?=	firefox:${PORTSDIR}/www/firefox

USE_X_PREFIX=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}/Plugin
PLUGIN_DIR?=	lib/firefox/lib/firefox-0.9.3/plugins
PLIST_SUB+=	PLUGIN_DIR=${PLUGIN_DIR}

do-install:
	@${MKDIR} ${PREFIX}/${PLUGIN_DIR}
	@${INSTALL_PROGRAM} ${WRKSRC}/npflash.so ${PREFIX}/${PLUGIN_DIR}

.include <bsd.port.mk>
