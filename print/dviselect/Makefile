# New ports collection makefile for:    dviselect
# Date created:         12 October 1994
# Whom:                 jmz
#
# $FreeBSD$
#

PORTNAME=	dviselect
PORTVERSION=	1.3
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	jmz

DISTNAME=	${PORTNAME}

MAINTAINER=	jmz@FreeBSD.org
COMMENT=	Extract pages from DVI files

SCRIPTS_ENV=	CFLAGS="${CFLAGS}"

MAN1=		dviselect.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 501000
BROKEN=		"Does not compile"
.endif

.include <bsd.port.post.mk>
