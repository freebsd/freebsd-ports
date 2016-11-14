# Created by: alepulver
# $FreeBSD$

PORTNAME=	xrdp
PORTVERSION=	0.6.2
DISTVERSIONPREFIX=	v
PORTEPOCH=	1
CATEGORIES=	net
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	meta+ports@vmeta.jp
COMMENT=	Open source Remote Desktop Protocol (RDP) server

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
USES=		autoreconf:build libtool pkgconfig ssl
USE_LDCONFIG=	${PREFIX}/lib/xrdp
USE_RC_SUBR=	xrdp
USE_XORG=	x11 xfixes

USE_GITHUB=	yes
GH_ACCOUNT=	neutrinolabs

CONFIGURE_ARGS=	--localstatedir=/var
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DEBUG
OPTIONS_DEFAULT=	JP106 X11RDP
OPTIONS_GROUP=	KEYMAP XSERVER
OPTIONS_GROUP_KEYMAP=	JP106
OPTIONS_GROUP_XSERVER=	X11RDP
OPTIONS_RADIO=	XVNC
OPTIONS_RADIO_XVNC=	TIGERVNC TIGHTVNC TRIDIAVNC
TIGERVNC_DESC=	Use TigerVNC (recommended)
TIGHTVNC_DESC=	Use TightVNC
TRIDIAVNC_DESC=	Use TridiaVNC
X11RDP_DESC=	Use X11rdp (most recommended)
JP106_DESC=	Install Japanese JP106 keymap

# Debug
DEBUG_CONFIGURE_ENABLE=	xrdpdebug
# Xvnc
TIGERVNC_RUN_DEPENDS=	Xvnc:net/tigervnc
TIGHTVNC_RUN_DEPENDS=	Xvnc:net/tightvnc
TRIDIAVNC_RUN_DEPENDS=	Xvnc:net/tridiavnc
# X11rdp
X11RDP_RUN_DEPENDS=	X11rdp:x11-servers/x11rdp
X11RDP_EXTRA_PATCHES=	${FILESDIR}/extra-patch-x11rdp_xrdp.ini
# JP106 keymap
JP106_PLIST_SUB=	JP106=""
JP106_PLIST_SUB_OFF=	JP106="@comment "

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MJP106}
KEYMAP_FILES+=	km-0411.ini km-e0010411.ini \
		km-e0200411.ini km-e0210411.ini
.endif

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
