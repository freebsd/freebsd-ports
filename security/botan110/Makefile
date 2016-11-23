# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	botan
PORTVERSION=	1.10.13
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://botan.randombit.net/releases/
PKGNAMESUFFIX=	110
DISTNAME=	Botan-${PORTVERSION}

MAINTAINER=	lapo@lapo.it
COMMENT=	Portable, easy to use, and efficient C++ crypto library

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/doc/license.txt

OPTIONS_DEFINE=		SSL GMP ECC DOCS
OPTIONS_DEFAULT=	SSL GMP ECC
ECC_DESC=	ECC support

USES=		compiler gmake python:build tar:tgz
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	configure.py
CONFIGURE_ARGS=	--prefix=${PREFIX} --with-bzip2 --with-zlib
MAKE_ARGS=	CXX="${CXX}" LIB_OPT="${CXXFLAGS}"
USE_LDCONFIG=	yes
PLIST_FILES=	bin/botan-config-1.10 lib/libbotan-1.10.a lib/libbotan-1.10.so lib/libbotan-1.10.so.1 \
		lib/libbotan-1.10.so.1.13 libdata/pkgconfig/botan-1.10.pc

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${PORTVERSION}
PORTDOCS=	*

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSSL}
USE_OPENSSL=	yes
CONFIGURE_ARGS+=--with-openssl
.endif

.if ${PORT_OPTIONS:MGMP}
LIB_DEPENDS+=	libgmp.so:math/gmp
CONFIGURE_ARGS+=--with-gnump
MAKE_ARGS+=	LDFLAGS="-L${LOCALBASE}/lib"
.endif

.if ${PORT_OPTIONS:MECC}
BUILD_DEPENDS+=	${LOCALBASE}/include/boost/tr1/memory.hpp:devel/boost-libs
CONFIGURE_ARGS+=--with-tr1-implementation=boost
CXXFLAGS+=	-I${LOCALBASE}/include
.else
CONFIGURE_ARGS+=--with-tr1-implementation=none
.endif

.include <bsd.port.pre.mk>

CONFIGURE_ARGS+=--cc ${COMPILER_TYPE}

post-patch:
	${REINPLACE_CMD} -e "s|#!/usr/bin/env python|#!${PYTHON_CMD}|" \
			${WRKSRC}/configure.py
.if ! ${PORT_OPTIONS:MDOCS}
	${REINPLACE_CMD} -e '/DOCDIR/d' \
			${WRKSRC}/src/build-data/makefile/unix_shr.in
.endif

post-install:
	@(cd "${STAGEDIR}${PREFIX}"; ${FIND} -s include/botan-1.10 -not -type d) >> ${TMPPLIST}

.include <bsd.port.post.mk>
