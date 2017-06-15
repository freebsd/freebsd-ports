# Created by: Eric Anholt <anholt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xorg-vfbserver
PORTVERSION=	1.19.1
PORTEPOCH=	1

COMMENT=	X virtual framebuffer server from X.Org

LICENSE=	MIT

MASTERDIR=	${.CURDIR}/../xorg-server
DESCR=		${.CURDIR}/pkg-descr
DISTINFO_FILE=	${.CURDIR}/distinfo
PATCHDIR=	${.CURDIR}/files

SLAVE_PORT=	yes
OPTIONS_EXCLUDE=DEVD HAL SUID

USE_XORG=	xfont2

CONFIGURE_ARGS+=--enable-xvfb --disable-dmx --disable-xephyr --disable-xnest \
		--disable-xwayland

PLIST_FILES=	bin/Xvfb man/man1/Xvfb.1.gz

do-install:
	cd ${WRKSRC}/hw/vfb; DESTDIR=${STAGEDIR} ${MAKE} install

.include "${MASTERDIR}/Makefile"
