# New ports collection makefile for:   nakenchat
# Date created:        01 July 2003
# Whom:                Michael Kohn  (mike@mikekohn.net)
#
# $FreeBSD$
#

PORTNAME=	nakenchat
PORTVERSION=	2.00
CATEGORIES=	net
MASTER_SITES=	http://www.mikekohn.com/nakenchat/

MAINTAINER=	mike@mikekohn.net
COMMENT=	Small (under 50k) chat server with many features

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502102
IGNORE=		Does not respect PTHREAD_{CFLAGS,LIBS} (or CFLAGS or CC, ...)
.endif

.include <bsd.port.post.mk>
