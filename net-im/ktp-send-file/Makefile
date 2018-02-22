# $FreeBSD$

PORTNAME=	ktp-send-file
PORTVERSION=	${KTP_VERSION}
PORTREVISION=	2
CATEGORIES=	net-im kde
MASTER_SITES=	KDE/${KTP_BRANCH}/kde-telepathy/${PORTVERSION}/src

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE instant messaging file transfer application

LIB_DEPENDS=	libtelepathy-qt4.so:net-im/telepathy-qt4 \
		libktpcommoninternalsprivate.so:net-im/ktp-common-internals
RUN_DEPENDS=	${KDE_PREFIX}/lib/kde4/libexec/ktp-filetransfer-handler:net-im/ktp-filetransfer-handler \
		${KDE_PREFIX}/bin/ktp-contactlist:net-im/ktp-contact-list

USES=		cmake gettext kde:4 tar:bzip2
USE_KDE=	kdelibs automoc4
USE_QT4=	corelib moc_build qmake_build rcc_build uic_build

.include <bsd.port.mk>
