# $FreeBSD$

PORTNAME=	botan
DISTVERSION=	2.12.0
CATEGORIES=	security
MASTER_SITES=	http://botan.randombit.net/releases/
PKGNAMESUFFIX=	2
DISTNAME=	Botan-${PORTVERSION}

MAINTAINER=	tremere@cainites.net
COMMENT=	Portable, easy to use and efficient C++ crypto library

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/license.txt

BROKEN_armv6=	include/arm_neon.h:28:2: error: "NEON support not enabled"

LIB_DEPENDS=	libboost_filesystem.so:devel/boost-libs

USES=		compiler:c++11-lang gmake python:build shebangfix tar:xz
USE_LDCONFIG=	yes

SHEBANG_FILES=	configure.py src/scripts/install.py

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	configure.py
CONFIGURE_ARGS=		--cc=${COMPILER_TYPE} \
			--with-boost \
			--with-bzip2 \
			--with-external-includedir=${LOCALBASE}/include \
			--with-external-libdir=${LOCALBASE}/lib \
			--with-lzma \
			--with-zlib
LDFLAGS+=		-pthread

DOCSDIR=	${LOCALBASE}/share/doc/${PORTNAME}-${PORTVERSION}

_SHLIBVER=	${DISTVERSION:S/./ /g:[2]}
PLIST_SUB=	SHLIBVER=${_SHLIBVER}
PORTDOCS=	*

OPTIONS_DEFINE=		DOCS SQLITE3 SSL
OPTIONS_DEFAULT=	SSL
OPTIONS_SUB=		yes

SQLITE3_USES=		sqlite
SQLITE3_CONFIGURE_WITH=	sqlite3

SSL_USES=		ssl
SSL_CONFIGURE_WITH=	openssl

.include <bsd.port.options.mk>

.if ${ARCH} == aarch64
CONFIGURE_ARGS+=	--cc-abi="-march=armv8-a+crypto"
.elif ${ARCH} == powerpc64
CONFIGURE_ARGS+=	--cpu="ppc64"
.endif

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1200000
CONFIGURE_ARGS+=	--without-os-features=getentropy,elf_aux_info
.endif

.if ${ARCH} == i386 || ${ARCH} == amd64
PLIST_SUB+=	HAS_RDRAND_RNG=""
.else
PLIST_SUB+=	HAS_RDRAND_RNG="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|^optimization_flags .*|optimization_flags "${CXXFLAGS}"|' \
		${WRKSRC}/src/build-data/cc/clang.txt

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/botan ${STAGEDIR}${PREFIX}/lib/libbotan-2.so.${_SHLIBVER}.${_SHLIBVER}.0

.include <bsd.port.mk>
