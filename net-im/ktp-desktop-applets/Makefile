# $FreeBSD$

PORTNAME=	ktp-desktop-applets
PORTVERSION=	${KTP_VERSION}
PORTREVISION=	2
CATEGORIES=	net-im kde
MASTER_SITES=	KDE/${KTP_BRANCH}/kde-telepathy/${PORTVERSION}/src

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE instant messaging plasma widgets

LIB_DEPENDS=	libktpcommoninternalsprivate.so:net-im/ktp-common-internals

USES=		cmake gettext kde:4 tar:bzip2
USE_KDE=	kdelibs automoc4
USE_QT4=	corelib moc_build qmake_build rcc_build uic_build

.include <bsd.port.mk>
