# $FreeBSD$

PORTNAME=	ktp
PORTVERSION=	${KTP_VERSION}
PORTREVISION=	3
CATEGORIES=	net-im kde
MASTER_SITES=	KDE/${KTP_BRANCH}/kde-telepathy/${PORTVERSION}/src
PKGNAMEPREFIX=	plasma-applet-
DISTNAME=	${PORTNAME}-desktop-applets-${PORTVERSION}
PKGNAMESUFFIX=	-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE instant messaging Plasma applets

LIB_DEPENDS=	libtelepathy-qt4.so:net-im/telepathy-qt4 \
		libktpcommoninternalsprivate.so:net-im/ktp-common-internals-kde4

USES=		cmake gettext kde:4 tar:bzip2
USE_KDE=	kdelibs automoc4
USE_QT4=	corelib declarative \
		moc_build qmake_build rcc_build uic_build

.include <bsd.port.mk>
