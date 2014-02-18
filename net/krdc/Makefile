# $FreeBSD$

PORTNAME=	krdc
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	net kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	RDP and VNC client for KDE

LIB_DEPENDS=	libvncserver.so:${PORTSDIR}/net/libvncserver \
		libtelepathy-qt4.so:${PORTSDIR}/net-im/telepathy-qt4

USES=		cmake:outsource
USE_KDE4=	kdehier kdelibs kdeprefix automoc4
USE_QT4=	moc_build qmake_build rcc_build uic_build
USE_XZ=		yes
USE_LDCONFIG=	yes

.include <bsd.port.mk>
