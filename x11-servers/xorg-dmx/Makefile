# Created by: lesi@FreeBSD.org
# $FreeBSD$

PORTNAME=	xorg-dmx

COMMENT=	Distributed Multihead X from X.Org

LICENSE=	MIT

MASTERDIR=	${.CURDIR}/../xorg-server
DESCR=		${.CURDIR}/pkg-descr

SLAVE_PORT=	yes
USE_XORG=	dmx xorgproto x11 xaw7 xext xfixes xi xmu xpm xrender xres xt xtst

CONFIGURE_ARGS+=--enable-dmx --disable-xephyr --disable-xnest --disable-xvfb \
		--disable-xwayland

do-install:
	cd ${WRKSRC}/hw/dmx; DESTDIR=${STAGEDIR} ${MAKE} install

.include "${MASTERDIR}/Makefile"
