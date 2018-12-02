# Created by: Dima Panov <fluffy@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cagibi
PORTVERSION=	0.2.0
PORTREVISION=	1
CATEGORIES=	net devel
MASTER_SITES=	KDE/stable/${PORTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE SSDP/uPNP proxy

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

USES=		cmake kde:4 qt:4 tar:bzip2
USE_KDE=	automoc4
USE_QT=		corelib network xml dbus \
		qmake_build moc_build rcc_build uic_build

.include <bsd.port.mk>
