# New ports collection makefile for:	xephyr
# Date created:				2008-05-18
# Whom:					Max Brazhnikov <makc@issp.ac.ru>
#
# $FreeBSD$
#

PORTNAME=	xephyr
PORTREVISION=	0

COMMENT=	A kdrive based X server from X.Org

MASTERDIR=	${.CURDIR}/../xorg-server
DESCR=		${.CURDIR}/pkg-descr
USE_XORG=	x11 xf86driproto glproto randrproto renderproto fixesproto \
		dri2proto damageproto xcmiscproto xtrans inputproto \
		xf86bigfontproto scrnsaverproto bigreqsproto \
		resourceproto fontsproto videoproto \
		compositeproto trapproto recordproto \
		xineramaproto xinerama evieproto xkbfile xfont \
		xau xdmcp xext fontenc xv pixman

CONFIGURE_ARGS=	--enable-kdrive --enable-xephyr	--disable-dmx --disable-xvfb \
		--without-xmlto --disable-docs --disable-devel-docs \
		--disable-xorg --disable-xnest \
		--localstatedir=/var --without-dtrace

SLAVE_PORT=	yes
PLIST_FILES=	bin/Xephyr

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hw/kdrive/ephyr/Xephyr ${PREFIX}/bin/

.include "${MASTERDIR}/Makefile"
