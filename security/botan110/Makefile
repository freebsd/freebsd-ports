# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	botan
DISTVERSION=	1.10.17
PORTREVISION=	1
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

USES=		compiler gmake python:build shebangfix tar:tgz
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	configure.py
CONFIGURE_ARGS=	--prefix=${PREFIX} --cc ${CHOSEN_COMPILER_TYPE} \
		--with-tr1-implementation=system --with-bzip2 --with-zlib
MAKE_ARGS=	CXX="${CXX}" CHECK_OPT="${CXXFLAGS}" LIB_OPT="${CXXFLAGS}"
USE_LDCONFIG=	yes
PLIST_FILES=	bin/botan-config-1.10 lib/libbotan-1.10.a lib/libbotan-1.10.so lib/libbotan-1.10.so.1 \
		lib/libbotan-1.10.so.1.17 libdata/pkgconfig/botan-1.10.pc
SHEBANG_FILES=	configure.py
TEST_TARGET=	check

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${PORTVERSION}
PORTDOCS=	*

SSL_USES=		ssl
SSL_CONFIGURE_WITH=	openssl

GMP_USES=		localbase:ldflags
GMP_LIB_DEPENDS=	libgmp.so:math/gmp
GMP_CONFIGURE_WITH=	gnump

.include <bsd.port.pre.mk>

.if (${OPSYS} == FreeBSD && ${OSVERSION} > 1200084) || ${SSL_DEFAULT:Mopenssl} || ${SSL_DEFAULT:M*-devel}
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-openssl11
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|#!/usr/bin/env python|#!${PYTHON_CMD}|" \
		${WRKSRC}/configure.py

post-patch-DOCS-off:
	@${REINPLACE_CMD} -e '/DOCDIR/d' \
		${WRKSRC}/src/build-data/makefile/unix_shr.in

post-install:
	@(cd "${STAGEDIR}${PREFIX}"; ${FIND} -s include/botan-1.10 -not -type d) >> ${TMPPLIST}

post-test:
	cd ${WRKSRC} && ${SETENV} LD_LIBRARY_PATH="." ./check --test

.include <bsd.port.post.mk>
