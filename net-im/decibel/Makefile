# Created by: arved
# $FreeBSD$

PORTNAME=	decibel
PORTVERSION=	0.5.0
PORTREVISION=	10
CATEGORIES=	net-im
MASTER_SITES=	http://decibel.kde.org/fileadmin/downloads/decibel/releases/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Realtime communications framework

LIB_DEPENDS=	QtTapioca.0:${PORTSDIR}/net-im/tapioca-qt

DEPRECATED=	Deprecated and unsupported upstream for many years, not used by anything
EXPIRATION_DATE=	2013-11-17

USE_QT4=	xml dbus gui qtestlib qmake_build moc_build uic_build rcc_build
USE_LDCONFIG=	yes
USES=		cmake pkgconfig

NO_STAGE=	yes
post-patch:
	${REINPLACE_CMD} -e \
		"s,$${LIB_INSTALL_DIR}/pkgconfig,data/pkgconfig,g"\
		${WRKSRC}/src/client/Decibel/CMakeLists.txt

.include <bsd.port.mk>
