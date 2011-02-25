# New ports collection makefile for:	pcbsd-netmanager
# Date created:				Jul 14, 2009
# Whom:					Kris Moore
#
# $FreeBSD$
#

PORTNAME=	pcbsd-netmanager
PORTVERSION=	8.0
PORTREVISION=	3
CATEGORIES=	net kde
MASTER_SITES=	ftp://ftp.pcbsd.org/pub/software/ \
		http://www.pcbsd.org/~kris/software/

MAINTAINER=	kris@pcbsd.org
COMMENT=	PC-BSD Networking Utilities for KDE4

LIB_DEPENDS=	pcbsd.0:${PORTSDIR}/sysutils/libpcbsd

WRKSRC=		${WRKDIR}/pcbsd-netmanager

USE_GZIP=	yes
USE_QMAKE=	yes
USE_KDE4=	automoc4 kdehier kdeprefix kdelibs workspace 
USE_LDCONFIG=	yes
USE_QT_VER=	4
QT_COMPONENTS=	corelib qmake_build moc_build rcc_build uic_build linguist
HAS_CONFIGURE=	yes
MAKE_ARGS=	INSTALL_ROOT=${DESTDIR}

QMAKE_ARGS=	-unix -recursive ${QMAKE_PRO}
QMAKE_PRO=	pcbsdnetmanager.pro

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local/kde4|${PREFIX}|g' \
				 ${WRKSRC}/pcbsdnetmanager.pro \
				 ${WRKSRC}/src/NetworkManager/NetworkManager.pro \
				 ${WRKSRC}/src/NetworkManagerAdmin/NetworkManagerAdmin.pro \
				 ${WRKSRC}/src/NetworkTray/NetworkTray.pro \
				 ${WRKSRC}/src/ethernetconfig/ethernetconfig.pro \
				 ${WRKSRC}/src/wificonfig/wificonfig.pro

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} -unix CONFIG+="configure" ${QMAKE_PRO}

.include <bsd.port.mk>
