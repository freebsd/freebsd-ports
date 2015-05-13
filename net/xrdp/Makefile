# Created by: alepulver
# $FreeBSD$

PORTNAME=	xrdp
PORTVERSION=	0.6.1
PORTREVISION=	6
PORTEPOCH=	1
CATEGORIES=	net

MAINTAINER=	meta+ports@vmeta.jp
COMMENT=	Open source Remote Desktop Protocol (RDP) server

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
USES=		autoreconf:build libtool pkgconfig
USE_LDCONFIG=	${PREFIX}/lib/xrdp
USE_OPENSSL=	yes
USE_RC_SUBR=	xrdp
USE_XORG=	x11 xfixes

USE_GITHUB=	yes
GH_ACCOUNT=	neutrinolabs
GH_TAGNAME=	5d53758

CONFIGURE_ARGS=	--localstatedir=/var
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

OPTIONS_DEFINE=	DEBUG
OPTIONS_DEFAULT=	JP106 X11RDP
OPTIONS_GROUP=	KEYMAP XSERVER
OPTIONS_GROUP_KEYMAP= JP106
OPTIONS_GROUP_XSERVER= X11RDP
OPTIONS_RADIO=	XVNC
OPTIONS_RADIO_XVNC=	REALVNC TIGERVNC TIGHTVNC TRIDIAVNC
REALVNC_DESC=	Use RealVNC
TIGERVNC_DESC=	Use TigerVNC (recommended)
TIGHTVNC_DESC=	Use TightVNC
TRIDIAVNC_DESC=	Use TridiaVNC
X11RDP_DESC=	Use X11rdp (most recommended)
JP106_DESC=	Install Japanese JP106 keymap

.include <bsd.port.options.mk>

# Which Xserver to use
.if ${PORT_OPTIONS:MREALVNC}
RUN_DEPENDS=	Xvnc:${PORTSDIR}/net/vnc
.endif
.if ${PORT_OPTIONS:MTIGERVNC}
RUN_DEPENDS=	Xvnc:${PORTSDIR}/net/tigervnc
.endif
.if ${PORT_OPTIONS:MTIGHTVNC}
RUN_DEPENDS=	Xvnc:${PORTSDIR}/net/tightvnc
.endif
.if ${PORT_OPTIONS:MTRIDIAVNC}
RUN_DEPENDS=	Xvnc:${PORTSDIR}/net/tridiavnc
.endif
# X11rdp
.if ${PORT_OPTIONS:MX11RDP} || exists(${LOCALBASE}/bin/X11rdp)
RUN_DEPENDS+=	X11rdp:${PORTSDIR}/x11-servers/x11rdp
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-x11rdp_xrdp.ini
.endif

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=	--enable-xrdpdebug
CFLAGS+=	-DXRDP_DEBUG
.endif

.if ${PORT_OPTIONS:MJP106}
KEYMAP_FILES+=	km-0411.ini km-e0010411.ini \
		km-e0200411.ini km-e0210411.ini
PLIST_SUB+=	JP106=""
.else
PLIST_SUB+=	JP106="@comment "
.endif

SUB_FILES=	pkg-message

post-patch:
.for f in sesman/sesman.ini sesman/startwm.sh xrdp/rsakeys.ini xrdp/xrdp.ini
	@${MV} ${WRKSRC}/$f ${WRKSRC}/$f.sample
.endfor

pre-configure:
	@cd ${WRKSRC} && ./bootstrap

post-install:
.for f in ${KEYMAP_FILES}
	${INSTALL_DATA} ${FILESDIR}/$f ${STAGEDIR}${PREFIX}/etc/xrdp
.endfor

.include <bsd.port.mk>
