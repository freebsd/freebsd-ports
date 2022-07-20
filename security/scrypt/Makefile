PORTNAME=	scrypt
PORTVERSION=	1.3.1
CATEGORIES=	security
MASTER_SITES=	http://www.tarsnap.com/scrypt/

MAINTAINER=	cperciva@tarsnap.com
COMMENT=	Key Derivation Function

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USES=		libtool ssl tar:tgz

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CFLAGS="-I${OPENSSLINC} ${CFLAGS}" \
		LDFLAGS="-L${OPENSSLLIB} ${LDFLAGS}"
CONFIGURE_ARGS=	--enable-libscrypt-kdf --disable-static

PLIST_FILES=	bin/scrypt \
		include/scrypt-kdf.h \
		lib/libscrypt-kdf.so.1.0.0 \
		man/man1/scrypt.1.gz

.include <bsd.port.mk>
