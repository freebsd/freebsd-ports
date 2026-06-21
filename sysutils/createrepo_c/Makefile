PORTNAME=	createrepo_c
DISTVERSION=	1.2.4
CATEGORIES=	sysutils

MAINTAINER=	ktk@netlabs.org
COMMENT=	C implementation of createrepo
WWW=		http://rpm-software-management.github.io/createrepo_c/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	librpm.so:archivers/rpm4 \
		libcurl.so:ftp/curl \
		libmodulemd.so:misc/libmodulemd \
		libpopt.so:devel/popt \
		libzck.so:archivers/zchunk \
		libzstd.so:archivers/zstd
TEST_DEPENDS=	bash:shells/bash

USES=		cmake:testing gnome pathfix pkgconfig shebangfix sqlite ssl
USE_GITHUB=	yes
GH_ACCOUNT=	rpm-software-management
USE_GNOME=	glib20 libxml2
USE_LDCONFIG=	yes

SHEBANG_FILES=	tests/run_tests.sh.in

CMAKE_ON=	CMAKE_DISABLE_FIND_PACKAGE_Doxygen
CMAKE_OFF=	BUILD_DOC_C ENABLE_PYTHON

.include <bsd.port.mk>
