# New ports collection Makefile for:	kdeadmin
# Date created:				2008-01-30
# Whom:					Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	kdeadmin
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	sysutils kde ipv6
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE Admin applications

RUN_DEPENDS=	${LOCALBASE}/share/icons/hicolor/index.theme:${PORTSDIR}/misc/hicolor-icon-theme

LATEST_LINK=	${PORTNAME}4

USE_BZIP2=	yes
USE_QT_VER=	4
USE_KDE4=	kdelibs pimlibs kdeprefix kdehier automoc4
KDE4_BUILDENV=	yes
USE_OPENSSL=	yes
QT_COMPONENTS=	corelib opengl moc rcc dbus qt3support designer network svg qtestlib \
		network uic3 porting
#USE_OPENLDAP=	yes

# dirty hack should fix in upstream?
LDFLAGS=	-lcrypt

CMAKE_ARGS+=	-DBUILD_kpackage:BOOL=Off \
		-DBUILD_lilo-config:BOOL=Off

post-patch:
	${MKDIR} ${WRKSRC}
	${REINPLACE_CMD} -e \
	's,$${LIB_INSTALL_DIR}/pkgconfig,libdata/pkgconfig,' \
	${WRKSRC}/../knetworkconf/backends/CMakeLists.txt

.include <bsd.port.mk>
