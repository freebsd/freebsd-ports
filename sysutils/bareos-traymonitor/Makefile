PORTNAME=	bareos
PORTREVISION=	1
PKGNAMESUFFIX=	-traymonitor

COMMENT=	Backup archiving recovery open sourced (traymonitor)
WWW=		https://www.bareos.org/

LIB_DEPENDS+=	libqwt5-qt5.so:x11-toolkits/qwt5-qt5 \
		libbareos.so:sysutils/bareos-client

CONFLICTS=	bareos18-traymonitor bareos19-traymonitor bareos20-traymonitor

USES=		desktop-file-utils gettext-runtime pkgconfig qt:5
USE_QT=		buildtools_build qmake_build uitools_build gui core widgets
WITH_BAT=	yes

PLIST=		${.CURDIR}/pkg-plist
CFLAGS+=	-DMDB_DSYNC=O_SYNC -DMDB_USE_POSIX_SEM=1

MASTERDIR=	${.CURDIR}/../../sysutils/bareos-server

CMAKE_ARGS+=		-Dtraymonitor=yes \
			-Dbuild-dird=no \
			-Dbuild-stored=no \
			-Dclient-only=yes \
			-Dnls=ON

.include "${MASTERDIR}/Makefile"
