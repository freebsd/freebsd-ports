# $FreeBSD$

PORTNAME=	xwayland
PORTVERSION=	1.19.1

COMMENT=	X Clients under Wayland

LICENSE=	MIT

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/wayland-protocols.pc:graphics/wayland-protocols
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

do-install:
	cd ${WRKSRC}/hw/xwayland; DESTDIR=${STAGEDIR} ${MAKE_CMD} install

.include "${MASTERDIR}/Makefile"
