# Created by: Stas Timokhin <stast@bsdportal.ru>
# $FreeBSD$

PORTNAME=	eiskaltdcpp
CATEGORIES=	net-p2p
PKGNAMESUFFIX=	-data
PORTREVISION=	4

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Shared data for EiskaltDC++ GUIs

LICENSE=	GPLv3

MASTERDIR=	${.CURDIR}/../eiskaltdcpp-lib

USES=		cmake shebangfix
SHEBANG_FILES=	data/examples/commands.ru_RU.UTF-8.php \
		data/examples/deadbeef.ru_RU.UTF-8.sh \
		data/examples/mod.amarok.sh \
		data/examples/mpris_now_playing.en_US.sh \
		data/examples/xmms2_audacious2.ru_RU.UTF-8.php \
		data/update_geoip
php_OLD_CMD=	/usr/bin/php5
NO_ARCH=	yes
NO_BUILD=	yes
INSTALLS_ICONS=	yes

CMAKE_SOURCE_PATH=	${WRKSRC}/data

OPTIONS_DEFINE=	EMOTICONS EXAMPLES LUASCRIPTS SOUNDS
OPTIONS_DEFAULT=	EMOTICONS SOUNDS
OPTIONS_SUB=	yes
EMOTICONS_DESC=		Install emoticons
EXAMPLES_DESC=		Install script examples
LUASCRIPTS_DESC=	Install lua script examples
SOUNDS_DESC=		Install sound files

CMAKE_ARGS=		-Wno-dev \
			-DUSE_GTK:BOOL=ON \
			-DCLIENT_DATA_DIR=${DATADIR} \
			-DSHARE_DIR=${LOCALBASE}/share

EMOTICONS_CMAKE_ON=	-DWITH_EMOTICONS:BOOL=ON
EMOTICONS_CMAKE_OFF=	-DWITH_EMOTICONS:BOOL=OFF
EXAMPLES_CMAKE_ON=	-DWITH_EXAMPLES:BOOL=ON
EXAMPLES_CMAKE_OFF=	-DWITH_EXAMPLES:BOOL=OFF
LUASCRIPTS_CMAKE_ON=	-DWITH_LUASCRIPTS:BOOL=ON -DLUA_SCRIPT:BOOL=ON
LUASCRIPTS_CMAKE_OFF=	-DWITH_LUASCRIPTS:BOOL=OFF
SOUNDS_CMAKE_ON=	-DWITH_SOUNDS:BOOL=ON
SOUNDS_CMAKE_OFF=	-DWITH_SOUNDS:BOOL=OFF

.include "${MASTERDIR}/Makefile"
