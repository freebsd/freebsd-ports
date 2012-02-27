# New ports collection makefile for:   retroshare
# Date created:        15 January 2012
# Whom:                glocke
#
# $FreeBSD$
#

PORTNAME=	retroshare
PORTVERSION=	0.5.3a
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
BINARY_NOGUI=	retroshare-nogui
MAKE_JOBS_UNSAFE=yes

DESKTOP_ENTRIES="${BINARY}" "${COMMENT}" "" "${BINARY}" \
		"Network;FileTransfer;" true

OPTIONS=	NOGUI "Also build nogui binary" Off

.include <bsd.port.options.mk>

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} PREFIX=${PREFIX} ${BINARY}.pro

post-patch:
	@${REINPLACE_CMD} -e 's|plugins|#plugins|' ${WRKSRC}/${BINARY}.pro
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/libretroshare/src/libretroshare.pro
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/retroshare-gui/src/RetroShare.pro
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/retroshare-nogui/src/retroshare-nogui.pro
	@${REINPLACE_CMD} -e 's|/usr/local/share/retroshare|${DATADIR}|' \
		${WRKSRC}/libretroshare/src/rsserver/rsinit.cc
.if defined(WITHOUT_NOGUI)
	@${REINPLACE_CMD} -e 's|retroshare-nogui|#retroshare-nogui|' \
		${WRKSRC}/${BINARY}.pro
	@${REINPLACE_CMD} -e 's|RetroShare.pro \\|RetroShare.pro|' \
		${WRKSRC}/${BINARY}.pro
.else
	@${REINPLACE_CMD} -e 's|retroshare-nogui.pro \\|retroshare-nogui.pro|' \
		${WRKSRC}/${BINARY}.pro
.endif

pre-install:
.if defined(WITHOUT_NOGUI)
PLIST_SUB+=	NOGUI="@comment "
.else
PLIST_SUB+=	NOGUI=""
.endif

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/retroshare-gui/src/${BINARY} ${PREFIX}/bin
.if defined(WITH_NOGUI)
	${INSTALL_PROGRAM} ${WRKSRC}/retroshare-nogui/src/${BINARY_NOGUI} ${PREFIX}/bin
.endif
	${MKDIR} ${DATADIR}
	${INSTALL_MAN} ${WRKSRC}/libbitdht/src/example/bdboot.txt ${DATADIR}

.include <bsd.port.mk>
