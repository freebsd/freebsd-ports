# $FreeBSD$

PORTNAME=	bareos
PKGNAMESUFFIX=	-traymonitor

COMMENT=	Backup archiving recovery open sourced (traymonitor)

LIB_DEPENDS+=	libqwt5-qt5.so:x11-toolkits/qwt5-qt5 \
		libbareos.so:sysutils/bareos-client

CONFLICTS=	bacula*-bat-* bareos16-traymonitor-*

USES=		pkgconfig gettext-runtime desktop-file-utils qt:5
USE_QT=		buildtools_build qmake_build uitools_build gui core
WITH_BAT=	yes

PLIST=		${.CURDIR}/pkg-plist
CFLAGS+=	-DMDB_DSYNC=O_SYNC -DMDB_USE_POSIX_SEM=1

MASTERDIR=	${.CURDIR}/../../sysutils/bareos-server

CMAKE_ARGS+=		-Dtraymonitor=yes \
			-Dbuild-dird=no \
			-Dbuild-stored=no \
			-Dclient-only=yes

.include "${MASTERDIR}/Makefile"
