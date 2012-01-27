# New ports collection makefile for:   retroshare
# Date created:        15 January 2012
# Whom:                glocke
#
# $FreeBSD$
#

PORTNAME=	retroshare
PORTVERSION=	0.5.2a
CATEGORIES=	net-p2p
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=${PORTNAME}/${BINARY}/${PORTVERSION}
DISTNAME=	${BINARY}-v${PORTVERSION}

MAINTAINER=	glocke@bsdstammtisch.at
COMMENT=	A private and secure decentralised communication platform

LICENSE=	GPLv2
LICENSE_FILE=	${WRKDIR}/trunk/retroshare-gui/src/license/license.txt

LIB_DEPENDS=	gpgme.19:${PORTSDIR}/security/gpgme \
		upnp.8:${PORTSDIR}/devel/upnp \
		gnome-keyring.0:${PORTSDIR}/security/libgnome-keyring
RUN_DEPENDS+=	pinentry-qt4:${PORTSDIR}/security/pinentry-qt4

WRKSRC=		${WRKDIR}/trunk
USE_QT_VER=	4
QT_COMPONENTS=	corelib gui network xml script designer_build uic_build \
		qmake_build moc_build rcc_build
HAS_CONFIGURE=	yes
BINARY=		RetroShare

DESKTOP_ENTRIES="${BINARY}" "${COMMENT}" "" "${BINARY}" \
		"Network;FileTransfer;" true

CFLAGS+=	-I${LOCALBASE}/include/gpgme

USE_DOS2UNIX=	retroshare-gui/src/${BINARY}.pro

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} PREFIX=${PREFIX} ${BINARY}.pro

post-patch:
	${CP} ${FILESDIR}/rsinit.h ${WRKSRC}/libretroshare/src/rsserver

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/retroshare-gui/src/${BINARY} ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${INSTALL_MAN} ${WRKSRC}/libbitdht/src/example/bdboot.txt ${DATADIR}
	@${ECHO_MSG} "**************************************************"
	@${ECHO_MSG} "*               POST INSTALL                     *"
	@${ECHO_MSG} "**************************************************"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "After you have created an account, you should copy"
	@${ECHO_MSG} "${DATADIR}/bdboot.txt into your"
	@${ECHO_MSG} "~/.retroshare/YOURCERT/ directory to seed DHT with"
	@${ECHO_MSG} "initial nodes. UPnP does not work right now, you"
	@${ECHO_MSG} "have to use port forwarding to connect to others."
	@${ECHO_MSG} ""
	@${ECHO_MSG} "**************************************************"

.include <bsd.port.mk>
