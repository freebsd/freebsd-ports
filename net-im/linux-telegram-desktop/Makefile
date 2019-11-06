# Created by: Henry Hu <henry.hu.sh@gmail.com>
# $FreeBSD$

PORTNAME=	telegram-desktop
PORTVERSION=	1.3.0
CATEGORIES=	net-im linux
MASTER_SITES=	https://updates.tdesktop.com/tlinux32/
PKGNAMEPREFIX=	linux-
DISTNAME=	tsetup32.${PORTVERSION}

MAINTAINER=	henry.hu.sh@gmail.com
COMMENT=	Official desktop client for Telegram messenger (Linux version)

BROKEN=		unfetchable

LICENSE=	GPLv3

USES=		linux:c7 tar:xz
USE_LINUX=	alsalib alsa-plugins-oss dbuslibs dri expat gtk2 xorglibs
NO_BUILD=	yes
RUN_DEPENDS=	dbus-launch:devel/dbus

WRKSRC=		${WRKDIR}/Telegram
TDESKTOPDIR=	lib/telegram-desktop
SUB_FILES=	telegram-desktop.sh
SUB_LIST=	TDESKTOPDIR=${TDESKTOPDIR}

DESKTOP_ENTRIES=	"Telegram Desktop" "${COMMENT}" "" \
			"${PREFIX}/bin/telegram-desktop -- %u" \
			"Network;InstantMessaging;" false

PLIST_FILES=	bin/telegram-desktop ${TDESKTOPDIR}/Telegram

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${TDESKTOPDIR}
# The main program binary
	${INSTALL_PROGRAM} ${WRKSRC}/Telegram \
		${STAGEDIR}${PREFIX}/${TDESKTOPDIR}
# Wrapper for the main program
	${INSTALL_SCRIPT} ${WRKDIR}/telegram-desktop.sh \
		${STAGEDIR}${PREFIX}/bin/telegram-desktop

.include <bsd.port.mk>
