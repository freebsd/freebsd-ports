# New ports collection makefile for:	PolKit-kde
# Date created:		2009-12-25
# Whom:			Dima Panov <fluffy@Fluffy.Khv.RU>
#
# $FreeBSD$
#

PORTNAME=	polkit-kde
PORTVERSION=	0.95.1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/apps/KDE4.x/admin/
DISTNAME=	polkit-kde-1-${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE4 frontend to PolKit-1.

LIB_DEPENDS=	polkit-qt-agent-1.0:${PORTSDIR}/sysutils/polkit-qt

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
USE_QT_VER=	4
QT_COMPONENTS=	corelib dbus gui network svg xml  \
		qmake_build moc_build rcc_build uic_build
USE_CMAKE=	yes

USE_KDE4=	kdelibs kdeprefix automoc4

CMAKE_ARGS+=	-DCMAKE_REQUIRED_FLAGS:STRING="-L${LOCALBASE}/lib"
CMAKE_ARGS+=	-DCMAKE_INCLUDE_PATH:STRING="${LOCALBASE}/include"
CMAKE_ARGS+=	-DCMAKE_EXE_LINKER_FLAGS:STRING="-L${LOCALBASE}/lib"
CMAKE_ARGS+=    -DCMAKE_SHARED_LINKER_FLAGS:STRING="-L${LOCALBASE}/lib"
CMAKE_ENV+=     XDG_CONFIG_DIRS="${PREFIX}/etc/xdg/autostart"


post-extract:
	${REINPLACE_CMD} -e 's|$${LIB_INSTALL_DIR}/pkgconfig|libdata/pkgconfig|' \
		${WRKSRC}/CMakeLists.txt
#	${REINPLACE_CMD} -e 's|/etc/xdg|${PREFIX}/etc/xdg|' \
#		${WRKSRC}/agent/CMakeLists.txt

.include <bsd.port.mk>
