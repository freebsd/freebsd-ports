# New ports collection Makefile for:	kdeutils
# Date created:				2008-01-31
# Whom:					Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	kdeutils
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	misc kde
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Collection of utilities for KDE 4

LATEST_LINK=	${PORTNAME}4

USE_KDE4=	kdeprefix
NO_BUILD=	yes

OPTIONS=	ARK "Install archiving tool Ark" on \
		FILELIGHT "Install file system viewer Filelight" on \
		KCALC "Install scientific calculator KCalc" on \
		KCHARSELECT "Install character selector KCharSelect" on \
		KDF "Install disk usage tool KDiskFree" on \
		KFLOPPY "Install floppy formatter KFloppy" on \
		KGPG "Install encryption tool KGpg" on \
		KREMOTECONTROL "Install KRemoteControl" on \
		KTIMER "Install countdown launcher KTimer" on \
		KWALLET "Install password manager KWallet" on \
		PRINTER_APPLET "Install printer system tray utility" on \
		SUPERKARAMBA "Install widget framework SuperKaramba" on \
		SWEEPER "Install system cleaner Sweeper" on

.include <bsd.port.options.mk>

.ifdef(WITH_ARK)
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/ark:${PORTSDIR}/archivers/ark
.endif

.ifdef(WITH_FILELIGHT)
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/filelight:${PORTSDIR}/sysutils/filelight-kde4
.endif

.ifdef(WITH_KCALC)
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/kcalc:${PORTSDIR}/math/kcalc
.endif

.ifdef(WITH_KCHARSELECT)
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/kcharselect:${PORTSDIR}/deskutils/kcharselect
.endif

.ifdef(WITH_KDF)
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/kdf:${PORTSDIR}/sysutils/kdf
.endif

.ifdef(WITH_KFLOPPY)
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/kfloppy:${PORTSDIR}/sysutils/kfloppy
.endif

.ifdef(WITH_KGPG)
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/kgpg:${PORTSDIR}/security/kgpg-kde4
.endif

.ifdef(WITH_KREMOTECONTROL)
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/krcdnotifieritem:${PORTSDIR}/comms/kremotecontrol
.endif

.ifdef(WITH_KTIMER)
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/ktimer:${PORTSDIR}/x11-clocks/ktimer
.endif

.ifdef(WITH_KWALLET)
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/kwalletmanager:${PORTSDIR}/security/kwallet
.endif

.ifdef(WITH_PRINTER_APPLET)
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/printer-applet:${PORTSDIR}/print/kdeutils4-printer-applet
.endif

.ifdef(WITH_SUPERKARAMBA)
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/superkaramba:${PORTSDIR}/deskutils/superkaramba
.endif

.ifdef(WITH_SWEEPER)
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/sweeper:${PORTSDIR}/sysutils/sweeper
.endif

do-install:
		${DO_NADA}

.include <bsd.port.mk>
