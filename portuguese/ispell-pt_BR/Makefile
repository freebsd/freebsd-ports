# New ports collection makefile for: br-ispell
# Date created:         5 February 1999
# Whom:                 Joao Carlos Mendes Luis <jonny@jonny.eng.br>
#
# $FreeBSD$
#

PORTNAME=	ispell
PORTVERSION=	2.4
CATEGORIES=	portuguese textproc
MASTER_SITES=	ftp://ftp.ime.usp.br/pub/ueda/br.ispell/
PKGNAMEPREFIX=	pt_BR-
DISTNAME=	br.ispell-2.4

MAINTAINER=	jonny@jonny.eng.br

BUILD_DEPENDS=	buildhash:${PORTSDIR}/textproc/ispell

MAN1=		conjugue.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 500000
BROKEN=		"Does not build on 5.0"
.endif

.include <bsd.port.post.mk>
