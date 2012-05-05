# New ports collection makefile for:	dfc
# Date created:		2012-04-01
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dfc
PORTVERSION=	2.5.0
CATEGORIES=	sysutils
MASTER_SITES=	http://projects.gw-computing.net/attachments/download/42/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Display file system space usage using graph and colors

LICENSE=	BSD

PLIST_FILES=	bin/dfc
MAN1=		dfc.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800000
BROKEN=		does not compile on FreeBSD 7.X
.endif

.include <bsd.port.post.mk>
