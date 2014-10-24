# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	botan
PORTVERSION=	1.10.8
CATEGORIES=	security
MASTER_SITES=	http://files.randombit.net/botan/v1.10/
PKGNAMESUFFIX=	110
DISTNAME=	Botan-${PORTVERSION}
EXTRACT_SUFX=	.tbz

MAINTAINER=	lapo@lapo.it
COMMENT=	Portable, easy to use, and efficient C++ crypto library

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/doc/license.txt

LATEST_LINK=	botan${PKGNAMESUFFIX}

OPTIONS_DEFINE=		SSL GMP ECC DOCS
OPTIONS_DEFAULT=	SSL GMP ECC
ECC_DESC=	ECC support

USES=		compiler gmake python:build tar:bzip2
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	configure.py
CONFIGURE_ARGS=	--prefix=${PREFIX} --with-bzip2 --with-zlib
MAKE_ARGS=	CXX="${CXX}" LIB_OPT="${CXXFLAGS}"
USE_LDCONFIG=	yes
PLIST_FILES=	bin/botan-config-1.10 lib/libbotan-1.10.a lib/libbotan-1.10.so lib/libbotan-1.10.so.0 \
		lib/libbotan-1.10.so.0.8 libdata/pkgconfig/botan-1.10.pc

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${PORTVERSION}
PORTDOCS=	*

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSSL}
USE_OPENSSL=	yes
CONFIGURE_ARGS+=--with-openssl
.endif

.if ${PORT_OPTIONS:MGMP}
LIB_DEPENDS+=	libgmp.so:${PORTSDIR}/math/gmp
CONFIGURE_ARGS+=--with-gnump
MAKE_ARGS+=	LDFLAGS="-L${LOCALBASE}/lib"
.endif

.if ${PORT_OPTIONS:MECC}
BUILD_DEPENDS+=	${LOCALBASE}/include/boost/tr1/memory.hpp:${PORTSDIR}/devel/boost-libs
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
	@${ECHO_CMD} @dirrm include/botan-1.10/botan >> ${TMPPLIST}
	@${ECHO_CMD} @dirrm include/botan-1.10 >> ${TMPPLIST}

.include <bsd.port.post.mk>
