# Created by: Dima Panov <fluffy@FreeBSD.org>
# $FreeBSD$

PORTNAME=	hupnp
PORTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	net devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}
DISTNAME=	herqq-${PORTVERSION}

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	Library for building UPnP devices and control points

USES=		gmake qmake zip
USE_QT4=	corelib network xml dbus gui \
		moc_build rcc_build uic_build

QMAKE_ARGS=	"CONFIG+=DISABLE_AVTESTAPP DISABLE_TESTAPP"

.include <bsd.port.mk>
