# New ports collection makefile for:	gkrellm-mailwatch
# Date Created:		22.08.2000
# Whom:			Tobias Reifenberger <treif@mayn.de>
#
# $FreeBSD$
#

PORTNAME=	gkrellmmailwatch
PORTVERSION=	0.7.2
PORTREVISION=	5
CATEGORIES=	mail
MASTER_SITES=	http://gkrellm.luon.net/files/
DISTNAME=	mailwatch-${PORTVERSION}

MAINTAINER=	treif@mayn.de
COMMENT=	GKrellM mailwatch plugin

BUILD_DEPENDS=	${LOCALBASE}/include/gkrellm/gkrellm.h:${PORTSDIR}/sysutils/gkrellm
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm

PLIST_FILES=	libexec/gkrellm/plugins/mailwatch.so
USE_GNOME=	imlib

do-install:
	${MKDIR} ${PREFIX}/libexec/gkrellm/plugins
	${INSTALL_PROGRAM} ${WRKSRC}/mailwatch.so ${PREFIX}/libexec/gkrellm/plugins

.include <bsd.port.mk>
