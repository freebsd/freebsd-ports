# New ports collection makefile for:   tund
# Date created:        20 July 1999
# Whom:                Sergey Kosyakov <ks@itp.ac.ru>
#
# $FreeBSD$
#

PORTNAME=	tund
PORTVERSION=	0.20
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.chg.ru/pub/networking/freebsd/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	IP over UDP tunnel with encryption

USE_OPENSSL=	YES

MAN8=		tund.8
MANCOMPRESSED=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "sparc64"
BROKEN=		"Does not build on ia64 or sparc64"
.endif

.include <bsd.port.post.mk>
