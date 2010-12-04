# Ports collection Makefile for:	userinfo
# Date created:		5 November 2002
# Whom:			Ben Kibbey <bjk@arbornet.org>
#
# $FreeBSD$
#

PORTNAME=	userinfo
PORTVERSION=	2.2
CATEGORIES=	sysutils
MASTER_SITES=	SF/bjk/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Show information about local users

USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes

MAN1=		ui.1
MLINKS=		ui.1 userinfo.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 900007
BROKEN=		fails to build with new utmpx
.endif

.include <bsd.port.post.mk>
