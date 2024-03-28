PORTNAME=	bacula
PKGNAMESUFFIX=	15-client-static

COMMENT=	Network backup solution (static client)

BROKEN_aarch64=	Fails to link: missing sbrk
BROKEN_riscv64=	Fails to link: missing sbrk
BROKEN_SSL=	libressl

WITH_CLIENT_ONLY=	yes
PLIST=			${.CURDIR}/pkg-plist
MASTERDIR=		${.CURDIR}/../../sysutils/bacula15-server

PLIST_FILES=	sbin/bacula-fd-static \
		sbin/bconsole-static

OPTIONS_DEFINE=		NLS OPENSSL
OPTIONS_DEFAULT=	OPENSSL

CONFIGURE_ARGS+=	--disable-build-dird \
			--disable-build-stored \
			--disable-libtool \
			--enable-client-only \
			--enable-static-cons \
			--enable-static-fd

.include "${MASTERDIR}/Makefile"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/filed/static-bacula-fd  ${STAGEDIR}${PREFIX}/sbin/bacula-fd-static
	${INSTALL_PROGRAM} ${WRKSRC}/src/console/static-bconsole ${STAGEDIR}${PREFIX}/sbin/bconsole-static
