# $FreeBSD$

PORTNAME=	plasma-disks
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	sysutils kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Monitors S.M.A.R.T. capable devices for imminent failure

# XXX license
# https://invent.kde.org/plasma/plasma-disks/-/tree/master/LICENSES
LICENSE=	BSD3CLAUSE CC0-1.0 GPLv2 GPLv3 LGPL3 # FSF KDE-GPL KDE-LGPL
LICENSE_COMB=	multi
#LICENSE_NAME_KDE-GPL=	LicenseRef KDE Accepted GPL
#LICENSE_NAME_KDE-LGPL=	LicenseRef KDE Accepted LGPL
LICENSE_FILE_BSD3CLAUSE=	${WRKSRC}/LICENSES/BSD-3-Clause.txt
LICENSE_FILE_CC0-1.0=	${WRKSRC}/LICENSES/CC0-1.0.txt
LICENSE_FILE_GPLv2=	${WRKSRC}/LICENSES/GPL-2.0-only.txt
LICENSE_FILE_GPLv3=	${WRKSRC}/LICENSES/GPL-3.0-only.txt
LICENSE_FILE_LGPL3=	${WRKSRC}/LICENSES/LGPL-3.0-only.txt
#LICENSE_FILE_FSF=	${WRKSRC}/LICENSES/FSFAP.txt
#LICENSE_PERMS_KDE-GPL=	gpl3
#LICENSE_PERMS_KDE-LGPL= gpl3	

RUN_DEPENDS=	smartmontools>0:sysutils/smartmontools

USES=		cmake compiler:c++11-lang kde:5 qt:5 tar:xz

USE_KDE=	activities config configwidgets coreaddons ecm ksysguard \
		plasma-framework codecs service kio windowsystem auth i18n \
		kdeclarative solid notifications dbusaddons widgetsaddons
USE_QT=		core dbus buildtools_build qmake_build quickcontrols network \
		gui xml concurrent declarative widgets

post-patch:
	${REINPLACE_CMD} "s|LOCALBASE|${LOCALBASE}|" \
		${WRKSRC}/src/helper.cpp

.include <bsd.port.mk>
