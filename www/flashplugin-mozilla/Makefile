# New ports collection makefile for:	flashplugin-mozilla
# Date created:				25 October 2001
# Whom:					Leland Wang <llwang@infor.org>
#
# $FreeBSD$
#

PORTNAME?=	flashplugin-mozilla
PORTVERSION=	0.4.10
PORTREVISION=	5
CATEGORIES=	www
MASTER_SITES=	http://www.swift-tools.net/Flash/
DISTNAME=	flash-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	llwang@infor.org
COMMENT=	A GPL standalone Flash (TM) plugin for Mozilla web browser

LIB_DEPENDS=	flash.0:${PORTSDIR}/graphics/libflash
RUN_DEPENDS?=	mozilla:${PORTSDIR}/www/mozilla

USE_X_PREFIX=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}/Plugin
PLUGIN_DIR?=	lib/browser_plugins
PLIST_SUB+=	PLUGIN_DIR=${PLUGIN_DIR}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/npflash.so ${X11BASE}/${PLUGIN_DIR}

.include <bsd.port.mk>
