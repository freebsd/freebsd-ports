# Created by: Tobias Reifenberger <treif@mayn.de>
# $FreeBSD$

PORTNAME=	gkrellmmailwatch
PORTVERSION=	0.7.2
PORTREVISION=	8
CATEGORIES=	mail
MASTER_SITES=	http://gkrellm.luon.net/files/
DISTNAME=	mailwatch-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GKrellM mailwatch plugin

BUILD_DEPENDS=	${LOCALBASE}/include/gkrellm/gkrellm.h:${PORTSDIR}/sysutils/gkrellm
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm

PLIST_FILES=	libexec/gkrellm/plugins/mailwatch.so
USES=		pkgconfig
USE_GNOME=	imlib

do-install:
	${MKDIR} ${PREFIX}/libexec/gkrellm/plugins
	${INSTALL_PROGRAM} ${WRKSRC}/mailwatch.so ${PREFIX}/libexec/gkrellm/plugins

.include <bsd.port.mk>
