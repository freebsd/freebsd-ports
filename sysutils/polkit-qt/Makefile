# Created by: Dima Panov <fluffy@Fluffy.Khv.RU>
# $FreeBSD$

PORTNAME=	polkit-qt
PORTVERSION=	0.103.0
PORTREVISION=	1
DISTVERSIONPREFIX=	1-
CATEGORIES=	sysutils
MASTER_SITES=	KDE/stable/apps/KDE4.x/admin/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt 4 frontend to PolKit-1

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpolkit-agent-1.so:${PORTSDIR}/sysutils/polkit

USE_LDCONFIG=	yes
USE_KDE4=	automoc4
USE_QT4=	corelib dbus gui network svg xml  \
		qmake_build moc_build rcc_build uic_build
USES=		cmake gettext tar:bzip2
# TODO: the next release (post-0.103.0) should have commit 56883bd, which
#       syncs FindGObject.cmake with kdelibs' and should find GObject without
#       requiring us to explicitly set LDFLAGS.
LDFLAGS+=	-L${LOCALBASE}/lib

post-extract:
	${REINPLACE_CMD} -e 's|$${LIB_INSTALL_DIR}/pkgconfig|libdata/pkgconfig|' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
