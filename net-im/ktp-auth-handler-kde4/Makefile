# $FreeBSD$

PORTNAME=	ktp-auth-handler
PORTVERSION=	${KTP_VERSION}
PORTREVISION=	3
CATEGORIES=	net-im kde
MASTER_SITES=	KDE/${KTP_BRANCH}/kde-telepathy/${PORTVERSION}/src
PKGNAMESUFFIX=	-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KWallet integration module for KDE Telepathy

DEPRECATED=	KDE4 is EOL upstream
EXPIRATION_DATE=	2018-12-31

LIB_DEPENDS=	libqjson.so:devel/qjson@qt4 \
		libqca.so:devel/qca@qt4 \
		libtelepathy-qt4.so:net-im/telepathy-qt@qt4 \
		libktpcommoninternalsprivate.so:net-im/ktp-common-internals-kde4

USES=		cmake gettext kde:4 qt:4 tar:bzip2
USE_KDE=	kdelibs automoc4
USE_QT=		corelib dbus gui xml webkit \
		moc_build qmake_build rcc_build uic_build

.include <bsd.port.mk>
