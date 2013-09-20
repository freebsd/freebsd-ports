# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	botan
PORTVERSION=	1.8.13
CATEGORIES=	security
MASTER_SITES=	http://files.randombit.net/botan/v1.8/
DISTNAME=	Botan-${PORTVERSION}
EXTRACT_SUFX=	.tbz

MAINTAINER=	lapo@lapo.it
COMMENT=	Portable, easy to use, and efficient C++ crypto library

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/doc/license.txt

OPTIONS_DEFINE=		SSL GMP ECC
OPTIONS_DEFAULT=	SSL GMP ECC
ECC_DESC=	ECC support

USE_BZIP2=	yes
USE_PYTHON_BUILD=	yes
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	configure.py
CONFIGURE_ARGS=	--prefix=${PREFIX} --with-tr1-implementation=boost \
		--with-bzip2 --with-zlib
USE_GMAKE=	yes
MAKE_ARGS=	CXX="${CXX}" LIB_OPT="${CXXFLAGS}"
USE_LDCONFIG=	yes
PLIST_FILES=	bin/botan-config lib/libbotan.a lib/libbotan.so lib/libbotan.so.0 libdata/pkgconfig/botan-1.8.pc

PORTDOCS=	*

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSSL}
USE_OPENSSL=	yes
CONFIGURE_ARGS+=--with-openssl
.endif

.if ${PORT_OPTIONS:MGMP}
LIB_DEPENDS+=	gmp.10:${PORTSDIR}/math/gmp
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

post-patch:
	${REINPLACE_CMD} -e "s|#!/usr/bin/env python|#!${PYTHON_CMD}|" \
			${WRKSRC}/configure.py
.if ! ${PORT_OPTIONS:MDOCS}
	${REINPLACE_CMD} -e '/$$(MKDIR_INSTALL) $$(DOCDIR)/d' \
			-e '/$$(INSTALL_CMD_DATA) $$$$i $$(DOCDIR); /d' \
			${WRKSRC}/src/build-data/makefile/unix_shr.in
.endif

post-install:
	@(cd ${PREFIX}; ${FIND} -s include/botan -not -type d) >> ${TMPPLIST}
	@${ECHO_CMD} @dirrm include/botan >> ${TMPPLIST}

.include <bsd.port.mk>
