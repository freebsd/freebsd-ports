# New ports collection makefile for:	ident2
# Date created:				30 Nov 1999
# Whom:					rod@zort.on.ca
#
# $FreeBSD$
#

PORTNAME=	ident2
PORTVERSION=	1.03
CATEGORIES=	security net
MASTER_SITES=	http://michael.bacarella.com/projects/ident2/
DISTNAME=	ident2-v${PORTVERSION}_FINAL

MAINTAINER=	scorpio@drkshdw.org
COMMENT=	An RFC1413 identification server which also supports random replies

GNU_CONFIGURE=	yes
MAN8=		ident2.8

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 501000
BROKEN=		"Does not compile"
.endif

.include <bsd.port.post.mk>
