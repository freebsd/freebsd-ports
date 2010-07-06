# New ports collection makefile for:	mktorrent
# Date created:		9 May 2010
# Whom:			Damian Gerow <dgerow@afflictions.org>
#
# $FreeBSD$
#

PORTNAME=	mktorrent
PORTVERSION=	1.0
CATEGORIES=	net-p2p
MASTER_SITES=	SF

MAINTAINER=	dgerow@afflictions.org
COMMENT=	A command-line utility for creating BitTorrent metainfo files

MAKEFILE=	BSDmakefile
MAKE_FLAGS=	USE_LONG_OPTIONS=1

PLIST_FILES=	bin/mktorrent

OPTIONS=	THREADS		"Enable support for pthreads"		on \
		OPENSSL		"Use OpenSSL for hashing"		on \
		HASHCHECK	"Verify file hashes" 			on

.include <bsd.port.options.mk>

.if !defined(WITHOUT_THREADS)
MAKE_FLAGS+=	USE_PTHREADS=1
.endif

.if !defined(WITHOUT_OPENSSL)
MAKE_FLAGS+=	USE_OPENSSL=1
USE_OPENSSL=	yes
.endif

.if defined(WITHOUT_HASHCHECK)
MAKE_FLAGS+=	NO_HASH_CHECK=1
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|-lpthread|${PTHREAD_LIBS}|g" ${WRKSRC}/BSDmakefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
