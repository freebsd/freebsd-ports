# Created by: Eric Anholt <anholt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xorg-nestserver
PORTEPOCH=	2

COMMENT=	Nesting X server from X.Org

LICENSE=	MIT

MASTERDIR=	${.CURDIR}/../xorg-server
DESCR=		${.CURDIR}/pkg-descr

RUN_DEPENDS=	xkeyboard-config>=2.5:x11/xkeyboard-config

SLAVE_PORT=	yes
USE_XORG=	x11 xext

CONFIGURE_ARGS+=--enable-xnest --disable-dmx --disable-xephyr --disable-xvfb \
		--disable-xwayland

PLIST_FILES=	bin/Xnest man/man1/Xnest.1.gz

do-install:
	cd ${WRKSRC}/hw/xnest; DESTDIR=${STAGEDIR} ${MAKE} install

.include "${MASTERDIR}/Makefile"
