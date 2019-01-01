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

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

BUILD_DEPENDS=	automoc4:devel/automoc4
LIB_DEPENDS=	libpolkit.so:sysutils/policykit

USE_LDCONFIG=	yes
USES=		cmake gettext pkgconfig qt:4 tar:bzip2
USE_QT=		corelib dbus gui network svg xml  \
		qmake_build moc_build rcc_build uic_build

PORTSCOUT=	limit:^0

post-extract:
	${REINPLACE_CMD} -e 's|$${LIB_INSTALL_DIR}/pkgconfig|libdata/pkgconfig|' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
