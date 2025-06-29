PORTNAME=	tpm2-tss
DISTVERSION=	4.0.1
PORTREVISION=	3
CATEGORIES=	security
MASTER_SITES=	https://github.com/tpm2-software/tpm2-tss/releases/download/${DISTVERSION}/

MAINTAINER=	tstruk@gmail.com
COMMENT=	TPM2 Software Stack core library

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libjson-c.so:devel/json-c \
		libcurl.so:ftp/curl \
		libuuid.so:misc/libuuid

USES=		compiler:c11 gmake libtool pkgconfig ssl
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ENV=	CRYPTO_CFLAGS="-I${OPENSSLINC}" CRYPTO_LIBS="-L${OPENSSLLIB} -lcrypto" \
		EXTRA_CFLAGS="-I${LOCALBASE}/include"

KEYDIR=		/var/lib/tpm2-tss/system/keystore
RUNDIR=		/var/run/tpm2-tss/eventlog
CONFIGURE_ARGS=	--disable-doxygen-doc --disable-dependency-tracking --enable-valgrind=no \
		--with-runstatedir=${RUNDIR}

INSTALL_TARGET=	install-strip

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/lib/udev/rules.d/tpm-udev.rules
	@${RMDIR} ${STAGEDIR}${PREFIX}/lib/udev/rules.d
	@${RMDIR} ${STAGEDIR}${PREFIX}/lib/udev
	@${MKDIR} ${STAGEDIR}${RUNDIR}
	@${MKDIR} ${STAGEDIR}${KEYDIR}

.include <bsd.port.mk>
