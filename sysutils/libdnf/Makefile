PORTNAME=	libdnf
DISTVERSION=	0.70.2
PORTREVISION=	2
CATEGORIES=	sysutils

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Dandified YUM, the next-generation version of YUM
WWW=		https://github.com/rpm-software-management/libdnf

LICENSE=	LGPL21 # no LICENSE tag for Version 2.1
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	check>0:devel/check
LIB_DEPENDS=	libassuan.so:security/libassuan \
		libcurl.so:ftp/curl \
		libexpat.so:textproc/expat2 \
		libffi.so:devel/libffi \
		libgcrypt.so:security/libgcrypt \
		libgpgme.so:security/gpgme \
		libgpg-error.so:security/libgpg-error \
		libidn2.so:dns/libidn2 \
		libjson-c.so:devel/json-c \
		libmodulemd.so:misc/libmodulemd \
		libnghttp2.so:www/libnghttp2 \
		libpsl.so:dns/libpsl \
		libpcre.so:devel/pcre \
		libpopt.so:devel/popt \
		librepo.so:misc/librepo \
		librpmio.so:archivers/rpm4 \
		libsmartcols.so:devel/util-linux \
		libsolv.so:misc/libsolv \
		libssh2.so:security/libssh2 \
		libunistring.so:devel/libunistring \
		libyaml.so:textproc/libyaml \
		libzstd.so:archivers/zstd
TEST_DEPENDS=	cppunit>0:devel/cppunit

USES=		cmake:testing compiler:c++11-lang gettext gnome lua pkgconfig sqlite ssl
USE_GNOME=	glib20 libxml2
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	rpm-software-management

CMAKE_OFF=	BUILD_TESTNG WITH_GTKDOC WITH_HTML WITH_TESTS FREEBSD_INSTALL_DOCS
CMAKE_TESTING_ON=	BUILD_TESTNG WITH_TESTS # tests throw exceptions, see https://github.com/rpm-software-management/libdnf/issues/1581

BINARY_ALIAS=	git=false

OPTIONS_DEFINE=		PYTHON ZCHUNK
OPTIONS_DEFAULT=	PYTHON
OPTIONS_SUB=		yes

PYTHON_CMAKE_BOOL=	WITH_BINDINGS
PYTHON_USES=		python
PYTHON_CMAKE_ON=	-DPYTHON_DESIRED=${PYTHON_MAJOR_VER}
PYTHON_BUILD_DEPENDS=	swig:devel/swig \
			${PYTHON_PKGNAMEPREFIX}sphinx>0:textproc/py-sphinx@${PY_FLAVOR}

ZCHUNK_DESC=		With zchunk support
ZCHUNK_CMAKE_BOOL=	WITH_ZCHUNK
ZCHUNK_BROKEN=		Links with zchunk when WITH_ZCHUNK=OFF https://github.com/rpm-software-management/libdnf/issues/1515

# Tests fail to compile: ld: error: unable to find library -ltestshared, see https://github.com/rpm-software-management/libdnf/issues/1574

.include <bsd.port.mk>
