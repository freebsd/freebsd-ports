# Created by: lesi@FreeBSD.org
# $FreeBSD$

PORTNAME=	xorg-dmx

COMMENT=	Distributed Multihead X from X.Org

MASTERDIR=	${.CURDIR}/../xorg-server
DESCR=		${.CURDIR}/pkg-descr
USE_XORG=	x11 xf86driproto glproto randrproto renderproto fixesproto \
		dri2proto damageproto xcmiscproto xextproto xf86miscproto \
		xf86vidmodeproto xf86bigfontproto scrnsaverproto bigreqsproto \
		resourceproto fontsproto xf86dgaproto videoproto \
		compositeproto trapproto recordproto resourceproto \
		xineramaproto xinerama evieproto xkbfile xfont fontenc xkbui \
		xxf86misc xxf86vm xaw7 xmu xpm xext xrender xfixes xi dmxproto \
		xau dmx xtst xres pixman xtrans presentproto

CONFIGURE_ARGS=	--disable-xvfb --disable-xnest \
		--without-xmlto	--disable-docs --disable-devel-docs \
		--enable-dmx --localstatedir=/var --without-dtrace

SLAVE_PORT=	yes

do-install:
	cd ${WRKSRC}/hw/dmx; DESTDIR=${STAGEDIR} ${MAKE} install

.include "${MASTERDIR}/Makefile"
