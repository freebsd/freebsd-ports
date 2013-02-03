# Created by: Martin Wilke <miwi@FreeBSD.org>
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

OPTIONS_DEFINE=	ARK FILELIGHT KCALC KCHARSELECT KDF KFLOPPY KGPG \
		KREMOTECONTROL KTIMER KWALLET PRINTER_APPLET \
		SUPERKARAMBA SWEEPER
OPTIONS_DEFAULT=	${OPTIONS_DEFINE}

ARK_DESC=		Install archiving tool Ark
FILELIGHT_DESC=		Install file system viewer Filelight
KCALC_DESC=		Install scientific calculator KCalc
KCHARSELECT_DESC=	Install character selector KCharSelect
KDF_DESC=		Install disk usage tool KDiskFree
KFLOPPY_DESC=		Install floppy formatter KFloppy
KGPG_DESC=		Install encryption tool KGpg
KREMOTECONTROL_DESC=	Install KRemoteControl
KTIMER_DESC=		Install countdown launcher KTimer
KWALLET_DESC=		Install password manager KWallet
PRINTER_APPLET_DESC=	Install printer system tray utility
SUPERKARAMBA_DESC=	Install widget framework SuperKaramba
SWEEPER_DESC=		Install system cleaner Sweeper

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MARK}
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/ark:${PORTSDIR}/archivers/ark
.endif

.if ${PORT_OPTIONS:MFILELIGHT}
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/filelight:${PORTSDIR}/sysutils/filelight-kde4
.endif

.if ${PORT_OPTIONS:MKCALC}
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/kcalc:${PORTSDIR}/math/kcalc
.endif

.if ${PORT_OPTIONS:MKCHARSELECT}
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/kcharselect:${PORTSDIR}/deskutils/kcharselect
.endif

.if ${PORT_OPTIONS:MKDF}
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/kdf:${PORTSDIR}/sysutils/kdf
.endif

.if ${PORT_OPTIONS:MKFLOPPY}
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/kfloppy:${PORTSDIR}/sysutils/kfloppy
.endif

.if ${PORT_OPTIONS:MKGPG}
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/kgpg:${PORTSDIR}/security/kgpg-kde4
.endif

.if ${PORT_OPTIONS:MKREMOTECONTROL}
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/krcdnotifieritem:${PORTSDIR}/comms/kremotecontrol
.endif

.if ${PORT_OPTIONS:MKTIMER}
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/ktimer:${PORTSDIR}/x11-clocks/ktimer
.endif

.if ${PORT_OPTIONS:MKWALLET}
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/kwalletmanager:${PORTSDIR}/security/kwallet
.endif

.if ${PORT_OPTIONS:MPRINTER_APPLET}
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/printer-applet:${PORTSDIR}/print/kdeutils4-printer-applet
.endif

.if ${PORT_OPTIONS:MSUPERKARAMBA}
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/superkaramba:${PORTSDIR}/deskutils/superkaramba
.endif

.if ${PORT_OPTIONS:MSWEEPER}
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/sweeper:${PORTSDIR}/sysutils/sweeper
.endif

do-install:
		${DO_NADA}

.include <bsd.port.mk>
