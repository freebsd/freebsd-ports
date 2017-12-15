# $FreeBSD$

PORTNAME=	botan
DISTVERSION=	2.3.0
CATEGORIES=	security
MASTER_SITES=	http://botan.randombit.net/releases/
PKGNAMESUFFIX=	2
DISTNAME=	Botan-${PORTVERSION}

MAINTAINER=	tremere@cainites.net
COMMENT=	Portable, easy to use and efficient C++ crypto library

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/license.txt

LIB_DEPENDS=	libboost_filesystem.so:devel/boost-libs

OPTIONS_DEFINE=		SQLITE3 SSL DOCS
OPTIONS_DEFAULT=	SSL
OPTIONS_SUB=		yes

USES=		compiler:c++11-lang gmake python:build shebangfix tar:tgz
HAS_CONFIGURE=	yes
USE_LDCONFIG=	yes

CONFIGURE_SCRIPT=	configure.py
CONFIGURE_ARGS=	--with-external-includedir=${PREFIX}/include \
		--with-external-libdir=${PREFIX}/lib \
		--with-boost --with-bzip2 --with-lzma --with-zlib
LDFLAGS+=	-pthread
SHEBANG_FILES=	configure.py src/scripts/install.py

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${PORTVERSION}
PORTDOCS=	*

SQLITE3_USES=		sqlite
SQLITE3_CONFIGURE_WITH=	sqlite3

SSL_USES=		ssl
SSL_CONFIGURE_WITH=	openssl
SSL_VARS=		BROKEN_SSL=	openssl-devel

post-patch:
	@${REINPLACE_CMD} -e 's|^optimization_flags .*|optimization_flags "${CXXFLAGS}"|' \
		${WRKSRC}/src/build-data/cc/clang.txt

post-stage:
.for i in bin/botan lib/libbotan-2.so.3.3.0
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/${i}
.endfor

.include <bsd.port.mk>
