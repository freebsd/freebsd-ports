# Created by: Dima Panov <fluffy@Fluffy.Khv.RU>
# $FreeBSD$

PORTNAME=	polkit-qt-1
DISTVERSION=	0.113.0
PORTREVISION=	8
CATEGORIES=	sysutils
MASTER_SITES=	KDE/stable/${PORTNAME}/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt5 wrapper around Polkit libraries

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpolkit-agent-1.so:sysutils/polkit

USES=		cmake compiler:c++11-lang gnome pkgconfig qt:5 tar:xz
USE_GNOME=	glib20
USE_QT=		core dbus gui widgets buildtools_build qmake_build
CMAKE_OFF=	BUILD_EXAMPLES  \
		BUILD_TEST

USE_LDCONFIG=	yes

post-patch:
	${REINPLACE_CMD} -e 's|$${LIB_DESTINATION}/pkgconfig|libdata/pkgconfig|' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
