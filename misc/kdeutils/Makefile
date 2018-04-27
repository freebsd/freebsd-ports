# $FreeBSD$

PORTNAME=	kdeutils
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	misc kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Collection of utilities for KDE

USES=		kde:5 metaport

RUN_DEPENDS=	ark>=${KDE_APPLICATIONS_VERSION}:archivers/ark \
		filelight>=${KDE_APPLICATIONS_VERSION}:sysutils/filelight \
		kcalc>=${KDE_APPLICATIONS_VERSION}:math/kcalc \
		kcharselect>=${KDE_APPLICATIONS_VERSION}:deskutils/kcharselect \
		kdebugsettings>=${KDE_APPLICATIONS_VERSION}:sysutils/kdebugsettings \
		kdf>=${KDE_APPLICATIONS_VERSION}:sysutils/kdf \
		kfloppy>=${KDE_APPLICATIONS_VERSION}:sysutils/kfloppy \
		kgpg>=${KDE_APPLICATIONS_VERSION}:security/kgpg \
		kteatime>=${KDE_APPLICATIONS_VERSION}:x11-clocks/kteatime \
		ktimer>=${KDE_APPLICATIONS_VERSION}:x11-clocks/ktimer \
		kwalletmanager>=${KDE_APPLICATIONS_VERSION}:security/kwalletmanager \
		print-manager>=${KDE_APPLICATIONS_VERSION}:print/print-manager

.include <bsd.port.mk>
