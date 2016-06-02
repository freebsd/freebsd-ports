# $FreeBSD$

PORTNAME=	ktp-common-internals
PORTVERSION=	${KTP_VERSION}
CATEGORIES=	net-im kde
MASTER_SITES=	KDE/${KTP_BRANCH}/kde-telepathy/${PORTVERSION}/src

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE Telepathy internal library

LIB_DEPENDS=	libtelepathy-qt4.so:net-im/telepathy-qt4 \
		libtelepathy-logger-qt4.so:net-im/telepathy-logger-qt4
RUN_DEPENDS=	${LOCALBASE}/libexec/mission-control-5:net-im/telepathy-mission-control

USE_KDE4=	kdelibs pimlibs automoc4
USE_QT4=	declarative script \
		moc_build qmake_build rcc_build uic_build
USES=		cmake compiler:c++11-lang gettext tar:bzip2
USE_LDCONFIG=	yes

PLIST_SUB=	KTP_VERSION=${KTP_VERSION}

.include <bsd.port.mk>
