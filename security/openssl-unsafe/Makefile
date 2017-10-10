# Created by: Dirk Froemberg <dirk@FreeBSD.org>
# $FreeBSD$

PORTNAME=	openssl
PORTVERSION=	1.0.2.20170706
CATEGORIES=	security devel
PKGNAMESUFFIX=	-unsafe

MAINTAINER=	brnrd@FreeBSD.org
COMMENT=	Unsafe SSL and crypto library

LICENSE=	OpenSSL
LICENSE_FILE=	${WRKSRC}/LICENSE

CPE_VERSION=	1.0.2k

USES=		cpe perl5
USE_PERL5=	build
MAKE_ENV+=	LIBRPATH="${PREFIX}/openssl-unsafe/lib" GREP_OPTIONS= SHLIBVER=${OPENSSL_SHLIBVER}
CFLAGS+=	-fPIC -DPIC
SUB_FILES=	pkg-message
PLIST_SUB+=	SHLIBVER=${OPENSSL_SHLIBVER}
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	PeterMosmans
GH_TAGNAME=	c9ba19c8b7fd131137373dbd1fccd6a8bb0628be

MAKE_JOBS_UNSAFE=	yes

CONFIGURE_ARGS=	enable-camellia enable-cms enable-ec enable-ec2m enable-ec_nistp_64_gcc_128 \
		enable-ecdh enable-ecdsa enable-gost enable-idea enable-md2 enable-mdc2 \
		enable-rc2 enable-rc5 enable-rfc3779 enable-seed enable-ssl-trace \
		enable-ssl2 enable-ssl2-methods enable-ssl3 enable-weak-ssl-ciphers \
		experimental-jpake experimental-store \
		no-gmp sctp shared threads zlib zlib-dynamic

OPENSSLDIR?=	${PREFIX}/openssl-unsafe/etc
PLIST_SUB+=	OPENSSLDIR=${OPENSSLDIR:S=^${PREFIX}/==}

NOT_FOR_ARCHS=	i386

.include "version.mk"

post-patch:
	${REINPLACE_CMD} -e 's|m4 -B 8192|m4|g' \
		${WRKSRC}/crypto/des/Makefile
	${REINPLACE_CMD} -e 's|all install_docs |all |;s| tools$$||;s| build_tools$$||' ${WRKSRC}/Makefile.org

do-configure:
	${REINPLACE_CMD} -e "s|options 386|options|" \
		${WRKSRC}/config
	cd ${WRKSRC} \
	&& ${SETENV} CC="${CC}" FREEBSDCC="${CC}" CFLAGS="${CFLAGS}" PERL="${PERL}" \
	./config --prefix=${PREFIX}/openssl-unsafe --openssldir=${OPENSSLDIR} \
		--install_prefix=${STAGEDIR} \
		-L${PREFIX}/openssl-unsafe/lib ${CONFIGURE_ARGS}

post-configure:
	${REINPLACE_CMD} \
		-e 's|^MANDIR=.*$$|MANDIR=$$(PREFIX)/man|' \
		-e 's|$$(LIBDIR)/pkgconfig|libdata/pkgconfig|g' \
		-e 's|LIBVERSION=[^ ]* |LIBVERSION=${OPENSSL_SHLIBVER} |' \
		${WRKSRC}/Makefile

test: build
	cd ${WRKSRC} && ${MAKE} test

.include <bsd.port.mk>
