# New ports collection makefile for:	bsdhwmon
# Date created:				5 October 2008
# Whom:					Jeremy Chadwick <jdc@parodius.com>
#
# $FreeBSD$
#

PORTNAME=	bsdhwmon
PORTVERSION=	20120702
CATEGORIES=	sysutils
MASTER_SITES=	http://bsdhwmon.koitsu.org/dist/

MAINTAINER=	jdc@koitsu.org
COMMENT=	Hardware sensor monitoring utility for FreeBSD

PLIST_FILES=	sbin/bsdhwmon
MAN8=		bsdhwmon.8

OPTIONS_DEFINE=	DEBUG
DEBUG_DESC=	Enable debug build

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MDEBUG}
MAKE_ARGS+=	DEBUG=1
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bsdhwmon ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/bsdhwmon.8 ${MAN8PREFIX}/man/man8

.include <bsd.port.post.mk>
