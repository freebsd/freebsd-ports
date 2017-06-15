# Created by: Dima Panov <fluffy@Fluffy.Khv.RU>
# $FreeBSD$

PORTNAME=	polkit-qt
PORTVERSION=	0.112.0
DISTVERSIONPREFIX=	1-
CATEGORIES=	sysutils
MASTER_SITES=	KDE/stable/apps/KDE4.x/admin/

MAINTAINER=	kde@FreeBSD.org
COMMENT?=	Qt4 wrapper around Polkit libraries

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpolkit-agent-1.so:sysutils/polkit

USES=		cmake:outsource pkgconfig tar:bzip2
USE_GNOME=	glib20
CMAKE_ARGS=	-DBUILD_EXAMPLES:BOOL=OFF \
		-DBUILD_TEST:BOOL=OFF


.if empty(PKGNAMESUFFIX)
USES+=		kde:4
USE_KDE=	automoc4
USE_QT4=	corelib dbus gui \
		qmake_build moc_build rcc_build uic_build
CMAKE_ARGS+=	-DUSE_QT4:BOOL=ON \
		-DUSE_QT5:BOOL=OFF
.else
USE_QT5=	core dbus gui widgets buildtools_build qmake_build
CMAKE_ARGS+=	-DUSE_QT4:BOOL=OFF \
		-DUSE_QT5:BOOL=ON
.endif

USE_LDCONFIG=	yes

PLIST_SUB=	QTVER_SUFFIX="${PKGNAMESUFFIX}"

post-patch:
	${REINPLACE_CMD} -e 's|$${LIB_DESTINATION}/pkgconfig|libdata/pkgconfig|' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
