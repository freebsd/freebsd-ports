# Created by: Dima Panov <fluffy@Fluffy.Khv.RU>
# $FreeBSD$

PORTNAME=	policykit-qt
PORTVERSION=	0.9.4
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	KDE/stable/apps/KDE4.x/admin/
DISTNAME=	polkit-qt-${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	PolicyKit manager for Qt

LIB_DEPENDS=	libpolkit.so:sysutils/policykit

USE_LDCONFIG=	yes
USES=		cmake gettext kde:4 pkgconfig tar:bzip2
USE_KDE=	automoc4
USE_QT4=	corelib dbus gui network svg xml  \
		qmake_build moc_build rcc_build uic_build

PORTSCOUT=	limit:^0

post-extract:
	${REINPLACE_CMD} -e 's|$${LIB_INSTALL_DIR}/pkgconfig|libdata/pkgconfig|' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
