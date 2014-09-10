# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kdeutils
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	2
CATEGORIES=	misc kde
DISTFILES=	# empty

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Collection of utilities for KDE 4

USE_KDE4=	kdeprefix
NO_BUILD=	yes
NO_INSTALL=	yes
NO_MTREE=	yes

OPTIONS_DEFINE=	ARK FILELIGHT KCALC KCHARSELECT KDF KFLOPPY KGPG \
		KREMOTECONTROL KTIMER KWALLET PRINTMANAGER \
		SUPERKARAMBA SWEEPER
OPTIONS_DEFAULT=	${OPTIONS_DEFINE}

ARK_DESC=		Archiving tool Ark
ARK_RUN_DEPENDS=	${KDE4_PREFIX}/bin/ark:${PORTSDIR}/archivers/ark

FILELIGHT_DESC=		File system viewer Filelight
FILELIGHT_RUN_DEPENDS=	${KDE4_PREFIX}/bin/filelight:${PORTSDIR}/sysutils/filelight-kde4

KCALC_DESC=		Scientific calculator KCalc
KCALC_RUN_DEPENDS=	${KDE4_PREFIX}/bin/kcalc:${PORTSDIR}/math/kcalc

KCHARSELECT_DESC=	Character selector KCharSelect
KCHARSELECT_RUN_DEPENDS=	${KDE4_PREFIX}/bin/kcharselect:${PORTSDIR}/deskutils/kcharselect

KDF_DESC=		Disk usage tool KDiskFree
KDF_RUN_DEPENDS=	${KDE4_PREFIX}/bin/kdf:${PORTSDIR}/sysutils/kdf

KFLOPPY_DESC=		Floppy formatter KFloppy
KFLOPPY_RUN_DEPENDS=	${KDE4_PREFIX}/bin/kfloppy:${PORTSDIR}/sysutils/kfloppy

KGPG_DESC=		Encryption tool KGpg
KGPG_RUN_DEPENDS=	${KDE4_PREFIX}/bin/kgpg:${PORTSDIR}/security/kgpg-kde4

KREMOTECONTROL_DESC=	KRemoteControl
KREMOTECONTROL_RUN_DEPENDS=	${KDE4_PREFIX}/bin/krcdnotifieritem:${PORTSDIR}/comms/kremotecontrol

KTIMER_DESC=		Countdown launcher KTimer
KTIMER_RUN_DEPENDS=	${KDE4_PREFIX}/bin/ktimer:${PORTSDIR}/x11-clocks/ktimer

KWALLET_DESC=		Password manager KWallet
KWALLET_RUN_DEPENDS=	${KDE4_PREFIX}/bin/kwalletmanager:${PORTSDIR}/security/kwalletmanager

PRINTMANAGER_DESC=	Print manager
PRINTMANAGER_RUN_DEPENDS=	${KDE4_PREFIX}/lib/kde4/kcm_printer_manager.so:${PORTSDIR}/print/kde4-print-manager

SUPERKARAMBA_DESC=	Widget framework SuperKaramba
SUPERKARAMBA_RUN_DEPENDS=	${KDE4_PREFIX}/bin/superkaramba:${PORTSDIR}/deskutils/superkaramba

SWEEPER_DESC=		System cleaner Sweeper
SWEEPER_RUN_DEPENDS=	${KDE4_PREFIX}/bin/sweeper:${PORTSDIR}/sysutils/sweeper

.include <bsd.port.mk>
