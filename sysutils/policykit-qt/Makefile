# Created by: Dima Panov <fluffy@Fluffy.Khv.RU>
# $FreeBSD$

PORTNAME=	policykit-qt
PORTVERSION=	0.9.4
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/apps/KDE4.x/admin/
DISTNAME=	polkit-qt-${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	PolicyKit manager for Qt

LIB_DEPENDS=	polkit.2:${PORTSDIR}/sysutils/policykit

USE_BZIP2=	yes
USE_LDCONFIG=	yes
USE_KDE4=	automoc4
USE_QT4=	corelib dbus gui network svg xml  \
		qmake_build moc_build rcc_build uic_build
USES=		cmake gettext

PORTSCOUT=	limit:^0

NO_STAGE=	yes
post-extract:
	${REINPLACE_CMD} -e 's|$${LIB_INSTALL_DIR}/pkgconfig|libdata/pkgconfig|' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
