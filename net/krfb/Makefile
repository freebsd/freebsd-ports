# $FreeBSD$

PORTNAME=	krfb
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	3
CATEGORIES=	net kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	VNC server for KDE

LIB_DEPENDS=	libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libtelepathy-qt4.so:${PORTSDIR}/net-im/telepathy-qt4

USES=		cmake:outsource tar:xz
USE_KDE4=	kdehier kdelibs kdeprefix automoc4
USE_QT4=	corelib gui network \
		moc_build qmake_build rcc_build uic_build

.include <bsd.port.mk>
