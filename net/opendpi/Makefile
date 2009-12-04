# New ports collection makefile for:	opendpi
# Date created:		13 November 2009
# Whom:			fernandotcl
#
# $FreeBSD$
#

PORTNAME=	opendpi
PORTVERSION=	1.1.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	fernando@netfilter.com.br
COMMENT=	An open source deep packet inspection engine

GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64: includes i386 assembler
.endif

.include <bsd.port.post.mk>
