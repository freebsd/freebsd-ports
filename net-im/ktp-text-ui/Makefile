# $FreeBSD$

PORTNAME=	ktp-text-ui
PORTVERSION=	${KTP_VERSION}
CATEGORIES=	net-im kde
MASTER_SITES=	KDE/${KTP_BRANCH}/kde-telepathy/${PORTVERSION}/src

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE chat window application

LIB_DEPENDS=	libtelepathy-qt4.so:net-im/telepathy-qt4 \
		libtelepathy-logger-qt4.so:net-im/telepathy-logger-qt4 \
		libktpcommoninternalsprivate.so:net-im/ktp-common-internals
RUN_DEPENDS=	${KDE4_PREFIX}/bin/ktp-contactlist:net-im/ktp-contact-list

USE_KDE4=	automoc4
USE_QT4=	corelib webkit xml \
		moc_build qmake_build rcc_build uic_build
USES=		cmake compiler:c++11-lang gettext tar:bzip2
USE_LDCONFIG=	yes

.include <bsd.port.mk>
