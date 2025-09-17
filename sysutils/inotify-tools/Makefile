PORTNAME=	inotify-tools
DISTVERSION=	4.25.9.0
CATEGORIES=	sysutils

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Command-line utilities to watch for file events
WWW=		https://github.com/inotify-tools/inotify-tools/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libinotify.so:devel/libinotify
TEST_DEPENDS=	bash:shells/bash

USES=		autoreconf compiler:c11 gmake libtool localbase shebangfix
USE_GITHUB=	yes
USE_LDCONFIG=	yes

SHEBANG_GLOB=	*.t *.sh

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-doxygen

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	STATIC
OPTIONS_SUB=	yes

post-patch:
	@${REINPLACE_CMD} \
		-e 's|SHELL_PATH ?= /bin/bash|SHELL_PATH ?= ${LOCALBASE}/bin/bash|' \
		${WRKSRC}/t/Makefile

post-build-STATIC-on:
	@cd ${WRKSRC}/src && \
		${CC} -pthread ${LDFLAGS} -static -o inotifywait.static inotifywait.o common.o ../libinotifytools/src/.libs/libinotifytools.a ${LOCALBASE}/lib/libinotify.a && \
		${CC} -pthread ${LDFLAGS} -static -o inotifywatch.static inotifywatch.o common.o ../libinotifytools/src/.libs/libinotifytools.a ${LOCALBASE}/lib/libinotify.a

post-install-STATIC-on:
	${INSTALL_PROGRAM} ${WRKSRC}/src/inotifywait.static ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/inotifywatch.static ${STAGEDIR}${PREFIX}/bin

do-test: # Some tests are known to fail: https://github.com/inotify-tools/inotify-tools/issues/108
	@${ECHO} "unit test"
	@cd ${WRKSRC}/libinotifytools/src && ${GMAKE} test && ./test
	@${ECHO} "integration test"
	@cd ${WRKSRC}/t && ${GMAKE}

.include <bsd.port.mk>
