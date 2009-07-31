# New ports collection makefile for:	gkrellmbgchg
# Date Created:			8 Aug 2002
# Whom:				Chris Stuart <firewolf@lightningfire.net>
#
# $FreeBSD$
#

PORTNAME=	gkrellmbgchg
PORTVERSION=	0.0.4
PORTREVISION=	5
CATEGORIES=	misc
MASTER_SITES=	http://www.bender-suhl.de/stefan/comp/sources/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A plugin for GKrellM, which changes the desktop's background image

BUILD_DEPENDS=	${LOCALBASE}/include/gkrellm/gkrellm.h:${PORTSDIR}/sysutils/gkrellm
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm

USE_GNOME=	imlib

PLIST_FILES=	libexec/gkrellm/plugins/gkrellmbgchg.so

do-install:
	${INSTALL_DATA} ${STRIP} ${WRKSRC}/gkrellmbgchg.so \
	  ${PREFIX}/libexec/gkrellm/plugins

.include <bsd.port.mk>
