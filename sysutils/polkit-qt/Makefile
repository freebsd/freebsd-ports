# Created by: Dima Panov <fluffy@Fluffy.Khv.RU>
# $FreeBSD$

PORTNAME=	polkit-qt
PORTVERSION=	0.112.0
DISTVERSIONPREFIX=	1-
CATEGORIES=	sysutils
MASTER_SITES=	KDE/stable/apps/KDE4.x/admin/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt wrapper around Polkit libraries

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpolkit-agent-1.so:sysutils/polkit

CMAKE_ARGS=	-DBUILD_EXAMPLES:BOOL=OFF \
		-DBUILD_TEST:BOOL=OFF \
		-DUSE_QT4:BOOL=ON

USES=		cmake:outsource kde:4 pkgconfig tar:bzip2
USE_GNOME=	glib20
USE_KDE=	automoc4
USE_QT4=	corelib dbus gui \
		qmake_build moc_build rcc_build uic_build
USE_LDCONFIG=	yes

post-patch:
	${REINPLACE_CMD} -e 's|$${LIB_DESTINATION}/pkgconfig|libdata/pkgconfig|' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
