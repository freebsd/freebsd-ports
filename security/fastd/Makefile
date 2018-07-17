# $FreeBSD$

PORTNAME=		fastd
PORTVERSION=		18
PORTREVISION=		3
CATEGORIES=		security net
MASTER_SITES=		https://git.universe-factory.net/fastd/snapshot/

MAINTAINER=		crest_maintainer@rlwinm.de
COMMENT=		Fast and Secure Tunnelling Daemon

LICENSE=		BSD2CLAUSE
LICENSE_FILE=		${WRKSRC}/COPYRIGHT

BROKEN=			fails to build: cipher_aes128_ctr_nacl.c:36:10: 'crypto_stream_aes128ctr.h' file not found
DEPRECATED=	Broken for more than 5 months
EXPIRATION_DATE=	2018-08-20

LIB_DEPENDS=		libjson-c.so:devel/json-c       \
			libsodium.so:security/libsodium \
			libuecc.so:security/libuecc

USES=			bison cmake:outsource pkgconfig tar

USE_RC_SUBR=		fastd

PLIST_FILES=		bin/fastd           \
			man/man1/fastd.1.gz

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/fastd.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
