# Created by: Dima Panov <fluffy@Fluffy.Khv.RU>
# $FreeBSD$

PORTNAME=	polkit-qt
PORTVERSION=	0.103.0
PORTREVISION=	1
DISTVERSIONPREFIX=	1-
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/apps/KDE4.x/admin/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt 4 frontend to PolKit-1

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	polkit-agent-1.0:${PORTSDIR}/sysutils/polkit

USE_BZIP2=	yes
USE_LDCONFIG=	yes
USE_KDE4=	automoc4
USE_QT4=	corelib dbus gui network svg xml  \
		qmake_build moc_build rcc_build uic_build
USES=		cmake gettext
# TODO: the next release (post-0.103.0) should have commit 56883bd, which
#       syncs FindGObject.cmake with kdelibs' and should find GObject without
#       requiring us to explicitly set LDFLAGS.
LDFLAGS+=	-L${LOCALBASE}/lib

NO_STAGE=	yes
post-extract:
	${REINPLACE_CMD} -e 's|$${LIB_INSTALL_DIR}/pkgconfig|libdata/pkgconfig|' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
