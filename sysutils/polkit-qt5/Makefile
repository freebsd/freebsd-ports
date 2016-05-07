# $FreeBSD$

PORTNAME=	polkit-qt5
DISTNAME=	polkit-qt-1-${PORTVERSION}
PORTVERSION=	0.112.0
CATEGORIES=	sysutils
MASTER_SITES=	KDE/stable/apps/KDE4.x/admin/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt5 wrapper around Polkit libraries

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpolkit-agent-1.so:sysutils/polkit

CMAKE_ARGS=	-DBUILD_EXAMPLES:BOOL=OFF \
		-DBUILD_TEST:BOOL=OFF \
		-DUSE_QT4:BOOL=OFF \
		-DUSE_QT5:BOOL=ON

USE_GNOME=	glib20
USE_QT5=	core dbus gui widgets buildtools_build qmake_build
USES=		cmake:outsource tar:bzip2
USE_LDCONFIG=	yes

post-patch:
	${REINPLACE_CMD} -e 's|$${LIB_DESTINATION}/pkgconfig|libdata/pkgconfig|' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
