PORTNAME=	inotify-tools
DISTVERSION=	4.26.270
CATEGORIES=	sysutils

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Utilities to monitor and react to filesystem events in real-time
WWW=		https://github.com/inotify-tools/inotify-tools/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

# FreeBSD >= 15 has a native inotify implementation in libc.  Older releases
# need the user-space libinotify-kqueue port.  The upstream build.rs checks
# for /usr/include/sys/inotify.h and links libinotify when it is absent.
.if !exists(/usr/include/sys/inotify.h)
LIB_DEPENDS=	libinotify.so:devel/libinotify
.endif

TEST_DEPENDS=	bash:shells/bash

USES=		cargo gmake
USE_GITHUB=	yes
USE_LDCONFIG=	yes

CARGO_CRATES=	libc-0.2.183

.if !exists(/usr/include/sys/inotify.h)
CARGO_ENV+=	INOTIFYTOOLS_LINK_INOTIFY=1
.endif

post-extract:
	@${ECHO_CMD} ${DISTVERSION} > ${WRKSRC}/VERSION

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${CARGO_ENV} ${GMAKE} all \
		CARGO="${CARGO}" \
		SHELL_PATH="${LOCALBASE}/bin/bash"

do-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${CARGO_ENV} ${GMAKE} install-strip \
		CARGO="${CARGO}" \
		DESTDIR="${STAGEDIR}" \
		prefix="${PREFIX}"

post-install:
	# delete fsnotify* commands because they are Linux-specific: they depend on Linux's fanotify interface
	@${FIND} ${STAGEDIR}${PREFIX} -name "fsnotify*" -delete

do-test:
	@${ECHO} "====> Unit tests"
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${CARGO_ENV} ${GMAKE} unit-test \
		CARGO="${CARGO}"

# Integration tests are intentionally not run on FreeBSD.  They exercise
# Linux-specific fanotify commands (already removed by post-install) and rely
# on Linux event semantics (e.g. MOVED_TO) and utilities behaviour (realpath on
# missing files, chown to the current owner) that do not hold on FreeBSD.
# The unit-test target provides 480076 cross-platform tests.

# tests as of 4.26.270:
# Unit tests: Out of 480076 tests, 480076 succeeded and 0 failed.

.include <bsd.port.mk>
