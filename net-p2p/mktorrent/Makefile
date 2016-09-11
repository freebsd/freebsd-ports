# Created by: Damian Gerow <dgerow@afflictions.org>
# $FreeBSD$

PORTNAME=	mktorrent
PORTVERSION=	1.0
CATEGORIES=	net-p2p
MASTER_SITES=	SF

MAINTAINER=	dgerow@afflictions.org
COMMENT=	Command-line utility for creating BitTorrent metainfo files

.if defined(.PARSEDIR)
USES=		gmake
.else
MAKEFILE=	BSDmakefile
.endif
MAKE_FLAGS=	USE_LONG_OPTIONS=1

PLIST_FILES=	bin/mktorrent

OPTIONS_DEFINE=	THREADS OPENSSL HASHCHECK
OPTIONS_DEFAULT=	THREADS OPENSSL HASHCHECK
THREADS_DESC=	Enable support for pthreads
OPENSSL_DESC=	Use OpenSSL for hashing
HASHCHECK_DESC=	Verify file hashes

OPENSSL_USES=		ssl
OPENSSL_CFLAGS=		-I${OPENSSLINC}
OPENSSL_LDFLAGS=	-L${OPENSSLLIB}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTHREADS}
MAKE_FLAGS+=	USE_PTHREADS=1
.endif

.if ${PORT_OPTIONS:MOPENSSL}
MAKE_FLAGS+=	USE_OPENSSL=1
.endif

.if ! ${PORT_OPTIONS:MHASHCHECK}
MAKE_FLAGS+=	NO_HASH_CHECK=1
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
