PORTNAME=	trealla-prolog
DISTVERSIONPREFIX=	v
DISTVERSION=	2.68.20
CATEGORIES=	lang

MAINTAINER=	siva@FreeBSD.org
COMMENT=	Compact, efficient Prolog interpreter written in plain-old C
WWW=		https://github.com/trealla-prolog/trealla/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake

BUILD_DEPENDS=	xxd:sysutils/xxd

PLIST_FILES=	bin/tpl

TEST_TARGET=	test

OPTIONS_DEFINE=		FFI READLINE SSL THREADS
OPTIONS_DEFAULT=	FFI READLINE SSL THREADS

FFI_DESC=	FFI support
READLINE_DESC=	GNU readline support
SSL_DESC=	SSL support
THREADS_DESC=	Preemptive multithreading support

FFI_LIB_DEPENDS=	libffi.so:devel/libffi
FFI_MAKE_ARGS_OFF=	NOFFI=1

READLINE_USES=		readline
READLINE_MAKE_ARGS_OFF=	ISOCLINE=1

SSL_USES=		ssl
SSL_MAKE_ARGS_OFF=	NOSSL=1

THREADS_MAKE_ARGS_OFF=	NOTHREADS=1

USE_GITHUB=	yes
GH_PROJECT=	trealla

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tpl ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
