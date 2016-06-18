# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	scrypt
PORTVERSION=	1.2.0
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.tarsnap.com/scrypt/

MAINTAINER=	cperciva@tarsnap.com
COMMENT=	Key Derivation Function

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CFLAGS="-I${OPENSSLINC} ${CFLAGS}" \
		LDFLAGS="-L${OPENSSLLIB} ${LDFLAGS}"

USES=		gmake tar:tgz
USE_OPENSSL=	YES

PLIST_FILES=	bin/scrypt \
		man/man1/scrypt.1.gz

.include <bsd.port.mk>
