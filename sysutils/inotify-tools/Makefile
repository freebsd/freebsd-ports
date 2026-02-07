PORTNAME=	inotify-tools
DISTVERSION=	4.25.9.0
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Utilities to monitor and react to filesystem events in real-time
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

post-install:
	# delete fsnotify* commands because they are Linux-specific: they depend on Linux's fanotify interface
	@${FIND} ${STAGEDIR}${PREFIX} -name "fsnotify*" -delete

post-install-STATIC-on:
	${INSTALL_PROGRAM} ${WRKSRC}/src/inotifywait.static ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/inotifywatch.static ${STAGEDIR}${PREFIX}/bin

do-test: # Some tests are known to fail: https://github.com/inotify-tools/inotify-tools/issues/108
	@${ECHO} "====> Unit tests"
	@cd ${WRKSRC}/libinotifytools/src && ${GMAKE} test && ./test
	@${ECHO} "====> Integration tests"
	@cd ${WRKSRC}/t && ${GMAKE}

# tests as of 4.25.9.0:
# Unit tests: Out of 480076 tests, 480076 succeeded and 0 failed. (1-4 tests may fail due to "Too many open files", adjusting kern.maxfiles helps)
# Integration tests: some tests fail due to unreported MOVED_TO events, see https://github.com/inotify-tools/inotify-tools/issues/238

.include <bsd.port.mk>
