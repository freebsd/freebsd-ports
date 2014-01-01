# Created by: Eric Anholt <anholt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xorg-vfbserver

COMMENT=	X virtual framebuffer server from X.Org

MASTERDIR=	${.CURDIR}/../xorg-server
DESCR=		${.CURDIR}/pkg-descr
USE_XORG=	x11 xf86driproto glproto randrproto renderproto fixesproto \
		damageproto xcmiscproto xextproto xf86miscproto inputproto \
		xf86vidmodeproto xf86bigfontproto scrnsaverproto bigreqsproto \
		dri2proto resourceproto fontsproto xf86dgaproto videoproto \
		compositeproto trapproto recordproto resourceproto \
		xineramaproto xinerama evieproto xkbfile xfont fontenc \
		xkbui xxf86misc xxf86vm xaw7 xmu xpm xext pixman xtrans

CONFIGURE_ARGS=	--disable-dmx --disable-xnest \
		--without-xmlto --disable-docs --disable-devel-docs \
		--localstatedir=/var --without-dtrace

SLAVE_PORT=	yes
PLIST_FILES=	bin/Xvfb man/man1/Xvfb.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hw/vfb/Xvfb ${STAGEDIR}${PREFIX}/bin/
.if defined(WITH_NEW_XORG)
	${INSTALL_MAN} ${WRKSRC}/hw/vfb/man/Xvfb.1 ${STAGEDIR}${PREFIX}/man/man1/
.else
	${INSTALL_MAN} ${WRKSRC}/hw/vfb/Xvfb.1 ${STAGEDIR}${PREFIX}/man/man1/
.endif

.include "${MASTERDIR}/Makefile"
