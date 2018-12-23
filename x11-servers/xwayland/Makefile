# $FreeBSD$

PORTNAME=	xwayland
PORTVERSION=	1.19.1
# This is inherited from x11-servers/xorg-server
# Ensure it does not go backwards when bumping
PORTREVISION=	11

COMMENT=	X Clients under Wayland

LICENSE=	MIT

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/wayland-protocols.pc:graphics/wayland-protocols \
		${LOCALBASE}/include/linux/input.h:devel/evdev-proto
LIB_DEPENDS=	libwayland-client.so:graphics/wayland \
		libinput.so:x11/libinput

MASTERDIR=	${.CURDIR}/../xorg-server
DESCR=		${.CURDIR}/pkg-descr
DISTINFO_FILE=	${.CURDIR}/distinfo
PATCHDIR=	${.CURDIR}/files

SLAVE_PORT=	yes
OPTIONS_EXCLUDE=DEVD HAL SUID

USE_XORG=	x11 xext xfont2
USE_GL+=	egl gbm

CONFIGURE_ARGS+=	--disable-docs --disable-devel-docs \
			--enable-xwayland --disable-xorg --disable-xvfb --disable-xnest \
			--disable-xquartz --disable-xwin

PLIST_FILES=	bin/Xwayland

EXTRA_PATCHES=	${MASTERDIR}/files/patch-CVE-2017-12176 \
		${MASTERDIR}/files/patch-CVE-2017-12177 \
		${MASTERDIR}/files/patch-CVE-2017-12178 \
		${MASTERDIR}/files/patch-CVE-2017-12179 \
		${MASTERDIR}/files/patch-CVE-2017-12183 \
		${MASTERDIR}/files/patch-CVE-2017-1218x \
		${MASTERDIR}/files/patch-CVE-2017-1218y \
		${MASTERDIR}/files/patch-CVE-2017-13721 \
		${MASTERDIR}/files/patch-CVE-2017-13723 \
		${MASTERDIR}/files/patch-os_io.c

do-install:
	cd ${WRKSRC}/hw/xwayland; DESTDIR=${STAGEDIR} ${MAKE_CMD} install

.include "${MASTERDIR}/Makefile"
