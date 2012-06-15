# New ports collection makefile for:	dfc
# Date created:		2012-04-01
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dfc
PORTVERSION=	3.0.0
CATEGORIES=	sysutils
MASTER_SITES=	http://projects.gw-computing.net/attachments/download/63/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Display file system space usage using graph and colors

LICENSE=	BSD

OPTIONS_DEFINE=	NLS

USE_CMAKE=	yes
CMAKE_ARGS+=	-DMAN_PATH=${MANPREFIX}/man -DDFC_DOC_PATH=${DOCSDIR}
MANLANG=	"" fr
MAN1=		dfc.1

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
CMAKE_ARGS+=	-DNLS_ENABLED=true
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CMAKE_ARGS+=	-DNLS_ENABLED=false
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.mk>
