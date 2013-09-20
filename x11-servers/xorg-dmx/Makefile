# Created by: lesi@FreeBSD.org
# $FreeBSD$

PORTNAME=	xorg-dmx
PORTREVISION=	0

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
		xau dmx xtst xres pixman xtrans

CONFIGURE_ARGS=	--disable-xvfb --disable-xnest \
		--without-xmlto	--disable-docs --disable-devel-docs \
		--enable-dmx --localstatedir=/var --without-dtrace

MAN1=		Xdmx.1 dmxtodmx.1 vdltodmx.1 xdmxconfig.1

SLAVE_PORT=	yes

NO_STAGE=	yes
do-install:
	cd ${WRKSRC}/hw/dmx; ${MAKE} install

.include "${MASTERDIR}/Makefile"
