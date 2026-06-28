PORTNAME=	ty
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1
CATEGORIES=	lang

MAINTAINER=	bradgaragan@gmail.com
COMMENT=	Ty programming language
WWW=		https://github.com/marchelzo/ty

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/lib/libffi.a:devel/libffi \
		${LOCALBASE}/lib/libmimalloc.a:devel/mimalloc \
		${LOCALBASE}/lib/libpcre2-8.a:devel/pcre2 \
		${LOCALBASE}/lib/libxxhash.a:devel/xxhash \
		gperf:devel/gperf \
		luajit:lang/luajit \
		ninja:devel/ninja

LIB_DEPENDS=	libutf8proc.so:textproc/utf8proc

RUN_DEPENDS=	terminfo-db>0:misc/terminfo-db

USES=		cmake pkgconfig sqlite

USE_GITHUB=	yes
GH_ACCOUNT=	marchelzo

CMAKE_ARGS=	-DCMAKE_BUILD_TYPE:STRING=Release \
		-DUSE_NSYNC:BOOL=ON \
		-DUSE_SYSTEM_DEPS:BOOL=ON

PLIST_SUB=	TYMODDIR="${TYMODDIR}"

TYMODDIR=	lib/ty

.include <bsd.port.mk>
