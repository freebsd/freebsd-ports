# New ports collection makefile for:	pmap
# Date created:		14 Oct 2002
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	pmap
PORTVERSION=	20021014
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.wuppy.net.ru/pub/FreeBSD/local/pmap/

MAINTAINER=	skv@FreeBSD.org

PLIST_SUB=	KMODDIR=${KMODDIR}
WRKSRC=		${WRKDIR}/${PORTNAME}

MAN8=		pmap.8
MANCOMPRESSED=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500000
BROKEN=		"Currently does not support -CURRENT"
.endif

.if ${OSVERSION} <  450000
BROKEN=		"Not supported on systems prior to 4.5"
.endif

.include <bsd.port.post.mk>
