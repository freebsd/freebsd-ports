PORTNAME=	librepo
DISTVERSION=	1.19.0
PORTREVISION=	2
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library downloading repository metadata
WWW=		https://github.com/rpm-software-management/librepo

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libassuan.so:security/libassuan \
		libcurl.so:ftp/curl \
		libgpg-error.so:security/libgpg-error \
		libgpgme.so:security/gpgme
TEST_DEPENDS=	bash:shells/bash \
		check>0:devel/check \
		${PYTHON_PKGNAMEPREFIX}gpg>=2.0.0:security/py-gpg@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xattr>0:devel/py-xattr@${PY_FLAVOR}

USES=		cpe gettext-runtime gnome cmake:testing localbase:ldflags pkgconfig python shebangfix ssl
CPE_VENDOR=	redhat
USE_GNOME=	glib20 libxml2
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	rpm-software-management

SHEBANG_FILES=	tests/run_tests.sh.in
SHEBANG_GLOB=	*.sh

CFLAGS+=	-I${WRKSRC}/librepo

CMAKE_ARGS=	-DFREEBSD_PYTHON_VERSION=${PYTHON_VER}
CMAKE_OFF=	ENABLE_DOCS ENABLE_TESTS \
		ENABLE_SELINUX
CMAKE_TESTING_ON=	ENABLE_TESTS

OPTIONS_DEFINE=		PYTHON ZCHUNK
OPTIONS_DEFAULT=	ZCHUNK
OPTIONS_SUB=		yes

PYTHON_USES=		python
PYTHON_CMAKE_BOOL=	ENABLE_PYTHON
PYTHON_CMAKE_ON=	-DPYTHON_DESIRED=${PYTHON_MAJOR_VER}

ZCHUNK_DESC=		Build with zchunk support
ZCHUNK_CMAKE_BOOL=	WITH_ZCHUNK
ZCHUNK_LIB_DEPENDS=	libzck.so:archivers/zchunk

post-patch:
	@${RLN} ${FILESDIR}/xattr.c ${WRKSRC}/librepo/xattr.c
	@${RLN} ${FILESDIR}/xattr.h ${WRKSRC}/librepo/xattr.h

.include <bsd.port.mk>
