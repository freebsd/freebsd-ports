# New ports collection makefile for:	bsdhwmon
# Date created:				5 October 2008
# Whom:					Jeremy Chadwick <jdc@parodius.com>
#
# $FreeBSD$
#

PORTNAME=	bsdhwmon
PORTVERSION=	20090703
CATEGORIES=	sysutils
MASTER_SITES=	http://bsdhwmon.parodius.com/dist/

MAINTAINER=	jdc@parodius.com
COMMENT=	Hardware sensor monitoring utility for FreeBSD

PLIST_FILES=	sbin/bsdhwmon
MAN8=		bsdhwmon.8

.if defined(WITH_DEBUG)
MAKE_ARGS+=	DEBUG=1
.endif

.include <bsd.port.pre.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bsdhwmon ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/bsdhwmon.8 ${MAN8PREFIX}/man/man8

.include <bsd.port.post.mk>
