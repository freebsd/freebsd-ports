PORTNAME=	libressl
PORTVERSION=	3.9.0
CATEGORIES=	security devel
MASTER_SITES=	OPENBSD/LibreSSL
PKGNAMESUFFIX=	-devel

MAINTAINER=	brnrd@FreeBSD.org
COMMENT=	Free version of the SSL/TLS protocol forked from OpenSSL
WWW=		https://www.libressl.org/

LICENSE=	BSD4CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

FLAVORS=	default libtls
FLAVOR?=	${FLAVORS:[1]}
libtls_DESCR=	pkg-descr-libtls
libtls_PKGNAMESUFFIX=	-devel-libtls
libtls_PLIST=	pkg-plist-libtls

CPE_VENDOR=	openbsd

OPTIONS_DEFINE=	LIBTLS MAN3 NC
OPTIONS_DEFAULT=	MAN3 NC
LIBTLS_DESC=	Only install libtls (no libcrypto/libssl)
MAN3_DESC=	Install API manpages (section 3)
NC_DESC=	Install TLS-enabled netcat

CONFLICTS_INSTALL=		libressl \
				libretls
default_CONFLICTS_INSTALL=	openssl openssl111 openssl3[12] openssl-quictls

.if ${FLAVOR:U} == default
OPTIONS_EXCLUDE=	LIBTLS
.elif ${FLAVOR:U} == libtls
OPTIONS_SLAVE=		LIBTLS
OPTIONS_EXCLUDE=	MAN3
.endif

LIBTLS_CONFIGURE_ENABLE=	libtls-only
NC_CONFIGURE_ENABLE=		nc

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
USES=		cpe libtool pathfix pkgconfig
USE_LDCONFIG=	yes
OPTIONS_SUB=	yes
CFLAGS+=	-fpic -DPIC -Wl,-rpath,${PREFIX}/lib -Wl,--as-needed
LDFLAGS+=	-pthread

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

PLIST_SUB+=	LIBCRYPTO_SHLIBMAJ=53 \
		LIBCRYPTO_SHLIBFULL=53.0.0 \
		LIBSSL_SHLIBMAJ=56 \
		LIBSSL_SHLIBFULL=56.0.0 \
		LIBTLS_SHLIBMAJ=29 \
		LIBTLS_SHLIBFULL=29.0.0

post-patch-MAN3-off:
	${REINPLACE_CMD} -e '/^install-man:/s/install-man3//' \
		-e '/$$(MAKE) $$(AM_MAKEFLAGS) install-data-hook/d' \
		${WRKSRC}/man/Makefile.in

post-install:
	${RM} -r ${STAGEDIR}/${PREFIX}/etc/ssl/cert.pem
	${RMDIR} ${STAGEDIR}${PREFIX}/etc/ssl/certs
	${LN} -s /etc/ssl/certs ${STAGEDIR}${PREFIX}/etc/ssl/certs

post-stage-MAN3-on:
	(cd ${STAGEDIR}${PREFIX}; ${FIND} share/man/man3 -not -type d | \
		${SED} 's/$$/.gz/' >> ${TMPPLIST})

.include <bsd.port.mk>
