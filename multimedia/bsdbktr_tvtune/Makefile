# New ports collection makefile for:	bsdbktr_tvtune
# Date created:		Sun Jan  4 17:49:00 EST 2004
# Whom:			Mina Naguib <webmaster@topfx.com>
#
# $FreeBSD$
#

PORTNAME=	bsdbktr_tvtune
PORTVERSION=	0.02
CATEGORIES=	multimedia
MASTER_SITES=	http://www.topfx.com/dist/

MAINTAINER=	webmaster@topfx.com
COMMENT=	A console Brooktree (bktr) TV tuner

PLIST_FILES=	bin/bsdbktr_tvtune
WRKSRC=	${WRKDIR}/${PORTNAME}
ALL_TARGET=	bsdbktr_tvtune

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bsdbktr_tvtune ${PREFIX}/bin/

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
ONLY_FOR_ARCHS=	i386
.else
ONLY_FOR_ARCHS=	alpha i386 ia64
.endif

.include <bsd.port.post.mk>
