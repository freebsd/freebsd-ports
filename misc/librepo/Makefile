PORTNAME=	librepo
DISTVERSION=	1.14.1
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library downloading repository metadata

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libassuan.so:security/libassuan \
		libcurl.so:ftp/curl \
		libgpg-error.so:security/libgpg-error \
		libgpgme.so:security/gpgme

USES=		gettext-runtime gnome cmake localbase:ldflags pkgconfig
USE_GNOME=	glib20 libxml2
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	rpm-software-management

CMAKE_OFF=	ENABLE_DOCS ENABLE_TESTS

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
