# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	botan
PORTVERSION=	1.10.13
PORTREVISION=	6
CATEGORIES=	security
MASTER_SITES=	http://botan.randombit.net/releases/
PKGNAMESUFFIX=	110
DISTNAME=	Botan-${PORTVERSION}

MAINTAINER=	lapo@lapo.it
COMMENT=	Portable, easy to use, and efficient C++ crypto library

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/doc/license.txt

OPTIONS_DEFINE=		SSL GMP DOCS
OPTIONS_DEFAULT=	SSL GMP

USES=		compiler gmake python:build tar:tgz
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	configure.py
CONFIGURE_ARGS=	--prefix=${PREFIX} --cc ${CHOSEN_COMPILER_TYPE} \
		--with-tr1-implementation=system --with-bzip2 --with-zlib
MAKE_ARGS=	CXX="${CXX}" LIB_OPT="${CXXFLAGS}"
USE_LDCONFIG=	yes
PLIST_FILES=	bin/botan-config-1.10 lib/libbotan-1.10.a lib/libbotan-1.10.so lib/libbotan-1.10.so.1 \
		lib/libbotan-1.10.so.1.13 libdata/pkgconfig/botan-1.10.pc

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${PORTVERSION}
PORTDOCS=	*

BROKEN_aarch64=		Fails to configure: unknown or unidentifiable processor arm64

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSSL}
USES+=		ssl
CONFIGURE_ARGS+=--with-openssl
.endif

.if ${PORT_OPTIONS:MGMP}
USES+=		localbase:ldflags
LIB_DEPENDS+=	libgmp.so:math/gmp
CONFIGURE_ARGS+=--with-gnump
.endif

.include <bsd.port.pre.mk>

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
