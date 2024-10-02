PORTNAME=	createrepo_c
DISTVERSION=	1.1.4
CATEGORIES=	sysutils

MAINTAINER=	ktk@netlabs.org
COMMENT=	C implementation of createrepo
WWW=		http://rpm-software-management.github.io/createrepo_c/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	librpm.so:archivers/rpm4 \
		libcurl.so:ftp/curl \
		libmodulemd.so:misc/libmodulemd \
		libzck.so:archivers/zchunk \
		libzstd.so:archivers/zstd
TEST_DEPENDS=	bash:shells/bash

USES=		cmake pkgconfig shebangfix sqlite

USE_GNOME=	libxml2

USE_GITHUB=	yes
GH_ACCOUNT=	rpm-software-management

CMAKE_OFF=	ENABLE_PYTHON

SHEBANG_FILES=	tests/run_tests.sh.in

USE_LDCONFIG=	yes

post-patch:
	${REINPLACE_CMD} \
		'/pkg_check_modules/s|REQUIRED|REQUIRED IMPORTED_TARGET|' \
		${WRKSRC}/CMakeLists.txt
	for m in GLIB2 GIO GTHREAD2 LIBMODULEMD LZMA SQLITE3 RPM ZCK ZSTD; do \
		${REINPLACE_CMD} \
			"s/\$${$${m}_LIBRARIES}/PkgConfig::$${m}/" \
			${WRKSRC}/src/CMakeLists.txt \
			${WRKSRC}/tests/CMakeLists.txt; \
	done

do-test:
	cd ${CONFIGURE_WRKSRC} && ${MAKE_CMD} tests && ${MAKE_CMD} test

.include <bsd.port.mk>
