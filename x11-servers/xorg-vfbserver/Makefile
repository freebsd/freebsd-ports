# Created by: Eric Anholt <anholt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xorg-vfbserver
PORTVERSION=	1.18.0
PORTEPOCH=	1
CATEGORIES=	x11-servers
MASTER_SITES=	XORG/individual/xserver
DISTNAME=	xorg-server-${PORTVERSION}
DIST_SUBDIR=	xorg/xserver

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X virtual framebuffer server from X.Org

USES=		tar:bzip2 pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-dmx \
		--disable-xephyr \
		--disable-xnest \
		--disable-kdrive \
		--disable-xfbdev \
		--disable-xfake \
		--disable-screensaver \
		--disable-xwin \
		--disable-xwayland \
		--disable-xorg \
		--without-xmlto \
		--disable-docs \
		--disable-devel-docs \
		--localstatedir=/var \
		--without-dtrace \
		--without-doxygen \
		--disable-glx \
		--disable-dri  \
		--disable-config-hal \
		--disable-libdrm \
		--disable-glx-tls \
		--disable-vbe \
		--disable-vgahw \
		--enable-xvfb \
		--with-fontrootdir=${PREFIX}/share/fonts

USE_XORG=	pixman x11 fixesproto damageproto xcmiscproto xtrans \
		bigreqsproto randrproto renderproto xextproto inputproto \
		videoproto compositeproto recordproto \
		fontsproto resourceproto xf86driproto glproto \
		presentproto xineramaproto xkbfile xfont

PLIST_FILES=	bin/Xvfb \
		man/man1/Xvfb.1.gz

do-install:
	cd ${WRKSRC}/hw/vfb; DESTDIR=${STAGEDIR} ${MAKE} install

.include <bsd.port.mk>
