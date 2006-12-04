# New ports collection makefile for:   tund
# Date created:        20 July 1999
# Whom:                Sergey Kosyakov <ks@itp.ac.ru>
#
# $FreeBSD$
#

PORTNAME=	tund
PORTVERSION=	0.20
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.cemu.ru/pub/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	IP over UDP tunnel with encryption

DEPRECATED=	distfile disappeared and has no homepage
EXPIRATION_DATE=	2007-01-04

USE_OPENSSL=	YES

MAN8=		tund.8
MANCOMPRESSED=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "sparc64"
BROKEN=		"Does not build on ${ARCH}"
.endif

.include <bsd.port.post.mk>
