PORTNAME=	networkmanager-shim
DISTVERSION=	1.52.0
PORTREVISION=	1
CATEGORIES=	net-mgmt

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Compatibility shim for a standard network configuration tool suite
WWW=		https://networkmanager.dev

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	xsltproc:textproc/libxslt
LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libndp.so:net/libndp \
		libudev.so:devel/libudev-devd \
		libuuid.so:misc/libuuid

USES=		gnome meson perl5 pkgconfig

USE_GNOME=	glib20

USE_GITLAB=	yes
GL_SITE=	https://gitlab.freedesktop.org
GL_ACCOUNT=	NetworkManager
GL_PROJECT=	NetworkManager

MESON_ARGS=	-Dconcheck=false \
		-Dcrypto=null \
		-Ddbus_conf_dir=disabled \
		-Dintrospection=false \
		-Dlibaudit=no \
		-Dlibpsl=false \
		-Dmodem_manager=false \
		-Dnm_cloud_setup=false \
		-Dnmcli=false \
		-Dnmtui=false \
		-Dovs=false \
		-Dpolkit=false \
		-Dppp=false \
		-Dreadline=none \
		-Dselinux=false \
		-Dsession_tracking=no \
		-Dsystemd_journal=false \
		-Dsystemdsystemunitdir=disabled \
		-Dtests=no

do-build:
	${NINJA_CMD} -C ${BUILD_WRKSRC} src/libnm-client-public/nm-enum-types.c
	${NINJA_CMD} -C ${BUILD_WRKSRC} src/libnm-core-public/nm-core-enum-types.h
	${CC} -shared -fPIC -Wl,-soname,libnm.so.0 -o ${BUILD_WRKSRC}/libnm.so.0 \
		-I${WRKSRC}/src -I${WRKSRC}/src/libnm-core-public -I${WRKSRC}/src/libnm-client-public \
		-I${BUILD_WRKSRC} -I${BUILD_WRKSRC}/src/libnm-core-public/ -I${BUILD_WRKSRC}/src/libnm-client-public/ \
		$$(pkgconf --cflags glib-2.0) \
		-DNDEBUG \
		${BUILD_WRKSRC}/src/libnm-client-public/nm-enum-types.c

do-install:
	${MKDIR} -p ${STAGEDIR}${PREFIX}/include/libnm
	cd ${WRKSRC}/src/libnm-client-public && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include/libnm "-name *\.h"
	cd ${BUILD_WRKSRC}/src/libnm-client-public && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include/libnm "-name *\.h"
	cd ${WRKSRC}/src/libnm-core-public && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include/libnm "-name *\.h"
	cd ${BUILD_WRKSRC}/src/libnm-core-public && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include/libnm "-name *\.h"
	${REINPLACE_CMD} "/#include[[:space:]]*<linux\/.*>/d" ${STAGEDIR}${PREFIX}/include/libnm/*.h
	${INSTALL_LIB} ${BUILD_WRKSRC}/libnm.so.0 ${STAGEDIR}${PREFIX}/lib/
	${RLN} ${STAGEDIR}${PREFIX}/lib/libnm.so.0 ${STAGEDIR}${PREFIX}/lib/libnm.so
	${INSTALL_DATA} ${BUILD_WRKSRC}/meson-private/libnm.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig

.include <bsd.port.mk>
