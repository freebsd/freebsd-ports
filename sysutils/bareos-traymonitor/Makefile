PORTREVISION=	1

COMMENT=	Backup archiving recovery open sourced (traymonitor)

LIB_DEPENDS+=	libbareos.so:sysutils/bareos-client

CONFLICTS=	bareos20-traymonitor bareos21-traymonitor bareos22-traymonitor \
		bareos23-traymonitor

USES=		desktop-file-utils gettext-runtime pkgconfig

FLAVORS=	qt5 qt6
FLAVOR?=	${FLAVORS:[1]}

qt5_CONFLICTS=		bareos23-traymonitor-qt6
qt6_CONFLICTS=		bareos23-traymonitor-qt5

.if ${FLAVOR} == qt6
PKGNAMESUFFIX=	-traymonitor-qt6

USES+=		qt:6
USE_QT=		base:run declarative:build tools:build
CMAKE_ARGS+=	-Dbat-qt6=yes
.else
PKGNAMESUFFIX=	-traymonitor-qt5

LIB_DEPENDS+=	libqwt5-qt5.so:x11-toolkits/qwt5-qt5
USES+=		qt:5
USE_QT=		buildtools:build qmake:build uitools:build gui core widgets
.endif

WITH_BAT=	yes

PLIST=		${.CURDIR}/pkg-plist
CFLAGS+=	-DMDB_DSYNC=O_SYNC -DMDB_USE_POSIX_SEM=1

MASTERDIR=	${.CURDIR}/../../sysutils/bareos-server

CMAKE_ARGS+=		-Dtraymonitor=yes \
			-Dbuild-dird=no \
			-Dbuild-stored=no \
			-Dclient-only=yes \
			-Dnls=ON \
			-DENABLE_WEBUI=OFF

.include "${MASTERDIR}/Makefile"
