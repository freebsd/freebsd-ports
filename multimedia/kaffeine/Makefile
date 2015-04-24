# Created by: arved
# $FreeBSD$

PORTNAME=	kaffeine
PORTVERSION=	1.2.2
PORTREVISION=	8
CATEGORIES=	multimedia kde
MASTER_SITES=	SF/kaffeine/current

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Xine-base multimedia player

BUILD_DEPENDS=	${LOCALBASE}/include/linux/dvb/ca.h:${PORTSDIR}/multimedia/v4l_compat
LIB_DEPENDS=	libxine.so:${PORTSDIR}/multimedia/libxine

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_KDE4=	kdeprefix automoc4 kdelibs
USE_QT4=	corelib gui phonon svg network dbus xml sql \
		qmake_build moc_build rcc_build uic_build
USES=		cmake cpe gettext gmake
USE_LDCONFIG=		yes
USE_XORG=	xscrnsaver
CPE_VENDOR=	kaffeine
CPE_PRODUCT=	kaffeine_player

post-patch:
	${REINPLACE_CMD} -e 's,add_subdirectory(x-test),,' ${WRKSRC}/po/CMakeLists.txt

.include <bsd.port.mk>
