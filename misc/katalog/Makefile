# New ports collection makefile for:	katalog
# Date created:				15 May 2003
# Whom:					Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	katalog
PORTVERSION=	0.4
PORTREVISION=	7
CATEGORIES=	misc kde
MASTER_SITES=	http://salvaste.altervista.org/files/

PATCH_SITES=	http://www.realtime.sk/~stromek/kde/katalog/
PATCHFILES=	katalog.cmake.diff
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	CD organizer for KDE

USE_KDEBASE_VER=	3
USE_SQLITE=	yes
USE_CMAKE=	yes
CMAKE_USE_PTHREAD=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local/|${LOCALBASE}/|g' \
		${WRKSRC}/cmake/modules/FindSQLite3.cmake
	@${REINPLACE_CMD} -e 's|$${LIB_INSTALL_DIR}/qt3/|lib/|g' \
		${WRKSRC}/libqsqlite3/CMakeLists.txt
	@${ECHO_CMD} 'macro_add_compile_flags( katalog "-fPIC" )' \
		>> ${WRKSRC}/libkatalog/CMakeLists.txt
	@${ECHO_CMD} 'macro_add_compile_flags( katalogxml "-fPIC" )' \
		>> ${WRKSRC}/xml_backend/libkatalogxml/CMakeLists.txt

.include <bsd.port.mk>
