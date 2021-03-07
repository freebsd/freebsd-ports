# $FreeBSD$

PORTNAME=	libdnf
DISTVERSION=	0.60.0
CATEGORIES=	sysutils

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Dandified YUM, the next-generation version of YUM

LICENSE=	LGPL21 # no LICENSE tag for Version 2.1
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_FreeBSD_11=	fatal error: sys/auxv.h: No such file or directory

BUILD_DEPENDS=	check>0:devel/check
LIB_DEPENDS=	libassuan.so:security/libassuan \
		libgpgme.so:security/gpgme \
		libgpg-error.so:security/libgpg-error \
		libjson-c.so:devel/json-c \
		libmodulemd.so:misc/libmodulemd \
		librepo.so:misc/librepo \
		librpmio.so:archivers/rpm4 \
		libsmartcols.so:devel/util-linux \
		libsolv.so:misc/libsolv

USES=		cmake compiler:c++11-lang gettext gnome pkgconfig sqlite ssl
USE_GNOME=	glib20
USE_LDCONFIG=	yes
USE_GCC=	any # clang fails: https://github.com/rpm-software-management/libdnf/issues/1038

USE_GITHUB=	yes
GH_ACCOUNT=	rpm-software-management

CMAKE_OFF=	BUILD_TESTNG WITH_GTKDOC WITH_HTML BUILD_TESTING FREEBSD_INSTALL_DOCS

OPTIONS_DEFINE=		PYTHON ZCHUNK
OPTIONS_DEFAULT=	PYTHON
OPTIONS_SUB=		yes

PYTHON_CMAKE_BOOL=	WITH_BINDINGS
PYTHON_USES=		python
PYTHON_CMAKE_ON=	-DPYTHON_DESIRED=${PYTHON_MAJOR_VER}
PYTHON_BUILD_DEPENDS=	swig:devel/swig

ZCHUNK_DESC=		With zchunk support
ZCHUNK_CMAKE_BOOL=	WITH_ZCHUNK
ZCHUNK_BROKEN=		ZCHUNK option is declared, but this library is never actually used

.include <bsd.port.mk>
