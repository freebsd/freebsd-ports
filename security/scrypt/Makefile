# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	scrypt
PORTVERSION=	1.1.6
CATEGORIES=	security
MASTER_SITES=	http://www.tarsnap.com/scrypt/
EXTRACT_SUFX=	.tgz

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Key Derivation Function

GNU_CONFIGURE=	yes
USES=	gmake
USE_LDCONFIG=	yes

PLIST_FILES=	bin/scrypt \
		man/man1/scrypt.1.gz

OPTIONS_DEFINE=	SSE2
SSE2_DESC=	Use SSE2-optimized code

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSSE2}
CONFIGURE_ARGS+=	--enable-sse2
.else
CONFIGURE_ARGS+=	--disable-sse2
.endif

.include <bsd.port.mk>
