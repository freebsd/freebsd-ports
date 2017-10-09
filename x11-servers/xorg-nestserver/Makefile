# Created by: Eric Anholt <anholt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xorg-nestserver
PORTVERSION=	1.19.1
PORTREVISION=	1
PORTEPOCH=	2

COMMENT=	Nesting X server from X.Org

LICENSE=	MIT

MASTERDIR=	${.CURDIR}/../xorg-server
DESCR=		${.CURDIR}/pkg-descr
DISTINFO_FILE=	${.CURDIR}/distinfo
PATCHDIR=	${.CURDIR}/files

RUN_DEPENDS=	xkeyboard-config>=2.5:x11/xkeyboard-config

SLAVE_PORT=	yes
OPTIONS_EXCLUDE=DEVD HAL SUID

USE_XORG=	x11 xext xfont2

CONFIGURE_ARGS+=--enable-xnest --disable-dmx --disable-xephyr --disable-xvfb \
		--disable-xwayland

PLIST_FILES=	bin/Xnest man/man1/Xnest.1.gz

EXTRA_PATCHES=	${MASTERDIR}/files/patch-CVE-2017-13721 \
		${MASTERDIR}/files/patch-CVE-2017-13723

do-install:
	cd ${WRKSRC}/hw/xnest; DESTDIR=${STAGEDIR} ${MAKE} install

.include "${MASTERDIR}/Makefile"
