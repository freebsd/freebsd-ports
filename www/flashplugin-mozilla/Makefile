# New ports collection makefile for:	flashplugin-mozilla
# Date created:				25 October 2001
# Whom:					Leland Wang <llwang@infor.org>
#
# $FreeBSD$
#

PORTNAME=	flashplugin-mozilla
PORTVERSION=	0.4.10
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.swift-tools.com/Flash/
DISTNAME=	flash-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	llwang@infor.org

LIB_DEPENDS=	flash.0:${PORTSDIR}/graphics/libflash
RUN_DEPENDS=	mozilla:${PORTSDIR}/www/mozilla

USE_X_PREFIX=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}/Plugin

do-install:
.if exists(${X11BASE}/lib/mozilla)
	@${ECHO_MSG} "Installing flashplugin for mozilla"
	@${INSTALL_PROGRAM} ${WRKSRC}/npflash.so ${X11BASE}/lib/mozilla/plugins
.endif
.if exists(${X11BASE}/lib/mozilla-devel)
	@${ECHO_MSG} "Installing flashplugin for mozilla-devel"
	@${INSTALL_PROGRAM} ${WRKSRC}/npflash.so ${X11BASE}/lib/mozilla-devel/plugins
.endif

.include <bsd.port.mk>
