# New ports collection makefile for:	scrypt
# Date created:				26 May, 2009
# Whom:					Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	scrypt
PORTVERSION=	1.1.4
CATEGORIES=	security
MASTER_SITES=	http://www.tarsnap.com/scrypt/
EXTRACT_SUFX=	.tgz

MAINTAINER=	wenheping@gmail.com
COMMENT=	Key Derivation Function

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
PLIST_FILES=	bin/scrypt

MAN1=	scrypt.1

OPTIONS=	SSE2 "Use SSE2-optimized code" Off

.include <bsd.port.options.mk>

.if defined(WITH_SSE2)
CONFIGURE_ARGS+=	--enable-sse2
.else
CONFIGURE_ARGS+=	--disable-sse2
.endif

.include <bsd.port.mk>
