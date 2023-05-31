PORTNAME=	libressl
PORTVERSION=	3.8.0
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
default_CONFLICTS_INSTALL=	openssl openssl3[01] openssl-quictls

.if ${FLAVOR:U} == default
OPTIONS_EXCLUDE=	LIBTLS
.elif ${FLAVOR:U} == libtls
OPTIONS_SLAVE=		LIBTLS
OPTIONS_EXCLUDE=	MAN3
.endif

LIBTLS_CONFIGURE_ENABLE=	libtls-only
NC_CONFIGURE_ENABLE=		nc

GNU_CONFIGURE=	yes
USES=		cpe libtool pathfix pkgconfig
USE_LDCONFIG=	yes
OPTIONS_SUB=	yes
CFLAGS+=	-fpic -DPIC -Wl,-rpath,${PREFIX}/lib -Wl,--as-needed
LDFLAGS+=	-pthread

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

PLIST_SUB+=	LIBCRYPTO_SHLIBMAJ=51 \
		LIBCRYPTO_SHLIBFULL=51.0.0 \
		LIBSSL_SHLIBMAJ=54 \
		LIBSSL_SHLIBFULL=54.0.0 \
		LIBTLS_SHLIBMAJ=27 \
		LIBTLS_SHLIBFULL=27.0.0

post-patch-MAN3-off:
	${REINPLACE_CMD} -e '/^install-man:/s/install-man3//' \
		-e '/$$(MAKE) $$(AM_MAKEFLAGS) install-data-hook/d' \
		${WRKSRC}/man/Makefile.in

post-install:
	${RM} -r ${STAGEDIR}/${PREFIX}/etc/ssl/cert.pem

post-stage-MAN3-on:
	(cd ${STAGEDIR}${MANPREFIX}; ${FIND} man/man3 -not -type d | \
		${SED} 's/$$/.gz/' >> ${TMPPLIST})

.include <bsd.port.mk>
