# New ports collection Makefile for:	kdeadmin
# Date created:				2008-01-30
# Whom:					Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	kdeadmin
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	sysutils kde ipv6
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE Admin applications

LATEST_LINK=	${PORTNAME}4

USE_BZIP2=	yes
USE_QT_VER=	4
USE_KDE4=	kdelibs pimlibs kdeprefix kdehier automoc4
KDE4_BUILDENV=	yes
USE_OPENSSL=	yes
QT_COMPONENTS=	corelib opengl dbus qt3support designer network svg qtestlib \
		network porting_build qmake_build moc_build rcc_build \
		uic_build uic3_build
MAKE_JOBS_UNSAFE=	yes

PATCH_WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}

CMAKE_ARGS+=	-DBUILD_kpackage:BOOL=Off \
		-DBUILD_lilo-config:BOOL=Off

post-extract:
	${MKDIR} ${WRKSRC}

post-patch:
	${REINPLACE_CMD} -e \
	's,$${LIB_INSTALL_DIR}/pkgconfig,libdata/pkgconfig,' \
	${PATCH_WRKSRC}/knetworkconf/backends/CMakeLists.txt
#disable documentation for kpackage
	${REINPLACE_CMD} -e '/add_subdirectory(kpackage)/d' \
		${PATCH_WRKSRC}/doc/CMakeLists.txt
#disable system-config-printer-kde, it comes with print/kdeadmin4-system-config-printer-kde
	${REINPLACE_CMD} -e '/add_subdirectory.*system-config-printer-kde/d' \
		${WRKSRC}/../CMakeLists.txt
.include <bsd.port.mk>
