# Created by: Ade Lovett <ade@FreeBSD.org>

PORTNAME=	libxslt
DISTVERSION=	1.1.35
CATEGORIES=	textproc gnome
MASTER_SITES=	GNOME/sources/${PORTNAME}/${DISTVERSION:R}/
DIST_SUBDIR=	gnome2

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	XML stylesheet transformation library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgcrypt.so:security/libgcrypt \
		libgpg-error.so:security/libgpg-error

USES=		cmake cpe gnome localbase:ldflags pathfix pkgconfig tar:xz
CPE_VENDOR=	xmlsoft
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

CMAKE_OFF=	LIBXSLT_WITH_PYTHON
CMAKE_ON=	LIBXSLT_WITH_CRYPTO

OPTIONS_DEFINE=	DOCS DEBUG MEM_DEBUG TEST
OPTIONS_SUB=	yes

MEM_DEBUG_DESC=	Enable memory debugging

DEBUG_CMAKE_BOOL=	LIBXSLT_WITH_XSLT_DEBUG
DOCS_EXTRA_PATCHES_OFF=	${PATCHDIR}/extra-patch-docs
MEM_DEBUG_CMAKE_BOOL=	LIBXSLT_WITH_MEM_DEBUG
TEST_CMAKE_BOOL=	LIBXSLT_WITH_TESTS
TEST_TEST_TARGET=	test

post-install:
	${RLN} ${STAGEDIR}${PREFIX}/lib/libexslt.so.0.8.20 ${STAGEDIR}${PREFIX}/lib/libexslt.so.0
	${RLN} ${STAGEDIR}${PREFIX}/lib/libxslt.so.${DISTVERSION} ${STAGEDIR}${PREFIX}/lib/libxslt.so.1
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/libxslt-plugins
	${INSTALL_DATA} ${WRKSRC}/libxslt.m4 ${STAGEDIR}${PREFIX}/share/aclocal/libxslt.m4

.include <bsd.port.mk>
