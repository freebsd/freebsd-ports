# Created by: Artyom Mirgorodskiy <artyom.mirgorodsky@gmail.com>
# $FreeBSD$

PORTNAME=	flashplugin
PORTVERSION=	11.2r202.535
CATEGORIES=	www multimedia linux
MASTER_SITES=	http://fpdownload.macromedia.com/get/flashplayer/pdc/${PORTVERSION:S/r/./}/:plugin \
		LOCAL/nox:suplib
PKGNAMEPREFIX=	linux-${USE_LINUX}-
DISTFILES=	install_flash_player_11_linux.i386.tar.gz:plugin
DIST_SUBDIR=	${PORTNAME}/${PORTVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Adobe Flash Player NPAPI Plugin

ONLY_FOR_ARCHS=	amd64 i386
USE_LINUX?=	c6
USE_LINUX_APPS?=	curl cyrus-sasl2 gdkpixbuf2 gtk2 nspr nss # libssh2 openldap
WANT_GNOME=	yes

DISTINFO_FILE?=	${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}
PLIST?=		${MASTERDIR}/pkg-plist.${LINUX_RPM_ARCH}

RESTRICTED=	Redistribution not allowed
RESTRICTED_FILES=	${DISTFILES:Nlinux-f10-flashsupport*:C/:[^:]+$//}

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

USES=		webplugin:linux desktop-file-utils cpe
WEBPLUGIN_FILES=	libflashplayer.so

OPTIONS_DEFINE=	ALSA GNOME
OPTIONS_SUB=	yes

ALSA_DESC=	ALSA audio output (broken, needs lemul)
ALSA_RUN_DEPENDS?=	linux-${USE_LINUX}-alsa-lib>=1.0.22_2:${PORTSDIR}/audio/linux-c6-alsa-lib
ALSA_DISTFILES_OFF=	linux-f10-flashsupport-9.0.1.i386.tar.gz:suplib
ALSA_PLIST_SUB_OFF=	LINUXBASE="${LINUXBASE}" COMPATDIR="${LINUXBASE:H}"

GNOME_DESC=	include gnome support for .desktop file
GNOME_USES=	desktop-file-utils

CPE_VENDOR=	adobe
CPE_PRODUCT=	flash_player

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MALSA}
USE_LINUX_APPS+=alsalib alsa-plugins-oss
.else
.if ${USE_LINUX} == "f10"
USE_LINUX_APPS+=	openssl
.else
USE_LINUX_APPS+=	openssl-compat
.endif
.endif

.if ${PORT_OPTIONS:MGNOME}
INSTALLS_ICONS=	yes
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr|${PREFIX}|' -e '/^NotShowIn=KDE/d' ${WRKDIR}/usr/share/applications/flash-player-properties.desktop

do-install:
	${MKDIR} ${STAGEDIR}${WEBPLUGIN_DIR}
	${INSTALL_LIB} ${WRKDIR}/libflashplayer.so ${STAGEDIR}${WEBPLUGIN_DIR}
.if ! ${PORT_OPTIONS:MALSA}
	${MKDIR} ${STAGEDIR}${LINUXBASE}/usr/lib
	${INSTALL_LIB} ${WRKDIR}/libflashsupport.so ${STAGEDIR}${LINUXBASE}/usr/lib
.endif
	${INSTALL_PROGRAM} ${WRKDIR}/usr/bin/flash-player-properties ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKDIR}/usr/share/applications/flash-player-properties.desktop ${STAGEDIR}${DESKTOPDIR}
	(cd ${WRKDIR}/usr/share/icons && ${COPYTREE_SHARE} hicolor ${STAGEDIR}${PREFIX}/share/icons)

.include <bsd.port.mk>
