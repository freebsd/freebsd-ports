# New ports collection makefile for:	mute-net
# Date created:		Sat Dec 20 00:39:52 UTC 2003
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mute
PORTVERSION=	0.2.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}-net
PKGNAMESUFFIX=	-net
DISTNAME=	MUTE_fileSharing-${PORTVERSION}_UnixSource

MAINTAINER=	lioux@FreeBSD.org
COMMENT?=	Peer-to-peer client with privacy protection and easy search/download

USE_GMAKE=	yes
HAS_CONFIGURE=	yes

USE_PERL5_BUILD=yes
USE_REINPLACE=	yes

RELEASE_DIRECTORY=	MUTE_fileSharing-${PORTVERSION}-rc1_UnixSource

WRKSRC=		${WRKDIR}/${RELEASE_DIRECTORY}/MUTE
PATCH_WRKSRC=	${WRKDIR}/${RELEASE_DIRECTORY}

.ifndef(WITHOUT_GUI)
LIB_DEPENDS+=	wx_gtk2-2.4.0:${PORTSDIR}/x11-toolkits/wxgtk2

WX_CONFIG?=	${X11BASE}/bin/wxgtk2-2.4-config
.endif

#
MUTE_SETTINGS=		otherApps/fileSharing/userInterface/settings/
MUTE_CORE_GUI=		otherApps/fileSharing/userInterface/wxWindows/fileSharingMUTE
MUTE_CORE_GUI_FILE=	fileSharingMUTE
#
MUTE_CORE_TEXT=		otherApps/fileSharing/userInterface/textBased/textFileSharingMUTE
MUTE_CORE_TEXT_FILE=	textFileSharingMUTE

pre-everything::
#
.if (defined(WITHOUT_GUI) && defined(WITHOUT_TEXT))
	@${ECHO_MSG} "You need either GUI or TEXT interfaces."
	@${ECHO_MSG} "Only disable one of them!"
	@${FALSE}
.endif
#
.if !defined(WITHOUT_GUI) && !defined(WITHOUT_TEXT)
	@${ECHO_MSG} "You can disable the GUI interface by defining WITHOUT_GUI."
	@${ECHO_MSG} "You can disable the TEXT interface by defining WITHOUT_TEXT."
.endif

post-patch:
# C{flags,XX}, PTHREAD safeness
	@${REINPLACE_CMD} -E \
		-e 's|^GXX.+$$|GXX=${CXX}|' \
		-e 's|^(PLATFORM_LINK_FLAGS).+$$|\1=${PTHREAD_LIBS}|' \
		-e 's|(-DBSD)|\1 ${CFLAGS} ${PTHREAD_CFLAGS}|' \
		${PATCH_WRKSRC}/MUTE/Makefile.FreeBSDX86
# do not redefine socket_t
.for file in \
	minorGems/network/linux/SocketClientLinux.cpp \
	minorGems/network/linux/SocketLinux.cpp \
	minorGems/network/linux/SocketServerLinux.cpp
	@${REINPLACE_CMD} -E \
		-e 's|typedef int socklen_t;||' \
		${PATCH_WRKSRC}/${file}
.endfor
# do we want GUI?
.ifndef(WITHOUT_GUI)
	@${REINPLACE_CMD} -E \
		-e 's|%%WX_CONFIG%%|${WX_CONFIG}|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
	@${SED} -e "s|%%PREFIX%%|${PREFIX}|" \
		-e "s|%%DATADIR%%|${DATADIR}|" \
		-e "s|%%INTERFACE%%|gui|" \
		${FILESDIR}/wrapper.sh > \
		${WRKDIR}/wrapper-gui.sh
.endif
.ifndef(WITHOUT_TEXT)
	@${SED} -e "s|%%PREFIX%%|${PREFIX}|" \
		-e "s|%%DATADIR%%|${DATADIR}|" \
		-e "s|%%INTERFACE%%|text|" \
		${FILESDIR}/wrapper.sh > \
		${WRKDIR}/wrapper-text.sh
.endif

post-configure:
# we will use GNU make
# XXX - g modifier does not work with sed from REINPLACE_CMD
#	@${REINPLACE_CMD} -E \
	@${PERL} -pi \
		-e 's| make| ${GMAKE}|g' \
		${CONFIGURE_WRKSRC}/${MAKEFILE}
# CXX safeness
	@${REINPLACE_CMD} -E \
		-e 's|g\+\+|${CXX}|' \
		${WRKSRC}/otherApps/fileSharing/userInterface/wxWindows/Makefile

post-build:
.ifndef(WITHOUT_GUI)
	@cd ${BUILD_WRKSRC}/otherApps/fileSharing/userInterface/wxWindows/ ; \
		${GMAKE}

.endif

do-install:
# install initial settings
	@${MKDIR} ${DATADIR}/settings/
	@${INSTALL_DATA} ${INSTALL_WRKSRC}/${MUTE_SETTINGS}/* \
		${DATADIR}/settings/
# gui interface
.ifndef(WITHOUT_GUI)
# install binary
	@${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/${MUTE_CORE_GUI} \
		${PREFIX}/bin/${MUTE_CORE_GUI_FILE}-real
# install wrapper
	@${INSTALL_SCRIPT} ${WRKDIR}/wrapper-gui.sh \
		${PREFIX}/bin/${MUTE_CORE_GUI_FILE}
.endif
# text interface
.ifndef(WITHOUT_TEXT)
# install binary
	@${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/${MUTE_CORE_TEXT} \
		${PREFIX}/bin/${MUTE_CORE_TEXT_FILE}-real
# install wrapper
	@${INSTALL_SCRIPT} ${WRKDIR}/wrapper-text.sh \
		${PREFIX}/bin/${MUTE_CORE_TEXT_FILE}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.pre.mk>

# we cannot install if either a slave or master port is already
# installed
CONFLICTS+=	mute-net-[0-9]*

# gui interface
.ifndef(WITHOUT_GUI)
# we cannot install if slave gui port is installed
PLIST_SUB+=	GUI=""

CONFLICTS+=	mute-net-gui-*
.else
# tag package name properly
PKGNAMESUFFIX:=	${PKGNAMESUFFIX}-text

PLIST_SUB+=	GUI="@comment "
.endif

# text interface
.ifndef(WITHOUT_TEXT)
PLIST_SUB+=	TEXT=""

CONFLICTS+=	mute-net-text-*
.else
# tag package name properly
PKGNAMESUFFIX:=	${PKGNAMESUFFIX}-gui

PLIST_SUB+=	TEXT="@comment "
.endif

.include <bsd.port.post.mk>
