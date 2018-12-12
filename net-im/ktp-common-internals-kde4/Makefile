# $FreeBSD$

PORTNAME=	ktp-common-internals
PORTVERSION=	${KTP_VERSION}
PORTREVISION=	7
CATEGORIES=	net-im kde
MASTER_SITES=	KDE/${KTP_BRANCH}/kde-telepathy/${PORTVERSION}/src
PKGNAMESUFFIX=	-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE Telepathy internal library

DEPRECATED=	KDE4 is EOL upstream
EXPIRATION_DATE=	2018-12-31

LIB_DEPENDS=	libtelepathy-qt4.so:net-im/telepathy-qt@qt4 \
		libtelepathy-logger-qt4.so:net-im/telepathy-logger-qt4
RUN_DEPENDS=	${LOCALBASE}/libexec/mission-control-5:net-im/telepathy-mission-control

USES=		cmake compiler:c++11-lang gettext kde:4 qt:4 tar:bzip2
USE_KDE=	kdelibs pimlibs automoc4
USE_QT=		declarative script \
		moc_build qmake_build rcc_build uic_build
USE_LDCONFIG=	yes

PLIST_SUB=	KTP_VERSION=${KTP_VERSION}

.include <bsd.port.mk>
