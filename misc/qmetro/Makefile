# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	qmetro
PORTVERSION=	0.6.5
CATEGORIES=	misc graphics
MASTER_SITES=	SF/${PORTNAME}/source/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Map of the transport system for many city subways

LICENSE=	GPLv2

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

USES=		dos2unix qmake qt:4 zip
INSTALLS_ICONS=	yes
USE_QT=		gui xml uic_build moc_build multimedia \
		rcc_build
LDFLAGS=	-lz
DOS2UNIX_FILES=	rc/alarm.pri

.include <bsd.port.mk>
