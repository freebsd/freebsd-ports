PORTREVISION=	0

COMMENT=	Backup archiving recovery open sourced (traymonitor)

LIB_DEPENDS+=	libbareos.so:sysutils/bareos-client

CONFLICTS=	bareos22-traymonitor bareos23-traymonitor bareos-traymonitor

USES=		desktop-file-utils gettext-runtime pkgconfig

PKGNAMESUFFIX=	24-traymonitor

USES+=		qt:6
USE_QT=		base:run declarative:build tools:build
CMAKE_ARGS+=	-Dbat-qt6=yes

WITH_BAT=	yes

PLIST=		${.CURDIR}/pkg-plist
CFLAGS+=	-DMDB_DSYNC=O_SYNC -DMDB_USE_POSIX_SEM=1

MASTERDIR=	${.CURDIR}/../../sysutils/bareos24-server

CMAKE_ARGS+=		-Dtraymonitor=yes \
			-Dbuild-dird=no \
			-Dbuild-stored=no \
			-Dclient-only=yes \
			-Dnls=ON \
			-DENABLE_WEBUI=OFF

.include "${MASTERDIR}/Makefile"
