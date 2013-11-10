# Created by: Dima Panov <fluffy@FreeBSD.org>
# $FreeBSD$

PORTNAME=	hupnp
PORTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	net devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}
DISTNAME=	herqq-${PORTVERSION}

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	A library for building UPnP devices and control points

USES=		gmake qmake
USE_ZIP=	yes
USE_QT4=	corelib network xml dbus gui \
		qmake_build moc_build rcc_build uic_build

QMAKE_ARGS=	"CONFIG+=DISABLE_AVTESTAPP DISABLE_TESTAPP"
QMAKE_PRO=	herqq.pro

.include <bsd.port.mk>
