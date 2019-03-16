# Created by: Dima Panov <fluffy@Fluffy.Khv.RU>
# $FreeBSD$

PORTNAME=	polkit-qt
DISTVERSIONPREFIX=	1-
DISTVERSION=	0.112.0
PORTREVISION=	6
CATEGORIES=	sysutils
MASTER_SITES=	KDE/stable/apps/KDE4.x/admin/
PKGNAMESUFFIX=	5

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt5 wrapper around Polkit libraries

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpolkit-agent-1.so:sysutils/polkit

USES=		cmake compiler:c++11-lang gnome pkgconfig qt:5 tar:bzip2
USE_GNOME=	glib20
USE_QT=		core dbus gui widgets buildtools_build qmake_build
CMAKE_OFF=	BUILD_EXAMPLES  \
		BUILD_TEST \
		USE_QT4
CMAKE_ON=	USE_QT5
QTVER_SUFFIX=	5

USE_LDCONFIG=	yes

PLIST_SUB=	QTVER_SUFFIX="${QTVER_SUFFIX}"

post-patch:
	${REINPLACE_CMD} -e 's|$${LIB_DESTINATION}/pkgconfig|libdata/pkgconfig|' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
