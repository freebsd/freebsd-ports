# $FreeBSD$

PORTNAME=	krfb
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	net kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	VNC server for KDE

LIB_DEPENDS=	libtelepathy-qt4.so:net-im/telepathy-qt4

USES=		alias cmake:outsource jpeg tar:xz
USE_KDE4=	kdelibs kdeprefix automoc4
USE_QT4=	corelib gui network \
		moc_build qmake_build rcc_build uic_build

.include <bsd.port.mk>
