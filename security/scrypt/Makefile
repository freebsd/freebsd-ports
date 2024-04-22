PORTNAME=	scrypt
PORTVERSION=	1.3.2
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.tarsnap.com/scrypt/

MAINTAINER=	cperciva@tarsnap.com
COMMENT=	Key Derivation Function
WWW=		http://www.tarsnap.com/scrypt/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USES=		libtool ssl tar:tgz

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ENV=	CFLAGS="-I${OPENSSLINC} ${CFLAGS}" \
		LDFLAGS="-L${OPENSSLLIB} ${LDFLAGS}"
CONFIGURE_ARGS=	--enable-libscrypt-kdf --disable-static

PLIST_FILES=	bin/scrypt \
		include/scrypt-kdf.h \
		lib/libscrypt-kdf.so \
		lib/libscrypt-kdf.so.1 \
		lib/libscrypt-kdf.so.1.0.0 \
		share/man/man1/scrypt.1.gz

.include <bsd.port.mk>
