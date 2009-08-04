# New ports collection makefile for:	PolicyKit-qt
# Date created:		2009-07-09
# Whom:			Dima Panov <fluffy@Fluffy.Khv.RU>
#
# $FreeBSD$
#

PORTNAME=	policykit-qt
PORTVERSION=	0.9.2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITES=	ftp://ftp.kde.org/pub/kde/stable/apps/KDE4.x/admin/
DISTNAME=	polkit-qt-${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	PolicyKit manager for Qt

LIB_DEPENDS=	polkit.2:${PORTSDIR}/sysutils/policykit

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
USE_QT_VER=	4
QT_COMPONENTS=	corelib dbus gui network svg xml  \
		qmake_build moc_build rcc_build uic_build
USE_CMAKE=	yes

USE_KDE4=	automoc4

CMAKE_ARGS+=	-DCMAKE_REQUIRED_FLAGS:STRING="-L${LOCALBASE}/lib"
CMAKE_ARGS+=	-DCMAKE_INCLUDE_PATH:STRING="${LOCALBASE}/include"
CMAKE_ARGS+=	-DCMAKE_EXE_LINKER_FLAGS:STRING="-L${LOCALBASE}/lib"
CMAKE_ARGS+=    -DCMAKE_SHARED_LINKER_FLAGS:STRING="-L${LOCALBASE}/lib"

post-extract:
	${REINPLACE_CMD} -e 's|$${LIB_INSTALL_DIR}/pkgconfig|libdata/pkgconfig|' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
