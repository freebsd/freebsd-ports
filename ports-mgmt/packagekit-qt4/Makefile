# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/ports-mgmt/packagekit-qt4/Makefile 19804 2014-08-13 14:55:11Z kwm $

PORTNAME=	packagekit-qt4
PORTVERSION=	0.8.8
CATEGORIES=	ports-mgmt sysutils
MASTER_SITES=	http://www.packagekit.org/releases/
DISTNAME=	PackageKit-Qt-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Qt4 bindings to packagekit

BUILD_DEPENDS=	packagekit>=0.8.8:${PORTSDIR}/ports-mgmt/packagekit
RUN_DEPENDS=	packagekit>=0.8.8:${PORTSDIR}/ports-mgmt/packagekit

USE_LDCONFIG=	yes
USES=		cmake:outsource pkgconfig tar:xz
USE_GNOME=	glib20
USE_QT4=	dbus xml sql qmake_build moc_build uic_build rcc_build

.include <bsd.port.mk>
