# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kdeutils
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	4
CATEGORIES=	misc kde
PKGNAMESUFFIX=	-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Collection of utilities for KDE 4

USES=		kde:4 metaport

OPTIONS_DEFINE=	ARK FILELIGHT KCALC KCHARSELECT KDF KFLOPPY KGPG \
		KREMOTECONTROL KTIMER KWALLET PRINTMANAGER \
		SUPERKARAMBA SWEEPER
OPTIONS_DEFAULT=	${OPTIONS_DEFINE}

ARK_DESC=		Archiving tool Ark
ARK_RUN_DEPENDS=	${KDE_PREFIX}/bin/ark:archivers/ark-kde4

FILELIGHT_DESC=		File system viewer Filelight
FILELIGHT_RUN_DEPENDS=	${KDE_PREFIX}/bin/filelight:sysutils/filelight

KCALC_DESC=		Scientific calculator KCalc
KCALC_RUN_DEPENDS=	${KDE_PREFIX}/bin/kcalc:math/kcalc-kde4

KCHARSELECT_DESC=	Character selector KCharSelect
KCHARSELECT_RUN_DEPENDS=	${KDE_PREFIX}/bin/kcharselect:deskutils/kcharselect-kde4

KDF_DESC=		Disk usage tool KDiskFree
KDF_RUN_DEPENDS=	${KDE_PREFIX}/bin/kdf:sysutils/kdf-kde4

KFLOPPY_DESC=		Floppy formatter KFloppy
KFLOPPY_RUN_DEPENDS=	${KDE_PREFIX}/bin/kfloppy:sysutils/kfloppy-kde4

KGPG_DESC=		Encryption tool KGpg
KGPG_RUN_DEPENDS=	${KDE_PREFIX}/bin/kgpg:security/kgpg-kde4

KREMOTECONTROL_DESC=	KRemoteControl
KREMOTECONTROL_RUN_DEPENDS=	${KDE_PREFIX}/bin/krcdnotifieritem:comms/kremotecontrol-kde4

KTIMER_DESC=		Countdown launcher KTimer
KTIMER_RUN_DEPENDS=	${KDE_PREFIX}/bin/ktimer:x11-clocks/ktimer-kde4

KWALLET_DESC=		Password manager KWallet
KWALLET_RUN_DEPENDS=	${KDE_PREFIX}/bin/kwalletmanager:security/kwalletmanager-kde4

PRINTMANAGER_DESC=	Print manager
PRINTMANAGER_RUN_DEPENDS=	${KDE_PREFIX}/lib/kde4/kcm_printer_manager.so:print/print-manager-kde4

SUPERKARAMBA_DESC=	Widget framework SuperKaramba
SUPERKARAMBA_RUN_DEPENDS=	${KDE_PREFIX}/bin/superkaramba:deskutils/superkaramba-kde4

SWEEPER_DESC=		System cleaner Sweeper
SWEEPER_RUN_DEPENDS=	${KDE_PREFIX}/bin/sweeper:sysutils/sweeper-kde4

.include <bsd.port.mk>
